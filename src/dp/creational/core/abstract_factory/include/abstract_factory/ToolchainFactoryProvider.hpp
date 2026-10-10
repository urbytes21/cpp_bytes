#pragma once

#include <memory>
#include <string_view>

#include "abstract_factory/ToolchainFactory.hpp"

namespace dp::abstract_factory {

/// Picks the family once, e.g. from configuration. Returns nullptr if unknown
std::unique_ptr<ToolchainFactory> make_toolchain_factory(std::string_view os);

}  // namespace dp::abstract_factory
