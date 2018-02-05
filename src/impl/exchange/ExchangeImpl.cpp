#include <iterator>

#include "impl/exchange/ExchangeImpl.hpp"

void PIMPL_IMPL::registerStrategies(std::vector<std::function<void()>> strategies)
{
	std::lock_guard<std::mutex> lock(mutex);
	this->strategies.insert(
		this->strategies.end(), strategies.begin(), strategies.end());
}

void PIMPL_IMPL::registerStrategy(std::function<void()> strategy)
{
	registerStrategies({strategy});
}

void PIMPL_IMPL::runRegisterStrategies()
{
	std::lock_guard<std::mutex> lock(mutex);
	for (auto strategy : strategies) {
		strategy();
	}
}
