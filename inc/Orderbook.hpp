#ifndef ORDERBOOK_H
#define ORDERBOOK_H

#include <vector>

#include "Order.hpp"

struct 	Orderbook {
	std::vector<Order> buys;
	std::vector<Order> sells;
};

#endif  // ORDERBOOK_H
