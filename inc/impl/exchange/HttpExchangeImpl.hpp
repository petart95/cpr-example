#ifndef HTTP_EXCHANGE_IMPL_H
#define HTTP_EXCHANGE_IMPL_H

#include <condition_variable>
#include <mutex>
//#include <thread>

#include "Job.hpp"
#include "exchange/HttpExchange.hpp"
#include "impl/exchange/ExchangeImpl.hpp"

#define PIMPL_CLASS HttpExchange

class PIMPL_IMPL {
public:
	Impl(std::string url);

	nlohmann::json& getJsonOrderbook();

private: 
	nlohmann::json jsonOrderbook;
	std::mutex mutex;
	Job update;

	void updateOrderbook(std::string url);
};

#endif  // HTTP_EXCHANGE_IMPL_H
