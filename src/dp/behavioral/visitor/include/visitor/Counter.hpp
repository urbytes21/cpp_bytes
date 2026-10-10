#pragma once

#include "visitor/Visitor.hpp"

namespace dp::visitor {

/// A visitor that also produces a count
class Counter : public Visitor {
 public:
  virtual int count() const = 0;
};

}  // namespace dp::visitor
