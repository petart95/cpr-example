/**
 * \file   FrequencyStrategy.hpp
 * \author ptrifunovic
 *
 * \brief Declares the FrequencyStrategy class.
 *
 * The FrequencyStrategy class is used for
 * calcualtes frequency of notifications.
 *
 * \see NonblockingStrategy.hpp
 */

#ifndef FREQUENCY_STRATEGY_H
#define FREQUENCY_STRATEGY_H

#include <vector>

#include "exchange/Exchange.hpp"
#include "strategy/NonblockingStrategy.hpp"

/**
 * \brief The FrequencyStrategy class calcualtes frequency of notifications.
 */
class FrequencyStrategy : public NonblockingStrategy {
public:
	/**
	 * \brief Constructs FrequencyStrategy class using exchanges.
	 *
	 * \param exchanges Excanges that should be monitored.
	 */
	FrequencyStrategy(std::vector<Exchange*> exchanges);

private:
	/**
	 * \brief PIMPL idiom
	 */
	class Impl; 

    std::unique_ptr<Impl, void (*)(Impl *)> pImpl;

};

#endif  // FREQUENCY_STRATEGY_H
