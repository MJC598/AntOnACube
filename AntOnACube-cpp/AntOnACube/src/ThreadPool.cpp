#include "ThreadPool.h"

/// <summary>
/// Function to start Thread Pool
/// </summary>
void ThreadPool::start() {
	const uint32_t numThreads = std::thread::hardware_concurrency();
	threads.resize(numThreads);
	for (uint32_t i = 0; i < numThreads; i++) {
		threads.at(i) = std::thread(&ThreadPool::threadLoop, this);
	}
}

/// <summary>
/// Function to continuously loop looking for jobs to assign to a thread
/// </summary>
void ThreadPool::threadLoop() {
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

/// <summary>
/// Entry point for a job to be queued to a thread in the pool
/// </summary>
/// <param name="job"></param>
void ThreadPool::queueJob(const std::function<void()>& job) {
	{
		std::unique_lock<std::mutex> lock(queue_mutex);
		jobs.push(job);
	}
	mutex_condition.notify_one();
}

/// <summary>
/// Helper function to determine if the pool is busy
/// </summary>
/// <returns></returns>
bool ThreadPool::busy() {
	bool poolBusy;
	{
		std::unique_lock<std::mutex> lock(queue_mutex);
		poolBusy = jobs.empty();
	}
	return poolBusy;
}

/// <summary>
/// Helper Function to join all threads and end all tasks
/// </summary>
void ThreadPool::stop() {
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