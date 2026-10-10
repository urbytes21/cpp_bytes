#pragma once

#include <memory>

#include "state/DeviceState.hpp"

namespace dp::state {

/// @TODO: use abstract factory
std::unique_ptr<DeviceState> makeIdleState();
std::unique_ptr<DeviceState> makeProcessingState();
std::unique_ptr<DeviceState> makeErrorState();

}  // namespace dp::state
