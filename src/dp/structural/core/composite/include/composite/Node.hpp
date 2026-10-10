#pragma once

#include <cstddef>
#include <string>

namespace dp::composite {

/// Component
class Node {
 public:
  explicit Node(std::string name);
  virtual ~Node() = default;

  const std::string& name() const;

  virtual std::size_t size_bytes() const = 0;
  virtual void print(int depth) const = 0;

 protected:
  static std::string indent(int depth);

 private:
  std::string name_;
};

}  // namespace dp::composite
