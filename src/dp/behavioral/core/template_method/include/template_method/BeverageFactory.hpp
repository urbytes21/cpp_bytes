#pragma once

#include <memory>

#include "template_method/Beverage.hpp"

namespace dp::template_method {
std::unique_ptr<Beverage> makeCoffee();
std::unique_ptr<Beverage> makeTea();
std::unique_ptr<Beverage> makeBlackCoffee();
}  // namespace dp::template_method
