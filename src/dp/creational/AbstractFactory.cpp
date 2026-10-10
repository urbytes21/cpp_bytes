#include <memory>
#include <string_view>

#include "abstract_factory/ToolchainFactory.hpp"
#include "abstract_factory/ToolchainFactoryProvider.hpp"

#include "lab/Example.h"
#include "lab/Logger.h"

using namespace dp::abstract_factory;

LAB_EXAMPLE("AbstractFactory",
            "create families of related products that always match") {

  auto install_toolchain = [](const ToolchainFactory& factory) {
    const auto cmake = factory.create_cmake();
    const auto gdb = factory.create_gdb();
    cmake->install();
    gdb->install();  // guaranteed to belong to the same family as cmake
  };

  for (const std::string_view os : {"linux", "windows", "macos", "solaris"}) {
    LOG_SECTION(os);

    const std::unique_ptr<ToolchainFactory> factory =
        make_toolchain_factory(os);
    if (!factory) {
      LOG_S("    no toolchain factory for '" << os << "'");
      continue;
    }

    install_toolchain(*factory);
  }
}
