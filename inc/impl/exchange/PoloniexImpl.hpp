#ifndef POLONIEX_IMPL_H
#define POLONIEX_IMPL_H

#include "exchange/Poloniex.hpp"
#include "impl/exchange/HttpExchangeImpl.hpp"

class Poloniex::Impl : public HttpExchange::Impl {
public:
	Impl(std::string market);

	static std::string getOrderbookUrl(std::string market);

	Orderbook& getOrderbook();
	double fee();

private:
    Orderbook orderbook;

    static std::string getUrl();
    std::vector<Order> getOrders(std::string type);
};

#endif  // POLONIEX_IMPL_H
