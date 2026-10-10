#include "Linux.hpp"

#include "lab/Logger.h"

namespace dp::abstract_factory {

void LinuxGdb::install() const {
  LOG("    sudo apt install -y gdb && gdb --version");
}

void LinuxCMake::install() const {
  LOG("    sudo apt install -y cmake && cmake --version");
}

std::unique_ptr<GdbProduct> LinuxToolchainFactory::create_gdb() const {
  return std::make_unique<LinuxGdb>();
}

std::unique_ptr<CMakeProduct> LinuxToolchainFactory::create_cmake() const {
  return std::make_unique<LinuxCMake>();
}

}  // namespace dp::abstract_factory
