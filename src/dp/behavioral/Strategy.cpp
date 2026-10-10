#include <string>

#include "strategy/Document.hpp"
#include "strategy/ExportStrategy.hpp"

#include "lab/Example.h"
#include "lab/Logger.h"

using namespace dp::strategy;

LAB_EXAMPLE("Strategy", "") {
  LOG_SECTION("Swapping strategy objects at run time");

  Document report{"quarterly report"};
  LOG_S("  none     : " << report.exportDocument());

  auto strategy = create_json_export();
  report.set_export_strategy(std::move(strategy));
  LOG_S("  JSON     : " << report.exportDocument());

  strategy = create_markdown_export();
  report.set_export_strategy(std::move(strategy));
  LOG_S("  Markdown : " << report.exportDocument());
}
