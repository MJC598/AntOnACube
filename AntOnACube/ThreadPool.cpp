#include "ThreadPool.h"

void ThreadPool::Start() {
	const uint32_t numThreads = std::thread::hardware_concurrency();
	threads.resize(numThreads);
	for (uint32_t i = 0; i < numThreads; i++) {
		threads.at(i) = std::thread(&ThreadPool::ThreadLoop, this);
	}
}

void ThreadPool::ThreadLoop() {
	while (true) {
		std::function<void()>job;
		{
			std::unique_lock<std::mutex> lock(queue_mutex);
			mutex_condition.wait(lock, [this] {
				return !jobs.empty() || should_terminate;
				});
			if (should_terminate) {
				return;
			}
			job = jobs.front();
			jobs.pop();
		}
		job();
	}
}

void ThreadPool::QueueJob(const std::function<void()>& job) {
	{
		std::unique_lock<std::mutex> lock(queue_mutex);
		jobs.push(job);
	}
	mutex_condition.notify_one();
}

bool ThreadPool::Busy() {
	bool poolBusy;
	{
		std::unique_lock<std::mutex> lock(queue_mutex);
		poolBusy = jobs.empty();
	}
	return poolBusy;
}

void ThreadPool::Stop() {
	{
		std::unique_lock<std::mutex> lock(queue_mutex);
		should_terminate = true;
	}
	mutex_condition.notify_all();
	for (std::thread& active_thread : threads) {
		active_thread.join();
	}
	threads.clear();
}