#pragma once

#include "visitor/Element.hpp"
#include "visitor/Visitor.hpp"

namespace dp::visitor {

class JsonExporter : public Visitor {
 public:
  void visit(const Paragraph& paragraph) override;
  void visit(const Image& image) override;
  void visit(const Table& table) override;
};

}  // namespace dp::visitor
