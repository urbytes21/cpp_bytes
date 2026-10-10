#pragma once

#include <memory>
#include <string>

#include "chain_of_responsibility/Handler.hpp"

namespace dp::chain_of_responsibility {

std::unique_ptr<Handler> make_authentication_handler();
std::unique_ptr<Handler> make_logging_handler();
std::unique_ptr<Handler> make_method_handler(std::string method);

}  // namespace dp::chain_of_responsibility
