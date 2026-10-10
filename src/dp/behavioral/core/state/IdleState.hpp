#pragma once

#include <string>

#include "state/DeviceState.hpp"

namespace dp::state {

class IdleState : public DeviceState {
 public:
  std::string name() const override;
  void handle(Device& device) override;
};

}  // namespace dp::state
