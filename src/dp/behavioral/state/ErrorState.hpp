#pragma once

#include <string>

#include "state/DeviceState.hpp"

namespace dp::state {

class ErrorState : public DeviceState {
 public:
  std::string name() const override;
  void handle(Device& device) override;
};

}  // namespace dp::state
