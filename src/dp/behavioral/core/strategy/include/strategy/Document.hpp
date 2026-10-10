#pragma once

#include <memory>

#include "ExportStrategy.hpp"

namespace dp::strategy {

/// @brief Context
class Document {
 public:
  explicit Document(std::string content) : content_{std::move(content)} {}

  void set_export_strategy(std::unique_ptr<ExportStrategy> strategy) {
    strategy_ = std::move(strategy);
  }

  std::string exportDocument() const {
    if (!strategy_) {
      return "(no export strategy selected)";
    }
    return strategy_->export_text(content_);
  }

 private:
  std::string content_;
  std::unique_ptr<ExportStrategy> strategy_;
};

}  // namespace dp::strategy
