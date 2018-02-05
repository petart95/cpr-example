#include "impl/exchange/PoloniexImpl.hpp"

Poloniex::Poloniex(std::string first, std::string second)
    : HttpExchange((
    	pImpl = {
    		new Impl(first + "_" + second), 
    		[] (Impl *impl) { delete impl; }
    	},
    	pImpl.get()
    )),
    pImpl(std::move(pImpl))
{
}

Orderbook& Poloniex::getOrderbook()
{
    return pImpl->getOrderbook();
}

double Poloniex::fee()
{
    return pImpl->fee();
}
