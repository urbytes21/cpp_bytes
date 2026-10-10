#include "MacroCommand.hpp"

#include <utility>

namespace dp::command {

MacroCommand::MacroCommand(std::vector<std::unique_ptr<Command>> commands)
    : commands_{std::move(commands)} {}

void MacroCommand::execute() {
  for (const auto& command : commands_) {
    command->execute();
  }
}

void MacroCommand::undo() {  // undo in reverse order
  for (auto it = commands_.rbegin(); it != commands_.rend(); ++it) {
    (*it)->undo();
  }
}

std::string MacroCommand::name() const {
  return "macro of " + std::to_string(commands_.size());
}

}  // namespace dp::command
