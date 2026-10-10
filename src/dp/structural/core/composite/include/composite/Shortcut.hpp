#pragma once

#include <cstddef>
#include <string>

#include "composite/Node.hpp"

namespace dp::composite {

/// Another leaf: refers to a path, takes (almost) no space itself
class Shortcut : public Node {
 public:
  Shortcut(std::string name, std::string target);

  std::size_t size_bytes() const override;
  void print(int depth) const override;

 private:
  std::string target_;
};

}  // namespace dp::composite
