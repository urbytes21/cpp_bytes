#pragma once

#include <memory>
#include <string>

namespace dp::strategy {

/// Strategy interface
class ExportStrategy {
 public:
  virtual ~ExportStrategy() = default;

  virtual std::string export_text(const std::string& content) const = 0;
};

std::unique_ptr<ExportStrategy> create_json_export();
std::unique_ptr<ExportStrategy> create_markdown_export();

}  // namespace dp::strategy
