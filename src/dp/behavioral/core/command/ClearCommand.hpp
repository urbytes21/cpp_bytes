#pragma once

#include <string>

#include "command/Command.hpp"
#include "command/TextDocument.hpp"

namespace dp::command {

class ClearCommand : public Command {
 public:
  explicit ClearCommand(TextDocument& document);

  void execute() override;
  void undo() override;
  std::string name() const override;

 private:
  TextDocument& document_;
  std::string backup_;
};

}  // namespace dp::command
