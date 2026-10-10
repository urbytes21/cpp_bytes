#include "ClearCommand.hpp"

namespace dp::command {

ClearCommand::ClearCommand(TextDocument& document) : document_{document} {}

void ClearCommand::execute() {
  backup_ = document_.content();  // remember what is needed to undo
  document_.setContent("");
}

void ClearCommand::undo() {
  document_.setContent(backup_);
}

std::string ClearCommand::name() const {
  return "clear";
}

}  // namespace dp::command
