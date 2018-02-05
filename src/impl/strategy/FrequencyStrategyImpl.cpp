#include "impl/strategy/FrequencyStrategyImpl.hpp"

void FrequencyStrategy::Impl::strategy()
{
	auto end = std::chrono::steady_clock::now();
	auto elapsed =
		std::chrono::duration_cast<std::chrono::seconds>(end - start);
	std::cout << elapsed.count() << '\n';
	start = std::chrono::steady_clock::now();
}

void FrequencyStrategy::Impl::init()
{
	std::cout << "STARTIING 2" << std::endl;
	start = std::chrono::steady_clock::now();
}
