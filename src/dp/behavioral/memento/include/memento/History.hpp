#pragma once

#include <memory>
#include <string>
#include <vector>

#include "memento/Editor.hpp"

namespace dp::memento {

/// Caretaker: stores snapshots, has no idea what they contain.
class History {
 public:
  explicit History(Editor& editor);

  void backup(const std::string& label);
  void undo();
  void list() const;

 private:
  Editor& editor_;
  std::vector<std::unique_ptr<Editor::Snapshot>> snapshots_;
};

}  // namespace dp::memento
