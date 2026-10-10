#include "template_method/BeverageFactory.hpp"

#include <memory>

#include "BlackCoffee.hpp"
#include "Coffee.hpp"
#include "Tea.hpp"

namespace dp::template_method {

std::unique_ptr<Beverage> makeCoffee() {
  return std::make_unique<Coffee>();
}

std::unique_ptr<Beverage> makeTea() {
  return std::make_unique<Tea>();
}

std::unique_ptr<Beverage> makeBlackCoffee() {
  return std::make_unique<BlackCoffee>();
}

}  // namespace dp::template_method
