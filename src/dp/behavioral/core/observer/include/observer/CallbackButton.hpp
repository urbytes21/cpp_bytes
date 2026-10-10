#pragma once

#include <functional>
#include <utility>
#include <vector>

#include "observer/Event.hpp"

namespace dp::observer {

/// A lighter alternative: observers are std::function callbacks
class CallbackButton {
 public:
  using Callback = std::function<void(Event)>;

  /// Returns an id that can be used to unsubscribe
  int subscribe(Callback callback);
  void unsubscribe(int id);

  void press() const;

 private:
  std::vector<std::pair<int, Callback>> subscribers_;
  int next_id_{0};
};

}  // namespace dp::observer
