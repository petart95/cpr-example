#include "impl/strategy/NonblockingStrategyImpl.hpp"

NonblockingStrategy::Impl::Impl(
	std::function<void()> strategy,
	std::function<void()> init)
	: thread(
		[=] {
			mutex.lock();
			strategy();
		},
		[=] {
			init();
		}
	)
{
}

void NonblockingStrategy::Impl::notify()
{
	mutex.unlock();
}
