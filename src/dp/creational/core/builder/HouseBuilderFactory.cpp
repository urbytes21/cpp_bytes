#include "builder/HouseBuilderFactory.hpp"

#include <memory>

#include "StoneHouseBuilder.hpp"
#include "WoodenHouseBuilder.hpp"

namespace dp::builder {

std::unique_ptr<HouseBuilder> make_wooden_house_builder() {
  return std::make_unique<WoodenHouseBuilder>();
}

std::unique_ptr<HouseBuilder> make_stone_house_builder() {
  return std::make_unique<StoneHouseBuilder>();
}

}  // namespace dp::builder
