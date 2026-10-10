#pragma once

#include "Coffee.hpp"

namespace dp::template_method {

class BlackCoffee : public Coffee {
 private:
  bool wantsCondiments() const override {
    return false;
  }  // overrides only the hook
};

}  // namespace dp::template_method
