#pragma once

#include <string>

namespace dp::bridge {

/// Implementor: platform-specific primitives
class Renderer {
 public:
  virtual ~Renderer() = default;

  virtual void draw_rectangle(const std::string& label) const = 0;
  virtual void draw_text(const std::string& text) const = 0;
};

}  // namespace dp::bridge
