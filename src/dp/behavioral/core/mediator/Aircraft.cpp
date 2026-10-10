#include "mediator/Aircraft.hpp"

#include <utility>

#include "lab/Logger.h"

namespace dp::mediator {

Aircraft::Aircraft(std::string callsign, ControlTower& tower)
    : callsign_{std::move(callsign)}, tower_{tower} {}

const std::string& Aircraft::callsign() const {
  return callsign_;
}

void Aircraft::request_landing() {
  LOG_S("  " << callsign_ << ": requesting landing");
  tower_.request_landing(*this);
}

void Aircraft::clear_to_land() {
  cleared_ = true;
  LOG_S("  " << callsign_ << ": cleared to land");
}

void Aircraft::hold() const {
  LOG_S("  " << callsign_ << ": holding pattern");
}

void Aircraft::land() {
  if (!cleared_) {
    LOG_S("  " << callsign_ << ": cannot land without clearance");
    return;
  }

  LOG_S("  " << callsign_ << ": touchdown");
  cleared_ = false;
  tower_.report_landed(*this);
}

}  // namespace dp::mediator
