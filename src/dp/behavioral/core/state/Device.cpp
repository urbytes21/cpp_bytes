#include "state/Device.hpp"

#include <memory>
#include <utility>

#include "lab/Logger.h"

namespace dp::state {

Device::Device(std::unique_ptr<DeviceState> initial)
    : state_{std::move(initial)} {}

void Device::tick() {
  state_->handle(*this);
  if (next_state_) {
    LOG_S("    transition " << state_->name() << " -> " << next_state_->name());
    state_ = std::move(next_state_);  // safe: handle() has already returned
  }
}

void Device::transitionTo(std::unique_ptr<DeviceState> next) {
  next_state_ = std::move(next);
}

int Device::startJob() {
  return ++jobs_;
}

}  // namespace dp::state
