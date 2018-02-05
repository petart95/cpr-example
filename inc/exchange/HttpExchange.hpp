/**
 * \file   HttpExchange.hpp
 * \author ptrifunovic
 *
 * \brief Declares the HttpExchange class.
 *
 * The HttpExchange class is used for represnting
 * an exchange betwing two resources.
 *
 * The HttpExchange class updated the Orderbook
 * using HTTP requests.
 *
 * \see Exchange.hpp
 */

#ifndef HTTP_EXCHANGE_H
#define HTTP_EXCHANGE_H

#include <json.hpp>

#include "pimpl.h"

#include "exchange/Exchange.hpp"

/**
 * \brief The HttpExchange class represents an exchange.
 *
 * The HttpExchange class is an abstract class 
 * that implements part of the Exchange class
 * by updating the Orderbook using HTTP requests.
 *
 * The HttpExchange class constantly pools getOrderbookUrl()
 * and updates the jsonOrderbook which should be used
 * to render Orderbook by the subclasses.
 *
 * Every class that extends this class should implement:
 *     - Orderbook getOrderbook()
 *     - Orderbook getOrderbookUrl()
 *     - double fee()
 *
 * \see Exchange
 */
class HttpExchange : public Exchange, pimpl<HttpExchange> {
public:
	/**
	 * \brief Returns jsonOrderbook.
	 *
	 * The jsonOrderbook represents the latest pool response
	 * from the orderbook update url HTTP request.
	 *
	 * \return The jsonOrderbook.
	 */
	nlohmann::json& getJsonOrderbook();

	/**
	 * \brief Prints the order that is bought.
	 *
	 * TODO: Implement real buy
	 *
	 * \see Exchange::buy(Order &order)
	 */
	void buy(Order &order) override;

	/**
	 * \brief Prints the order that is solde.
	 *
	 * TODO: Implement real sell
	 *
	 * \see Exchange::sell(Order &order)
	 */
	void sell(Order &order) override;

protected:
	/**
	 * \brief Constructs HttpExchange by pulling on specified url.
	 *
	 * \param url The url from which to pull the orderbook.
	 */
	HttpExchange(std::string url);

};

#endif  // HTTP_EXCHANGE_H
