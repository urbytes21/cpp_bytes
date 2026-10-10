#pragma once

#include <string>

#include "observer/Event.hpp"

namespace dp::observer {

/// Observer interface.
class Listener {
 public:
  virtual ~Listener() = default;

  virtual void on_event(const std::string& source, Event event) = 0;
};

}  // namespace dp::observer
