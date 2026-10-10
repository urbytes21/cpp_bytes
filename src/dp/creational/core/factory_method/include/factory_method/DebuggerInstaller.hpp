#pragma once

#include <memory>

#include "factory_method/Debugger.hpp"

namespace dp::factory_method {

/// Creator
class DebuggerInstaller {
 public:
  virtual ~DebuggerInstaller() = default;

  /// Business logic shared by all platforms. It relies on the factory method
  /// and works with ANY product
  void install_and_check() const;

 private:
  /// The factory method
  virtual std::unique_ptr<Debugger> create_debugger() const = 0;
};

}  // namespace dp::factory_method
