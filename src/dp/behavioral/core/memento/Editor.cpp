#include "memento/Editor.hpp"

#include <algorithm>
#include <utility>

namespace dp::memento {

Editor::Snapshot::Snapshot(std::string text, std::size_t cursor,
                           std::string label)
    : text_{std::move(text)}, cursor_{cursor}, label_{std::move(label)} {}

void Editor::type(const std::string& text) {
  text_.insert(cursor_, text);
  cursor_ += text.size();
}

void Editor::moveCursor(std::size_t position) {
  cursor_ = std::min(position, text_.size());
}

std::unique_ptr<Editor::Snapshot> Editor::save(const std::string& label) const {
  // std::make_unique cannot reach the private constructor, so `new` is used
  return std::unique_ptr<Snapshot>(new Snapshot(text_, cursor_, label));
}

void Editor::restore(const Snapshot& snapshot) {
  text_ = snapshot.text_;
  cursor_ = snapshot.cursor_;
}

std::string Editor::show() const {
  std::string view = text_;
  view.insert(cursor_, "|");  // visualize the cursor
  return "\"" + view + "\"";
}

}  // namespace dp::memento
