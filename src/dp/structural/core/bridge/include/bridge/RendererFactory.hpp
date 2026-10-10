#pragma once

#include <memory>

#include "bridge/Renderer.hpp"

namespace dp::bridge {

std::shared_ptr<const Renderer> make_windows_renderer();
std::shared_ptr<const Renderer> make_linux_renderer();

}  // namespace dp::bridge
