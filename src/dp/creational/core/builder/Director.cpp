#include "builder/Director.hpp"

namespace dp::builder {

void Director::build_minimal(HouseBuilder& builder) {
  builder.build_walls();
  builder.build_roof();
}

void Director::build_luxury(HouseBuilder& builder) {
  builder.build_walls();
  builder.build_roof();
  builder.build_garage();
  builder.build_pool();
}

}  // namespace dp::builder
