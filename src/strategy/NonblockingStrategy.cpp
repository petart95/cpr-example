#include "impl/strategy/NonblockingStrategyImpl.hpp"

NonblockingStrategy::NonblockingStrategy(
	std::vector<Exchange*> exchanges,
	std::function<void()> strategy,
	std::function<void()> init)
	: pImpl(
		new Impl(strategy, init),
		[] (Impl *impl) { delete impl; }
	) 
{
	for (auto &exchange: exchanges) {
		exchange->registerStrategy([this] { this->notify(); });
	}
}

NonblockingStrategy::NonblockingStrategy(
	std::function<void()> strategy,
	std::function<void()> init)
	: NonblockingStrategy({}, strategy, init)
{
}

void NonblockingStrategy::notify() {
	pImpl->notify();
}