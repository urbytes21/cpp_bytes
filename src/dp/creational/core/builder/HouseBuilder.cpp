#include "builder/HouseBuilder.hpp"

#include <utility>

namespace dp::builder {

std::unique_ptr<House> HouseBuilder::result() {
  auto finished = std::move(house_);
  house_ = std::make_unique<House>();
  return finished;
}

House& HouseBuilder::house() {
  return *house_;
}

}  // namespace dp::builder
