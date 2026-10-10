#include "Linux.hpp"

namespace dp::factory_method {

std::string LinuxGdb::install_command() const {
  return "sudo apt install -y gdb";
}

std::string LinuxGdb::version_command() const {
  return "gdb --version";
}

std::unique_ptr<Debugger> LinuxInstaller::create_debugger() const {
  return std::make_unique<LinuxGdb>();
}

}  // namespace dp::factory_method
