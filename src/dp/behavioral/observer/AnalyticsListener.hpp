#pragma once

#include <string>

#include "observer/Listener.hpp"

namespace dp::observer {

class AnalyticsListener : public Listener {
 public:
  void on_event(const std::string& source, Event event) override;

 private:
  int events_{0};
};

}  // namespace dp::observer
