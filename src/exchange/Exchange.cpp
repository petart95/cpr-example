#include "impl/exchange/ExchangeImpl.hpp"

PIMPLE_M(registerStrategy, (std::function<void()> strategy), (strategy))
PIMPLE_M(registerStrategies, (std::vector<std::function<void()>> stragies), (stragies))
PIMPLE_M(runRegisterStrategies, (), ())
