#include "visitor/Element.hpp"
#include "visitor/Visitor.hpp"

#include <utility>

namespace dp::visitor {

Paragraph::Paragraph(std::string text) : text_{std::move(text)} {}

const std::string& Paragraph::text() const {
  return text_;
}

// Second dispatch: `*this` has the static type Paragraph here.
void Paragraph::accept(Visitor& visitor) const {
  visitor.visit(*this);
}

Image::Image(std::string path) : path_{std::move(path)} {}

const std::string& Image::path() const {
  return path_;
}

void Image::accept(Visitor& visitor) const {
  visitor.visit(*this);
}

Table::Table(int rows, int columns) : rows_{rows}, columns_{columns} {}

int Table::rows() const {
  return rows_;
}

int Table::columns() const {
  return columns_;
}

void Table::accept(Visitor& visitor) const {
  visitor.visit(*this);
}

}  // namespace dp::visitor
