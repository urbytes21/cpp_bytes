#pragma once

#include "builder/HouseBuilder.hpp"

namespace dp::builder {

class WoodenHouseBuilder : public HouseBuilder {
 public:
  void build_walls() override;
  void build_roof() override;
  void build_garage() override;
  void build_pool() override;
};

}  // namespace dp::builder
