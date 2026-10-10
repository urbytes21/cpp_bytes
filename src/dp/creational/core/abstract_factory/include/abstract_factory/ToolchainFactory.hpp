#pragma once

#include <memory>

#include "abstract_factory/Products.hpp"

namespace dp::abstract_factory {

/// Abstract factory: creates one product of each kind, all from one family
class ToolchainFactory {
 public:
  virtual ~ToolchainFactory() = default;

  virtual std::unique_ptr<GdbProduct> create_gdb() const = 0;
  virtual std::unique_ptr<CMakeProduct> create_cmake() const = 0;
};

}  // namespace dp::abstract_factory
