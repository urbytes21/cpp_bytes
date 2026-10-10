#pragma once

namespace dp::abstract_factory {

/// Product interface
class GdbProduct {
 public:
  virtual ~GdbProduct() = default;

  virtual void install() const = 0;
};

/// Product interface
class CMakeProduct {
 public:
  virtual ~CMakeProduct() = default;

  virtual void install() const = 0;
};

}  // namespace dp::abstract_factory
