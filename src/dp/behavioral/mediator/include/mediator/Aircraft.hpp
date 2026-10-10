#pragma once

#include <string>

#include "mediator/ControlTower.hpp"

namespace dp::mediator {

/// Component: communicates only through the tower.
class Aircraft {
 public:
  Aircraft(std::string callsign, ControlTower& tower);

  const std::string& callsign() const;

  void request_landing();

  // Called by the tower.
  void clear_to_land();
  void hold() const;

  void land();

 private:
  std::string callsign_;
  ControlTower& tower_;
  bool cleared_{false};
};

}  // namespace dp::mediator
