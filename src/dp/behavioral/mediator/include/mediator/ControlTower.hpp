#pragma once

namespace dp::mediator {

class Aircraft;

/// Mediator interface
class ControlTower {
 public:
  virtual ~ControlTower() = default;

  virtual void request_landing(Aircraft& aircraft) = 0;
  virtual void report_landed(Aircraft& aircraft) = 0;
};

}  // namespace dp::mediator
