/**
 * \file   NonblockingStrategy.hpp
 * \author ptrifunovic
 *
 * \brief Declares the NonblockingStrategy class.
 *
 * The NonblockingStrategy class is used for represnting
 * a strategy that shoud be executed when notified
 * and does not blocs the current thread.
 *
 * \see Strategy.hpp
 */

#ifndef NONBLOCKING_STRATEGY_H
#define NONBLOCKING_STRATEGY_H

#include <memory>

#include "exchange/Exchange.hpp"
#include "strategy/Strategy.hpp"

/**
 * \brief The NonblockingStrategy class represents a nonblocking strategy.
 *
 * The NonblockingStrategy class is an abstract class.
 *
 * Every class that extends NonblockingStrategy class should implement:
 *     - void void strategy()
 *     - void void init()
 */
class NonblockingStrategy : public Strategy {
public:

	/**
	 * \brief Constructs a NonblockingStrategy.
	 *
	 * \brief exchanges List of exchanges that triger the stratagey.
	 * \brief strategy The stratagey.
	 * \brief init The initialization for the strategy.
	 */
	NonblockingStrategy(
		std::vector<Exchange*> exchanges,
		std::function<void()> strategy,
		std::function<void()> init = [] {}); 

	/**
	 * \brief Constructs a NonblockingStrategy.
	 *
	 * \brief strategy The stratagey.
	 * \brief init The initialization for the strategy.
	 */
	NonblockingStrategy(
		std::function<void()> strategy,
		std::function<void()> init = [] {}); 

	/**
	 * \see Strategy::notify()
	 */
	void notify() override;

private:
	/**
	 * \brief PIMPL idiom
	 */
	class Impl; 

    std::unique_ptr<Impl, void (*)(Impl *)> pImpl;

};

#endif  // NONBLOCKING_STRATEGY_H
