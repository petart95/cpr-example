#ifndef BITTREX_IMPL_H
#define BITTREX_IMPL_H

#include "exchange/Bittrex.hpp"
#include "impl/exchange/HttpExchangeImpl.hpp"

#define PIMPLE_CLASS Bittrex

class PIMPLE_IMPL {
public:
	Impl(std::string market);

	static std::string getOrderbookUrl(std::string market);

	Orderbook& getOrderbook(PIMPLE_CLASS* bp);
	double fee();

private:
    Orderbook orderbook;

    static std::string getUrl();
    std::vector<Order> getOrders(std::string type);
};

#endif  // BITTREX_IMPL_H
