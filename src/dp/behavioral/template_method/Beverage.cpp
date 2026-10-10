#include "template_method/Beverage.hpp"

#include "lab/Logger.h"

namespace dp::template_method {

void Beverage::prepare() const {
  boilWater();
  brew();
  pourInCup();
  if (wantsCondiments()) {
    addCondiments();
  }
  LOG("    ready!");
}

void Beverage::boilWater() const {
  LOG("    boil water");
}

void Beverage::pourInCup() const {
  LOG("    pour into cup");
}

}  // namespace dp::template_method
