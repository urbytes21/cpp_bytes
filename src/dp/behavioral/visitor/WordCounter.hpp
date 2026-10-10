#pragma once

#include "visitor/Counter.hpp"
#include "visitor/Element.hpp"
#include "visitor/Visitor.hpp"

namespace dp::visitor {

/// A visitor that computes something instead of printing
class WordCounter : public Counter {
 public:
  void visit(const Paragraph& paragraph) override;

  void visit(const Image& /*image*/) override {}
  void visit(const Table& /*table*/) override {}
  int count() const override { return count_; }

 private:
  int count_{0};
};
}  // namespace dp::visitor
