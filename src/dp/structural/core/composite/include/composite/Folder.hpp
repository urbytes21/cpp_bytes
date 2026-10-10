#pragma once

#include <cstddef>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "composite/Node.hpp"

namespace dp::composite {

/// Composite: owns its children and delegates to them
class Folder : public Node {
 public:
  using Node::Node;

  /// Adds a child and returns a reference to it for convenient tree building
  template <typename T, typename... Args>
  T& add(Args&&... args) {
    auto child = std::make_unique<T>(std::forward<Args>(args)...);
    T& reference = *child;
    children_.push_back(std::move(child));

    return reference;
  }

  bool remove(const std::string& child_name);

  std::size_t size_bytes() const override;
  void print(int depth) const override;

 private:
  // destroyed recursively with the folder
  std::vector<std::unique_ptr<Node>> children_;
};

}  // namespace dp::composite
