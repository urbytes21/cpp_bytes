#pragma once

#include <memory>
#include <string>
#include <vector>

#include "command/Command.hpp"
#include "command/TextDocument.hpp"

namespace dp::command {

std::unique_ptr<Command> makeInsertTextCommand(TextDocument& document,
                                               std::string text);

std::unique_ptr<Command> makeClearCommand(TextDocument& document);

/// A command made of other commands
std::unique_ptr<Command> makeMacroCommand(
    std::vector<std::unique_ptr<Command>> commands);

}  // namespace dp::command
