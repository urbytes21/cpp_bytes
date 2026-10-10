#include "state/DeviceStateFactory.hpp"

#include <memory>

#include "ErrorState.hpp"
#include "IdleState.hpp"
#include "ProcessingState.hpp"

namespace dp::state {

std::unique_ptr<DeviceState> makeIdleState() {
  return std::make_unique<IdleState>();
}

std::unique_ptr<DeviceState> makeProcessingState() {
  return std::make_unique<ProcessingState>();
}

std::unique_ptr<DeviceState> makeErrorState() {
  return std::make_unique<ErrorState>();
}

}  // namespace dp::state
