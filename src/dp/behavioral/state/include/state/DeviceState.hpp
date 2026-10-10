#pragma once

#include <string>

namespace dp::state {

class Device;

/// State interface
class DeviceState {
 public:
  virtual ~DeviceState() = default;

  virtual std::string name() const = 0;
  virtual void handle(Device& device) = 0;
};

}  // namespace dp::state
