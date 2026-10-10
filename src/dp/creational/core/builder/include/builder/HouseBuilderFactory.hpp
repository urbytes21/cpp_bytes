#pragma once

#include <memory>

#include "builder/HouseBuilder.hpp"

namespace dp::builder {

std::unique_ptr<HouseBuilder> make_wooden_house_builder();
std::unique_ptr<HouseBuilder> make_stone_house_builder();

}  // namespace dp::builder
