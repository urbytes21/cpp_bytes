#pragma once

#include <string>

#include "bridge/Renderer.hpp"

namespace dp::bridge {

class WindowsRenderer : public Renderer {
 public:
  void draw_rectangle(const std::string& label) const override;
  void draw_text(const std::string& text) const override;
};

}  // namespace dp::bridge
