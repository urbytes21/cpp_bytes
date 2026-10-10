#pragma once

#include <memory>
#include <string_view>

#include "factory_method/DebuggerInstaller.hpp"

namespace dp::factory_method {

/// Returns the concrete creator for `os`, or nullptr if unknown
std::unique_ptr<DebuggerInstaller> make_installer(std::string_view os);

}  // namespace dp::factory_method
