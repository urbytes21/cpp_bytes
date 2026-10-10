#include "observer/CallbackButton.hpp"

#include <utility>

namespace dp::observer {

int CallbackButton::subscribe(Callback callback) {
  subscribers_.emplace_back(next_id_, std::move(callback));
  return next_id_++;
}

void CallbackButton::unsubscribe(int id) {
  std::erase_if(subscribers_,
                [id](const auto& entry) { return entry.first == id; });
}

void CallbackButton::press() const {
  for (const auto& [id, callback] : subscribers_) {
    callback(Event::kPressed);
  }
}

}  // namespace dp::observer
