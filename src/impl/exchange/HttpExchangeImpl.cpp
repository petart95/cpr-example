#include <cpr/cpr.h>

#include "impl/exchange/HttpExchangeImpl.hpp"

PIMPL_IMPL::Impl(std::string url)
    : update (
        [this, url] {
            //std::cout << "test2" << std::endl << std::flush;
            updateOrderbook(url);
            runRegisterStrategies();
        },
        [this, url] {
            //std::cout << "test1" << std::endl << std::flush;
            updateOrderbook(url);
            //std::cout << "test11" << std::endl << std::flush;
        }
    )
{
}

nlohmann::json& PIMPL_IMPL::getJsonOrderbook()
{
	//std::unique_lock<std::mutex> lock(mutex);
	return jsonOrderbook;
}

void PIMPL_IMPL::updateOrderbook(std::string url) 
{
    //std::cout << "test3" << std::endl << std::flush;
    //std::unique_lock<std::mutex> lock(mutex);
    auto request = cpr::Get(cpr::Url{url});
    jsonOrderbook = nlohmann::json::parse(request.text);
}
