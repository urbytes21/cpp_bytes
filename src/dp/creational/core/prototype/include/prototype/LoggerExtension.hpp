#pragma once

#include <memory>
#include <string>

#include "prototype/Extension.hpp"

namespace dp::prototype {

/// Concrete prototype: clone() uses the (deep-copying) copy constructor
class LoggerExtension : public Extension {
 public:
  explicit LoggerExtension(std::string level);

  std::unique_ptr<Extension> clone() const override;
  std::string describe() const override;
  void set_level(std::string level);

 private:
  std::string level_;
};

}  // namespace dp::prototype
