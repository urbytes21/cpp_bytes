#pragma once

#include "chain_of_responsibility/Handler.hpp"

namespace dp::chain_of_responsibility {

/// Does some work and always PASSES the request on.
class LoggingHandler : public Handler {
 public:
  void handle(const Request& request) const override;
};

}  // namespace dp::chain_of_responsibility
