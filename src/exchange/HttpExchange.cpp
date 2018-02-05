#include "impl/exchange/HttpExchangeImpl.hpp"

HttpExchange::HttpExchange(std::string url) 
	: pimpl<HttpExchange>(url) {}

PIMPLE_F(nlohmann::json&, getJsonOrderbook, (), ())

void HttpExchange::buy(Order &order)
{
    std::cout << "BUYING: " << order;
}

void HttpExchange::sell(Order &order)
{
    std::cout << "SELLING: " << order;
}
