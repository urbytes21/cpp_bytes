#include "Windows.hpp"

namespace dp::factory_method {

std::string WindowsGdb::install_command() const {
  return "pacman -S mingw-w64-x86_64-gdb";
}

std::string WindowsGdb::version_command() const {
  return "gdb.exe --version";
}

std::unique_ptr<Debugger> WindowsInstaller::create_debugger() const {
  return std::make_unique<WindowsGdb>();
}

}  // namespace dp::factory_method
