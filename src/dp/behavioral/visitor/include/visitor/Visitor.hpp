#pragma once

namespace dp::visitor {

class Paragraph;
class Image;
class Table;

/// Visitor interface.
class Visitor {
 public:
  virtual ~Visitor() = default;
  virtual void visit(const Paragraph& paragraph) = 0;
  virtual void visit(const Image& image) = 0;
  virtual void visit(const Table& table) = 0;
};

}  // namespace dp::visitor
