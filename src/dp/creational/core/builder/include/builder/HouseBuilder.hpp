#pragma once

#include <memory>

#include "builder/House.hpp"

namespace dp::builder {

/// Builder interface
class HouseBuilder {
 public:
  virtual ~HouseBuilder() = default;

  virtual void build_walls() = 0;
  virtual void build_roof() = 0;
  virtual void build_garage() = 0;
  virtual void build_pool() = 0;

  /// Hands out the finished product and starts a fresh one, so the builder
  /// can be reused safely
  std::unique_ptr<House> result();

 protected:
  House& house();

 private:
  std::unique_ptr<House> house_ = std::make_unique<House>();
};

}  // namespace dp::builder
