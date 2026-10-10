#include "LinuxRenderer.hpp"

#include "lab/Logger.h"

namespace dp::bridge {

void LinuxRenderer::draw_rectangle(const std::string& label) const {
  LOG_S("    [X11] XDrawRectangle for '" << label << "'");
}

void LinuxRenderer::draw_text(const std::string& text) const {
  LOG_S("    [X11] XDrawString '" << text << "'");
}

}  // namespace dp::bridge
