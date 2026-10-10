#include "command/CommandFactory.hpp"

#include <memory>
#include <utility>

#include "ClearCommand.hpp"
#include "InsertTextCommand.hpp"
#include "MacroCommand.hpp"

namespace dp::command {

std::unique_ptr<Command> makeInsertTextCommand(TextDocument& document,
                                               std::string text) {
  return std::make_unique<InsertTextCommand>(document, std::move(text));
}

std::unique_ptr<Command> makeClearCommand(TextDocument& document) {
  return std::make_unique<ClearCommand>(document);
}

std::unique_ptr<Command> makeMacroCommand(
    std::vector<std::unique_ptr<Command>> commands) {
  return std::make_unique<MacroCommand>(std::move(commands));
}

}  // namespace dp::command
