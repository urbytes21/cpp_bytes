#include <memory>
#include <string_view>
#include <utility>
#include <vector>

#include "template_method/Beverage.hpp"
#include "template_method/BeverageFactory.hpp"

#include "lab/Example.h"
#include "lab/Logger.h"

using namespace dp::template_method;

LAB_EXAMPLE(
    "TemplateMethod",
    "algorithm skeleton in a base class, steps and hooks in subclasses") {
  LOG_SECTION("Same algorithm, different steps");

  std::vector<std::pair<std::string_view, std::unique_ptr<Beverage>>> orders;
  orders.emplace_back("Coffee", makeCoffee());
  orders.emplace_back("Tea", makeTea());
  orders.emplace_back("Black coffee (hook overridden)", makeBlackCoffee());

  for (const auto& [name, beverage] : orders) {
    LOG_S("  " << name << ':');
    beverage->prepare();  // client code only calls the template method
  }
}
