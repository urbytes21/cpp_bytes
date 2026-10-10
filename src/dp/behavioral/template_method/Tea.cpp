#include "Tea.hpp"

#include "lab/Logger.h"

namespace dp::template_method {

void Tea::brew() const {
  LOG("    steep the tea bag");
}

void Tea::addCondiments() const {
  LOG("    add lemon");
}

}  // namespace dp::template_method
