#include "impl/strategy/FrequencyStrategyImpl.hpp"

FrequencyStrategy::FrequencyStrategy(std::vector<Exchange*> exchanges)
	: pImpl(
		new Impl(),
		[] (Impl *impl) { delete impl; }
	) ,
	NonblockingStrategy (
		exchanges, 
		[=] { pImpl->strategy(); },
		[=] { pImpl->init(); }
	)
{
}
