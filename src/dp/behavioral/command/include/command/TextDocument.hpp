#pragma once

#include <cstddef>
#include <string>
#include <utility>

namespace dp::command {

/// Receiver: contains the business logic.
class TextDocument {
 public:
  void insert(const std::string& text) { content_ += text; }
  void eraseLast(std::size_t count) { content_.erase(content_.size() - count); }
  const std::string& content() const { return content_; }
  void setContent(std::string content) { content_ = std::move(content); }

 private:
  std::string content_;
};

}  // namespace dp::command
