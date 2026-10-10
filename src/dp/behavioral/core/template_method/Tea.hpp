#pragma once

#include "template_method/Beverage.hpp"

namespace dp::template_method {

class Tea : public Beverage {
 private:
  void brew() const override;
  void addCondiments() const override;
};

}  // namespace dp::template_method
