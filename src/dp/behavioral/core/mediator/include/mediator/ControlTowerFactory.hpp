#pragma once

#include <memory>

#include "mediator/ControlTower.hpp"

namespace dp::mediator {

/// One runway, first come first served
std::unique_ptr<ControlTower> make_tower();

}  // namespace dp::mediator
