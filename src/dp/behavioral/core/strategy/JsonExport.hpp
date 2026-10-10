#pragma once

#include <string>

#include "strategy/ExportStrategy.hpp"

namespace dp::strategy {
class JsonExport : public ExportStrategy {
 public:
  std::string export_text(const std::string& content) const override {
    return R"({"content": ")" + content + "\"}";
  }
};
}  // namespace dp::strategy