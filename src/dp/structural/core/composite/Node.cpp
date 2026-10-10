#include "composite/Node.hpp"

#include <utility>

namespace dp::composite {

Node::Node(std::string name) : name_{std::move(name)} {}

const std::string& Node::name() const {
  return name_;
}

std::string Node::indent(int depth) {
  return std::string(static_cast<std::size_t>(depth) * 2, ' ');
}

}  // namespace dp::composite
