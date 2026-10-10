#include <memory>

#include "strategy/ExportStrategy.hpp"

#include "JsonExport.hpp"
#include "MarkdownExport.hpp"

namespace dp::strategy {
std::unique_ptr<ExportStrategy> create_json_export() {
  return std::make_unique<JsonExport>();
}

std::unique_ptr<ExportStrategy> create_markdown_export() {
  return std::make_unique<MarkdownExport>();
}
}  // namespace dp::strategy