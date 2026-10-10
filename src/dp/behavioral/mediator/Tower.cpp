#include "Tower.hpp"
#include <optional>

#include "lab/Logger.h"

namespace dp::mediator {

void Tower::request_landing(Aircraft& aircraft) {
  if (!runway_user_.has_value()) {
    runway_user_ = aircraft;
    aircraft.clear_to_land();
  } else {
    waiting_.emplace_back(aircraft);
    LOG_S("  [tower] runway busy with "
          << runway_user_->get().callsign() << ", " << aircraft.callsign()
          << " is number " << waiting_.size() << " in the queue");
    aircraft.hold();
  }
}

void Tower::report_landed(Aircraft& aircraft) {
  LOG_S("  [tower] " << aircraft.callsign() << " vacated the runway");
  runway_user_ = std::nullopt;
  if (!waiting_.empty()) {
    auto next = waiting_.front();
    waiting_.pop_front();

    runway_user_ = next;

    next.get().clear_to_land();
  }
}

}  // namespace dp::mediator
