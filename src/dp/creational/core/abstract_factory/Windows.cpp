#include "Windows.hpp"

#include "lab/Logger.h"

namespace dp::abstract_factory {

void WindowsGdb::install() const {
  LOG("    pacman -S mingw-w64-x86_64-gdb && gdb --version");
}

void WindowsCMake::install() const {
  LOG("    pacman -S mingw-w64-x86_64-cmake && cmake --version");
}

std::unique_ptr<GdbProduct> WindowsToolchainFactory::create_gdb() const {
  return std::make_unique<WindowsGdb>();
}

std::unique_ptr<CMakeProduct> WindowsToolchainFactory::create_cmake() const {
  return std::make_unique<WindowsCMake>();
}

}  // namespace dp::abstract_factory
