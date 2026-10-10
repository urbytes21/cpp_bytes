#include "abstract_factory/ToolchainFactoryProvider.hpp"

#include <memory>

#include "Linux.hpp"
#include "MacOs.hpp"
#include "Windows.hpp"

namespace dp::abstract_factory {

std::unique_ptr<ToolchainFactory> make_toolchain_factory(std::string_view os) {
  if (os == "linux") {
    return std::make_unique<LinuxToolchainFactory>();
  }
  if (os == "windows") {
    return std::make_unique<WindowsToolchainFactory>();
  }
  if (os == "macos") {
    return std::make_unique<MacOsToolchainFactory>();
  }
  return nullptr;
}

}  // namespace dp::abstract_factory
