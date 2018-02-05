#include "impl/strategy/BlockingStrategyImpl.hpp"

BlockingStrategy::Impl::Impl(BlockingStrategy *pApi)
	: pApi(pApi)
{
}

void BlockingStrategy::Impl::notify()
{
	pApi->strategy();
}
