#include "StoneHouseBuilder.hpp"

namespace dp::builder {

void StoneHouseBuilder::build_walls() {
  house().add_part("stone walls");
}

void StoneHouseBuilder::build_roof() {
  house().add_part("clay tile roof");
}

void StoneHouseBuilder::build_garage() {
  house().add_part("stone garage");
}

void StoneHouseBuilder::build_pool() {
  house().add_part("in-ground pool");
}

}  // namespace dp::builder
