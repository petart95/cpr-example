#ifndef BLOCKING_STRATEGY_IMPL_H
#define BLOCKING_STRATEGY_IMPL_H

#include "strategy/BlockingStrategy.hpp"

class BlockingStrategy::Impl {
public:
	Impl(BlockingStrategy *pApi);

	void notify();

private:
	BlockingStrategy *pApi;
};

#endif  // BLOCKING_STRATEGY_IMPL_H
