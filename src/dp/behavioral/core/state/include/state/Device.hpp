#pragma once

#include <memory>

#include "state/DeviceState.hpp"

namespace dp::state {

/// Context
class Device {
 public:
  explicit Device(std::unique_ptr<DeviceState> initial);

  /// One tick of work: delegates to the current state
  void tick();

  /// Called by states to request a transition
  void transitionTo(std::unique_ptr<DeviceState> next);
  int startJob();

 private:
  std::unique_ptr<DeviceState> state_;
  std::unique_ptr<DeviceState> next_state_;
  int jobs_{0};
};

}  // namespace dp::state
