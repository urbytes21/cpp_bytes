#include "bridge/Widget.hpp"

#include <utility>

namespace dp::bridge {

Widget::Widget(std::shared_ptr<const Renderer> renderer)
    : renderer_{std::move(renderer)} {}

void Widget::set_renderer(std::shared_ptr<const Renderer> renderer) {
  renderer_ = std::move(renderer);
}

const Renderer& Widget::renderer() const {
  return *renderer_;
}

Button::Button(std::shared_ptr<const Renderer> renderer, std::string caption)
    : Widget{std::move(renderer)}, caption_{std::move(caption)} {}

void Button::draw() const {
  renderer().draw_rectangle(caption_);
  renderer().draw_text(caption_);
}

Label::Label(std::shared_ptr<const Renderer> renderer, std::string text)
    : Widget{std::move(renderer)}, text_{std::move(text)} {}

void Label::draw() const {
  renderer().draw_text(text_);
}

}  // namespace dp::bridge
