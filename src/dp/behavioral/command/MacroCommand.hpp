#pragma once

#include <memory>
#include <string>
#include <vector>

#include "command/Command.hpp"

namespace dp::command {

/// A command made of other commands.
class MacroCommand : public Command {
 public:
  explicit MacroCommand(std::vector<std::unique_ptr<Command>> commands);

  void execute() override;
  void undo() override;
  std::string name() const override;

 private:
  std::vector<std::unique_ptr<Command>> commands_;
};

}  // namespace dp::command
