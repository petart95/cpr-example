#include "impl/exchange/BittrexImpl.hpp"

Bittrex::Impl::Impl(std::string market)
	: HttpExchange::Impl(getOrderbookUrl(market))
{
}

std::string Bittrex::Impl::getUrl()
{
	return "https://bittrex.com/api/v1.1/";
}

std::string Bittrex::Impl::getOrderbookUrl(std::string market)
{
	return getUrl() + "public/getorderbook?market=" +
		market +"&type=both";
}

std::vector<Order> Bittrex::Impl::getOrders(std::string type)
{
    std::vector<Order> orders;
    for (auto &order : getJsonOrderbook()["result"][type]) {
        orders.push_back({ order["Rate"], order["Quantity"] });
    }
    return orders;
}

Orderbook& Bittrex::Impl::getOrderbook()
{
	orderbook.sells = getOrders("sell");
	orderbook.buys = getOrders("buy");
	return orderbook;
}

double Bittrex::Impl::fee()
{
	return 0.25 / 100;
}