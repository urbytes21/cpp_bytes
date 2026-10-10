#include "Coffee.hpp"

#include "lab/Logger.h"

namespace dp::template_method {

void Coffee::brew() const {
  LOG("    drip coffee through the filter");
}

void Coffee::addCondiments() const {
  LOG("    add sugar and milk");
}

}  // namespace dp::template_method
