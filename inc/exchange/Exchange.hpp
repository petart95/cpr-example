/**
 * \file   Exchange.hpp
 * \author ptrifunovic
 *
 * \brief Declares the Exchange class.
 *
 * The Exchange class is used for represnting
 * an exchange betwing two resources.
 */

#ifndef EXCHANGE_H
#define EXCHANGE_H

#include <vector>
#include <functional>

#include "pimpl.h"

#include "Orderbook.hpp"
#include "strategy/Strategy.hpp"

/**
 * \brief The Exchange class represents an exchange.
 *
 * The Exchange class is an abstract class.
 *
 * Every class that extends Exchange class should implement:
 *     - Orderbook& getOrderbook()
 *     - void buy(Order &order
 *     - void sell(Order &order)
 *     - double fee()
 */
class Exchange : pimpl(Exchange) {
public:
	/**
	 * \brief Returns the Orderbook of the exchange.
	 *
	 * \return The Orderbook of the exchange.
	 *
	 * \see Orderbook
	 */
	virtual Orderbook& getOrderbook() = 0;

	/**
	 * \brief Buys the specified Order.
	 *
	 * \param order The Order that should be bought.
	 *
	 * \see Order
	 */
	virtual void buy(Order &order) = 0;

	/**
	 * \brief Sells the specified Order.
	 *
	 * \param order The Order that should be sold.
	 *
	 * \see Order
	 */
	virtual void sell(Order &order) = 0;

	/**
	 * \breif Returns rhe fee for buying/selling an order.
	 *
	 * \return The fee for buying/selling an order.
	 */
	virtual double fee() = 0;

	/**
	 * \brief Registers a strategy.
	 *
	 * \param strategy The strategy that should be registered.
	 */
	void registerStrategy(std::function<void()> strategy);

	/**
	 * \brief Registers a list strategies.
	 *
	 * \param strategy The list of strategies that should be registered.
	 */
	void registerStrategies(std::vector<std::function<void()>> strategies);

	/**
	 * \brief Runs all registered strategies
	 *
	 * Note: This function should be caled
	 *       every time Orderbook is updated.
	 */
	void runRegisterStrategies();
    
};

#endif  // EXCHANGE_H
