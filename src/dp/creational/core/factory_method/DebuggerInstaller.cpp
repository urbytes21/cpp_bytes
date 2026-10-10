#include "factory_method/DebuggerInstaller.hpp"

#include "lab/Logger.h"

namespace dp::factory_method {

void DebuggerInstaller::install_and_check() const {
  const std::unique_ptr<Debugger> debugger = create_debugger();
  LOG_S("    install: " << debugger->install_command());
  LOG_S("    verify : " << debugger->version_command());
}

}  // namespace dp::factory_method
