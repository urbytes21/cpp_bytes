#pragma once

#include "chain_of_responsibility/Handler.hpp"

namespace dp::chain_of_responsibility {

/// Can STOP the chain
class AuthenticationHandler : public Handler {
 public:
  void handle(const Request& request) const override;
};

}  // namespace dp::chain_of_responsibility
