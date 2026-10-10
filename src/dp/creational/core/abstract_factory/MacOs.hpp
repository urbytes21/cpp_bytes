#pragma once

#include <memory>

#include "abstract_factory/Products.hpp"
#include "abstract_factory/ToolchainFactory.hpp"

namespace dp::abstract_factory {

// The MacOs family: concrete products and the factory that creates them

class MacOsGdb : public GdbProduct {
 public:
  void install() const override;
};

class MacOsCMake : public CMakeProduct {
 public:
  void install() const override;
};

class MacOsToolchainFactory : public ToolchainFactory {
 public:
  std::unique_ptr<GdbProduct> create_gdb() const override;
  std::unique_ptr<CMakeProduct> create_cmake() const override;
};

}  // namespace dp::abstract_factory
