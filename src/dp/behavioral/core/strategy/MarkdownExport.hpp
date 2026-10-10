#pragma once

#include <string>

#include "strategy/ExportStrategy.hpp"

namespace dp::strategy {
class MarkdownExport : public ExportStrategy {
 public:
  std::string export_text(const std::string& content) const override {
    return "**" + content + "**";
  }
};
}  // namespace dp::strategy