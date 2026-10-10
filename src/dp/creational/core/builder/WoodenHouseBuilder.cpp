#include "WoodenHouseBuilder.hpp"

namespace dp::builder {

void WoodenHouseBuilder::build_walls() {
  house().add_part("wooden walls");
}

void WoodenHouseBuilder::build_roof() {
  house().add_part("shingle roof");
}

void WoodenHouseBuilder::build_garage() {
  house().add_part("wooden carport");
}

void WoodenHouseBuilder::build_pool() {
  house().add_part("above-ground pool");
}

}  // namespace dp::builder
