#pragma once
#include <functional>
#include <condition_variable>
#include <queue>
#include <thread>

class ThreadPool {
public:
	void start();
	void queueJob(const std::function<void()>& job);
	void stop();
	bool busy();

private:
	void threadLoop();
	bool should_terminate = false;
	std::mutex queue_mutex;
	std::condition_variable mutex_condition;
	std::vector<std::thread> threads;
	std::queue<std::function<void()>> jobs;
};