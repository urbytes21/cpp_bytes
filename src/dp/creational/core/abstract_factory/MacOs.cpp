#include "MacOs.hpp"

#include "lab/Logger.h"

namespace dp::abstract_factory {

void MacOsGdb::install() const {
  LOG("    brew install gdb && gdb --version");
}

void MacOsCMake::install() const {
  LOG("    brew install cmake && cmake --version");
}

std::unique_ptr<GdbProduct> MacOsToolchainFactory::create_gdb() const {
  return std::make_unique<MacOsGdb>();
}

std::unique_ptr<CMakeProduct> MacOsToolchainFactory::create_cmake() const {
  return std::make_unique<MacOsCMake>();
}

}  // namespace dp::abstract_factory
