#pragma once

#include <memory>

#include "proxy/Service.hpp"

namespace dp::proxy {

/// Real subject: expensive to create
std::unique_ptr<Service> make_server();

/// Proxy: lazy creation + access control + logging
std::unique_ptr<Service> make_server_proxy();

}  // namespace dp::proxy
