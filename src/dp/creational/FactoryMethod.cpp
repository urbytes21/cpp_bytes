#include <string_view>

#include "factory_method/DebuggerInstaller.hpp"
#include "factory_method/InstallerFactory.hpp"

#include "lab/Example.h"
#include "lab/Logger.h"

using namespace dp::factory_method;

LAB_EXAMPLE("FactoryMethod",
            "subclasses decide which product a creator makes") {
  for (const std::string_view os : {"linux", "windows", "macos", "unknown"}) {
    LOG_SECTION(os);

    if (const auto installer = make_installer(os)) {
      installer->install_and_check();
    } else {
      LOG_S("    no installer for '" << os << "'");
    }
  }
}
