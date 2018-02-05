#ifndef FREQUENCY_STRATEGY_IMPL_H
#define FREQUENCY_STRATEGY_IMPL_H

#include <chrono>

#include "strategy/FrequencyStrategy.hpp"

class FrequencyStrategy::Impl {
public:
	void strategy();
	void init();

private:
	std::chrono::time_point<std::chrono::steady_clock> start;
};

#endif  // FREQUENCY_STRATEGY_IMPL_H
