#ifndef NONBLOCKING_STRATEGY_IMPL_H
#define NONBLOCKING_STRATEGY_IMPL_H

#include <condition_variable>
#include <mutex>

#include "Job.hpp"
#include "strategy/NonblockingStrategy.hpp"

class NonblockingStrategy::Impl {
public:
	Impl(
		std::function<void()> strategy,
		std::function<void()> init);

	void notify();

private:
	Job thread;
	std::mutex mutex;
	std::condition_variable notified;
};

#endif  // NONBLOCKING_STRATEGY_IMPL_H
