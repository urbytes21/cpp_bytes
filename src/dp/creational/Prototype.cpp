#include <memory>
#include <string>

#include "prototype/AnalyticsExtension.hpp"
#include "prototype/Extension.hpp"
#include "prototype/ExtensionRegistry.hpp"
#include "prototype/LoggerExtension.hpp"

#include "lab/Example.h"
#include "lab/Logger.h"

using namespace dp::prototype;

LAB_EXAMPLE(
    "Prototype",
    "copy objects through an interface with virtual clone() and presets") {

  LOG_SECTION("Registering configured prototypes");
  ExtensionRegistry registry;
  registry.add("debug-logger", std::make_unique<LoggerExtension>("DEBUG"));
  registry.add("analytics", std::make_unique<AnalyticsExtension>(
                                1200, "https://stats.example"));

  LOG_SECTION("Client clones by name");
  for (const std::string name : {"debug-logger", "analytics", "unknown"}) {
    if (const auto extension = registry.create(name)) {
      LOG_S("  " << name << " -> " << extension->describe());
    } else {
      LOG_S("  " << name << " -> no such prototype");
    }
  }

  LOG_SECTION("Clones are independent copies");
  const LoggerExtension original{"INFO"};
  std::unique_ptr<Extension> copy = original.clone();
  static_cast<LoggerExtension&>(*copy).set_level("TRACE");
  LOG_S("  original: " << original.describe());
  LOG_S("  clone   : " << copy->describe());

  const Extension& through_base = original;
  // no slicing
  const std::unique_ptr<Extension> full_copy = through_base.clone();
  LOG_S("  clone through a base reference keeps the real type: "
        << full_copy->describe());
}
