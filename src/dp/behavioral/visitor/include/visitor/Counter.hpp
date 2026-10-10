#pragma once

#include "visitor/Visitor.hpp"

namespace dp::visitor {
class Counter : public Visitor {
 public:
  virtual int count() const = 0;
};
}  // namespace dp::visitor