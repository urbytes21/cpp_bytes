#include "factory_method/InstallerFactory.hpp"

#include <memory>

#include "Linux.hpp"
#include "MacOs.hpp"
#include "Windows.hpp"

namespace dp::factory_method {

std::unique_ptr<DebuggerInstaller> make_installer(std::string_view os) {
  if (os == "linux") {
    return std::make_unique<LinuxInstaller>();
  }

  if (os == "windows") {
    return std::make_unique<WindowsInstaller>();
  }

  if (os == "macos") {
    return std::make_unique<MacOsInstaller>();
  }

  return nullptr;
}

}  // namespace dp::factory_method
