#include "mediator/ControlTowerFactory.hpp"

#include <memory>

#include "Tower.hpp"

namespace dp::mediator {

std::unique_ptr<ControlTower> make_tower() {
  return std::make_unique<Tower>();
}

}  // namespace dp::mediator
