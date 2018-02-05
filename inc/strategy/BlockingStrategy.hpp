/**
 * \file   BlockingStrategy.hpp
 * \author ptrifunovic
 *
 * \brief Declares the BlockingStrategy class.
 *
 * The BlockingStrategy class is used for represnting
 * a strategy that shoud be executed when notified
 * and blocks the current thred until it finishes.
 *
 * \see Strategy.hpp
 */

#ifndef BLOCKING_STRATEGY_H
#define BLOCKING_STRATEGY_H

#include <memory>

#include "strategy/Strategy.hpp"

/**
 * \brief The BlockingStrategy class represents a blocking strategy.
 *
 * The BlockingStrategy class is an abstract class.
 *
 * Every class that extends BlockingStrategy class should implement:
 *     - void void strategy()
 */
class BlockingStrategy : public Strategy {
public:
	/**
	 * \brief The strategy.
	 *
	 * This function is called afther notify.
	 */
	virtual void strategy() = 0;

	/**
	 * \see Strategy::notify()
	 */
	void notify() override;

protected:
	/**
	 * \brief Default constructor.
	 */
	BlockingStrategy();

private:
	// PIMPL idiom
	class Impl;
    std::unique_ptr<Impl, void (*)(Impl *)> pImpl;
};

#endif  // BLOCKING_STRATEGY_H
