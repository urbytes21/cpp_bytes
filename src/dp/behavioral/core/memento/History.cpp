#include "memento/History.hpp"

#include <utility>

#include "lab/Logger.h"

namespace dp::memento {

History::History(Editor& editor) : editor_{editor} {}

void History::backup(const std::string& label) {
  snapshots_.push_back(editor_.save(label));
}

void History::undo() {
  if (snapshots_.empty()) {
    LOG("  nothing to undo");
    return;
  }

  const std::unique_ptr<Editor::Snapshot> snapshot =
      std::move(snapshots_.back());
  snapshots_.pop_back();

  editor_.restore(*snapshot);
  LOG_S("  undo to '" << snapshot->label() << "' -> " << editor_.show());
}

void History::list() const {
  for (const auto& snapshot : snapshots_) {
    LOG_S("    saved: " << snapshot->label());
  }
}

}  // namespace dp::memento
