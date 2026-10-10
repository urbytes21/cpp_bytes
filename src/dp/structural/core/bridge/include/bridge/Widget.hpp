#pragma once

#include <memory>
#include <string>

#include "bridge/Renderer.hpp"

namespace dp::bridge {

/// Abstraction: high-level widget logic, delegates primitives to the renderer
class Widget {
 public:
  explicit Widget(std::shared_ptr<const Renderer> renderer);
  virtual ~Widget() = default;

  virtual void draw() const = 0;
  void set_renderer(std::shared_ptr<const Renderer> renderer);

 protected:
  const Renderer& renderer() const;

 private:
  std::shared_ptr<const Renderer> renderer_;  // the "bridge"
};

/// Refined abstraction
class Button : public Widget {
 public:
  Button(std::shared_ptr<const Renderer> renderer, std::string caption);

  void draw() const override;

 private:
  std::string caption_;
};

/// Refined abstraction
class Label : public Widget {
 public:
  Label(std::shared_ptr<const Renderer> renderer, std::string text);

  void draw() const override;

 private:
  std::string text_;
};

}  // namespace dp::bridge
