#ifndef JOB_IMPL_H
#define JOB_IMPL_H

#include <iostream>
#include <thread>

#include "Job.hpp"

class Job::Impl {
public:
	Impl(std::function<void()> job, std::function<void()> init);
	~Impl();

	void stop();

private:
	bool is_alive;
	std::thread thread;

	std::function<void()> job, init;
};

#endif  // JOB_IMPL_H