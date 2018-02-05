#include "impl/strategy/BlockingStrategyImpl.hpp"

BlockingStrategy::BlockingStrategy()
	: pImpl(
		new Impl(this),
		[] (Impl *impl) {
			delete impl; 
		}
	) 
{
}

void BlockingStrategy::notify() {
	pImpl->notify();
}