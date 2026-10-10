#pragma once

#include <deque>
#include <functional>
#include <optional>

#include "mediator/Aircraft.hpp"
#include "mediator/ControlTower.hpp"

namespace dp::mediator {

/// Concrete mediator: one runway, first come first served
class Tower : public ControlTower {
 public:
  void request_landing(Aircraft& aircraft) override;
  void report_landed(Aircraft& aircraft) override;

 private:
  std::optional<std::reference_wrapper<Aircraft>> runway_user_;
  std::deque<std::reference_wrapper<Aircraft>> waiting_;
};

}  // namespace dp::mediator
