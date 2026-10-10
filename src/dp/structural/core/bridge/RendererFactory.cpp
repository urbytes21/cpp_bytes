#include "bridge/RendererFactory.hpp"

#include <memory>

#include "LinuxRenderer.hpp"
#include "WindowsRenderer.hpp"

namespace dp::bridge {

std::shared_ptr<const Renderer> make_windows_renderer() {
  return std::make_shared<WindowsRenderer>();
}

std::shared_ptr<const Renderer> make_linux_renderer() {
  return std::make_shared<LinuxRenderer>();
}

}  // namespace dp::bridge
