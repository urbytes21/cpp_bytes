#pragma once

#include <memory>
#include <vector>

#include "command/Command.hpp"
#include "command/TextDocument.hpp"

namespace dp::command {

/// Invoker: executes commands without knowing what they do, and keeps a history.
class Editor {
 public:
  explicit Editor(const TextDocument& document);

  void run(std::unique_ptr<Command> command);
  void undo();

 private:
  const TextDocument& document_;
  std::vector<std::unique_ptr<Command>> history_;
};

}  // namespace dp::command
