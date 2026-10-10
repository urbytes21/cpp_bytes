#pragma once

#include <string>

namespace dp::observer {

enum class Event;

/// Observer interface.
class Listener {
 public:
  virtual ~Listener() = default;

  virtual void on_event(const std::string& source, Event event) = 0;
};

}  // namespace dp::observer
