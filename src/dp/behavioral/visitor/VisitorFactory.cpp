#include "visitor/VisitorFactory.hpp"

#include <memory>

#include "HtmlExporter.hpp"
#include "JsonExporter.hpp"
#include "WordCounter.hpp"

namespace dp::visitor {

std::unique_ptr<Visitor> make_html_exporter() {
  return std::make_unique<HtmlExporter>();
}

std::unique_ptr<Visitor> make_json_exporter() {
  return std::make_unique<JsonExporter>();
}

std::unique_ptr<Counter> make_word_counter() {
  return std::make_unique<WordCounter>();
}

}  // namespace dp::visitor
