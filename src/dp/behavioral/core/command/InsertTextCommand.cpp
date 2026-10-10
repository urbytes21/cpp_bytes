#include "InsertTextCommand.hpp"

#include <utility>

namespace dp::command {

InsertTextCommand::InsertTextCommand(TextDocument& document, std::string text)
    : document_{document}, text_{std::move(text)} {}

void InsertTextCommand::execute() {
  document_.insert(text_);
}

void InsertTextCommand::undo() {
  document_.eraseLast(text_.size());
}

std::string InsertTextCommand::name() const {
  return "insert \"" + text_ + "\"";
}

}  // namespace dp::command
