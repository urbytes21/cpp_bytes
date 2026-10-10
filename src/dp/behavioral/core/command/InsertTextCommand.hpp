#pragma once

#include <string>

#include "command/Command.hpp"
#include "command/TextDocument.hpp"

namespace dp::command {

class InsertTextCommand : public Command {
 public:
  InsertTextCommand(TextDocument& document, std::string text);

  void execute() override;
  void undo() override;
  std::string name() const override;

 private:
  TextDocument& document_;
  std::string text_;
};

}  // namespace dp::command
