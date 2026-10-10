#pragma once

#include <memory>
#include <string>

namespace dp::prototype {

/// Prototype interface: "I know how to copy myself."
class Extension {
 public:
  virtual ~Extension() = default;

  virtual std::unique_ptr<Extension> clone() const = 0;
  virtual std::string describe() const = 0;
};

}  // namespace dp::prototype
