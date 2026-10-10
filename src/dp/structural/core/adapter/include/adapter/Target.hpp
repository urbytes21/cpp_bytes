#pragma once

namespace dp::adapter {

/// Target: the interface the client code expects
class Target {
 public:
  virtual ~Target() = default;

  virtual void request() = 0;
};

}  // namespace dp::adapter
