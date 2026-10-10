#pragma once

#include <string>

#include "chain_of_responsibility/Handler.hpp"

namespace dp::chain_of_responsibility {

/// HANDLES the requests it is responsible for, forwards the others
class MethodHandler : public Handler {
 public:
  explicit MethodHandler(std::string method);

  void handle(const Request& request) const override;

 private:
  std::string method_;
};

}  // namespace dp::chain_of_responsibility
