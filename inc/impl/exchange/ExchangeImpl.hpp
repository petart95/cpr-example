#ifndef EXCHANGE_IMPL_H
#define EXCHANGE_IMPL_H

#include <mutex>

#include "exchange/Exchange.hpp"

#define PIMPLE_CLASS Exchange

class PIMPL_IMPL {
public:
	void registerStrategy(std::function<void()> strategy);
	void registerStrategies(std::vector<std::function<void()>> strategies);
	void runRegisterStrategies();

private:
	std::vector<std::function<void()>> strategies;
	std::mutex mutex;

};

#endif  // EXCHANGE_IMPL_H