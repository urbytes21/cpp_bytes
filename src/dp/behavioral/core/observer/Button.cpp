#include "observer/Button.hpp"

#include <utility>

#include "observer/Listener.hpp"

#include "lab/Logger.h"

namespace dp::observer {

Button::Button(std::string name) : name_{std::move(name)} {}

void Button::attach(Listener& listener) {
  listeners_.emplace_back(listener);
}

void Button::detach(Listener& listener) {
  std::erase_if(listeners_,
                [&](const auto& ref) { return &ref.get() == &listener; });
}

void Button::press() {
  notify(Event::kPressed);
}

void Button::release() {
  notify(Event::kReleased);
}

void Button::notify(Event event) {
  LOG_S("  " << name_ << " " << to_string(event) << ", notifying "
             << listeners_.size() << " listener(s)");

  for (auto& listener : listeners_) {
    listener.get().on_event(name_, event);
  }
}

}  // namespace dp::observer
