#pragma once

#include <cstddef>
#include <memory>
#include <string>

namespace dp::memento {

/// Originator.
class Editor {
 public:
  /// Memento: public metadata, private state.
  class Snapshot {
   public:
    const std::string& label() const { return label_; }  // safe to show

   private:
    friend class Editor;  // only the originator can read the state
    Snapshot(std::string text, std::size_t cursor, std::string label);

    std::string text_;
    std::size_t cursor_;
    std::string label_;
  };

  void type(const std::string& text);
  void moveCursor(std::size_t position);

  std::unique_ptr<Snapshot> save(const std::string& label) const;
  void restore(const Snapshot& snapshot);

  std::string show() const;

 private:
  std::string text_;
  std::size_t cursor_{0};
};

}  // namespace dp::memento
