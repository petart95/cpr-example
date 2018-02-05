/**
 * \file   Strategy.hpp
 * \author ptrifunovic
 *
 * \brief Declares the Strategy class.
 *
 * The Strategy class is used for represnting
 * a strategy that shoud be executed when notified.
 */

#ifndef STRATEGY_H
#define STRATEGY_H

/**
 * \brief The Strategy class represents a strategy.
 *
 * The Strategy class is an abstract class.
 *
 * Every class that extends Strategy class should implement:
 *     - void notify()
 */
class Strategy {
public:
	/**
	 * \brief Notifies that the strategy should be executed.
	 */
	virtual void notify() = 0;
};

#endif  // STRATEGY_H
