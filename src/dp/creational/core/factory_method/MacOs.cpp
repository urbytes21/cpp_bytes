#include "MacOs.hpp"

namespace dp::factory_method {

std::string MacOsLldb::install_command() const {
  return "xcode-select --install";
}

std::string MacOsLldb::version_command() const {
  return "lldb --version";
}

std::unique_ptr<Debugger> MacOsInstaller::create_debugger() const {
  return std::make_unique<MacOsLldb>();
}

}  // namespace dp::factory_method
