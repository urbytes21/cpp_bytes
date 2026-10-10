#pragma once

#include <cstddef>
#include <string>

#include "composite/Node.hpp"

namespace dp::composite {

/// Leaf
class File : public Node {
 public:
  File(std::string name, std::size_t bytes);

  std::size_t size_bytes() const override;
  void print(int depth) const override;

 private:
  std::size_t bytes_;
};

}  // namespace dp::composite
