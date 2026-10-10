#pragma once

#include <memory>

#include "abstract_factory/Products.hpp"
#include "abstract_factory/ToolchainFactory.hpp"

namespace dp::abstract_factory {

// The Windows family: concrete products and the factory that creates them

class WindowsGdb : public GdbProduct {
 public:
  void install() const override;
};

class WindowsCMake : public CMakeProduct {
 public:
  void install() const override;
};

class WindowsToolchainFactory : public ToolchainFactory {
 public:
  std::unique_ptr<GdbProduct> create_gdb() const override;
  std::unique_ptr<CMakeProduct> create_cmake() const override;
};

}  // namespace dp::abstract_factory
