/**
 * \file   HttpExchange.hpp
 * \author ptrifunovic
 *
 * \brief Declares the Bittrex class.
 *
 * The Bittrex class is used for represnting
 * the Bittrex exchange.
 *
 * \see HttpExchange.hpp
 */

#ifndef BITTREX_H
#define BITTREX_H

#include "pimpl.hpp"

#include "exchange/HttpExchange.hpp"

/**
 * \brief The Bittrex class represents the Bittrex exchange.
 *
 * \see HttpExchange
 */
class Bittrex : pimpl<Bittrex>, public HttpExchange{
public:
	/**
	 * \brief Counstracts the Bittrex class for specified market.
	 *
	 * \param first The name of the first market resource.
	 * \param second The name of the second market resource.
	 */
	Bittrex(std::string first, std::string second);

	/**
	 * \see Exchange::getOrderbook()
	 */
	Orderbook& getOrderbook() override;

	/**
	 * \see Exchange::fee()
	 */
	double fee() override;

};

#endif  // BITTREX_H
