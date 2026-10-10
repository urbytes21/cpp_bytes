#include "WindowsRenderer.hpp"

#include "lab/Logger.h"

namespace dp::bridge {

void WindowsRenderer::draw_rectangle(const std::string& label) const {
  LOG_S("    [Win32] DrawRectangle for '" << label << "'");
}

void WindowsRenderer::draw_text(const std::string& text) const {
  LOG_S("    [Win32] DrawText '" << text << "'");
}

}  // namespace dp::bridge
