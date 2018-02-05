/**
 * \file   HttpExchange.hpp
 * \author ptrifunovic
 *
 * \brief Declares the Poloniex class.
 *
 * The Poloniex class is used for represnting
 * the Poloniex exchange.
 *
 * \see HttpExchange.hpp
 */

#ifndef POLONIEX_H
#define POLONIEX_H

#include "exchange/HttpExchange.hpp"

/**
 * \brief The Poloniex class represents the Poloniex exchange.
 *
 * \see HttpExchange
 */
class Poloniex : public HttpExchange {
public:
	/**
	 * \brief Counstracts the Bittrex class for specified market.
	 *
	 * \param first The name of the first market resource.
	 * \param second The name of the second market resource.
	 */
	Poloniex(std::string first, std::string second);

	/**
	 * \see Exchange::getOrderbook()
	 */
	Orderbook& getOrderbook() override;

	/**
	 * \see Exchange::fee()
	 */
	double fee() override;

private:
	/**
	 * \brief PIMPL idiom
	 */
	class Impl;

    std::unique_ptr<Impl, void (*)(Impl *)> pImpl;

};

#endif  // POLONIEX_H
