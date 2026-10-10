#pragma once

#include "builder/HouseBuilder.hpp"

namespace dp::builder {

/// Director: knows the recipes, not the materials
class Director {
 public:
  static void build_minimal(HouseBuilder& builder);
  static void build_luxury(HouseBuilder& builder);
};

}  // namespace dp::builder
