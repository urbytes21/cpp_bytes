#pragma once

#include <string>

namespace dp::chain_of_responsibility {

struct Request {
  std::string method;
  std::string path;
  std::string token;
};

}  // namespace dp::chain_of_responsibility
