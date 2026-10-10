#pragma once

#include <string>

#include "observer/Listener.hpp"

namespace dp::observer {

class SoundListener : public Listener {
 public:
  void on_event(const std::string& source, Event event) override;
};

}  // namespace dp::observer
