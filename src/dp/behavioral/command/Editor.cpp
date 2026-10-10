#include "command/Editor.hpp"

#include <utility>

#include "lab/Logger.h"

namespace dp::command {

Editor::Editor(const TextDocument& document) : document_{document} {}

void Editor::run(std::unique_ptr<Command> command) {
  command->execute();
  LOG_S("  run  " << command->name() << " -> \"" << document_.content()
                  << "\"");
  history_.push_back(std::move(command));
}

void Editor::undo() {
  if (history_.empty()) {
    LOG("  undo: nothing to undo");
    return;
  }

  history_.back()->undo();
  LOG_S("  undo " << history_.back()->name() << " -> \"" << document_.content()
                  << "\"");
  history_.pop_back();
}

}  // namespace dp::command
