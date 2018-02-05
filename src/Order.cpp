#include "Order.hpp"

std::ostream& operator << (std::ostream& os, const Order& rhs) {
	return os << "{\"price\": " << rhs.price << ", \"quantity\": " << rhs.quantity << "}";
}