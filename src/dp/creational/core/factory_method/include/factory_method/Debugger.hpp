#pragma once

#include <string>

namespace dp::factory_method {

/// Product interface
class Debugger {
 public:
  virtual ~Debugger() = default;

  virtual std::string install_command() const = 0;
  virtual std::string version_command() const = 0;
};

}  // namespace dp::factory_method
