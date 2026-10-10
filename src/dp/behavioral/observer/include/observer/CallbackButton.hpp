#pragma once

#include <functional>
#include <utility>
#include <vector>

namespace dp::observer {
enum class Event;

/// A lighter alternative: observers are std::function callbacks.
class CallbackButton {
 public:
  using Callback = std::function<void(Event)>;

  /// Returns an id that can be used to unsubscribe.
  int subscribe(Callback callback);
  void unsubscribe(int id);

  void press() const;

 private:
  std::vector<std::pair<int, Callback>> subscribers_;
  int next_id_{0};
};

}  // namespace dp::observer
