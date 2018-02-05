#include "impl/exchange/BittrexImpl.hpp"

Bittrex::Bittrex(std::string first, std::string second)
    : HttpExchange((
    	this->pImpl = {
    		new Impl(first + "-" + second), 
    		[] (Impl *impl) { delete impl; }
    	},
    	this->pImpl.get()
    )),
    pImpl(std::move(this->pImpl))
{
}

Orderbook& Bittrex::getOrderbook()
{
    return pImpl->getOrderbook();
}

double Bittrex::fee()
{
    return pImpl->fee();
}
