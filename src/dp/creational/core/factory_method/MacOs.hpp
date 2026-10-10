#pragma once

#include <memory>
#include <string>

#include "factory_method/Debugger.hpp"
#include "factory_method/DebuggerInstaller.hpp"

namespace dp::factory_method {

/// Concrete product
class MacOsLldb : public Debugger {
 public:
  std::string install_command() const override;
  std::string version_command() const override;
};

/// Concrete creator
class MacOsInstaller : public DebuggerInstaller {
 private:
  std::unique_ptr<Debugger> create_debugger() const override;
};

}  // namespace dp::factory_method
