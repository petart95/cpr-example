#ifndef ORDER_H
#define ORDER_H

#include <iostream>

struct Order {
	double price;
	double quantity;

	friend std::ostream& operator << (std::ostream& os, const Order& rhs);
};

#endif  // ORDER_H