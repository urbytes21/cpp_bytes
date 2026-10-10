#pragma once

#include <string>

namespace dp::command {

/// Command interface
class Command {
 public:
  virtual ~Command() = default;

  virtual void execute() = 0;
  virtual void undo() = 0;
  virtual std::string name() const = 0;
};

}  // namespace dp::command
