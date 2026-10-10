#include "lab/Example.h"
#include "lab/Logger.h"

#include "state/Device.hpp"
#include "state/DeviceStateFactory.hpp"

LAB_EXAMPLE("State",
            "an object changes behavior with its state: one class per state") {
  LOG_SECTION("A device moving through Idle -> Processing -> Error states");
  dp::state::Device device{dp::state::makeIdleState()};
  for (int tick = 0; tick < 8; ++tick) {
    device.tick();
  }
}
