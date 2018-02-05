#include "impl/exchange/PoloniexImpl.hpp"

Poloniex::Impl::Impl(std::string market) 
	: HttpExchange::Impl(getOrderbookUrl(market))
{
	std::cout << "TEST" << std::endl << std::flush;
}

std::string Poloniex::Impl::getUrl()
{
	return "https://poloniex.com/";
}

std::string Poloniex::Impl::getOrderbookUrl(std::string market)
{
	return getUrl() + "public?command=returnOrderBook&currencyPair=" 
		+ market;
}

std::vector<Order> Poloniex::Impl::getOrders(std::string type)
{
    std::vector<Order> orders;
    for (auto& order : getJsonOrderbook()[type]) {
        double price = std::stod(order[0].dump().substr(1, order[0].dump().size() - 2));
        orders.push_back({ price, order[1] });
    }
    return orders;
}

Orderbook& Poloniex::Impl::getOrderbook()
{
	orderbook.sells = getOrders("sell");
	orderbook.buys = getOrders("buy");
	return orderbook;
}

double Poloniex::Impl::fee()
{
	return 0.25 / 100;
}