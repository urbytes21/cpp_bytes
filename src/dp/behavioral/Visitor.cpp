#include <memory>
#include <variant>
#include <vector>

#include "visitor/Counter.hpp"
#include "visitor/Element.hpp"
#include "visitor/VariantElement.hpp"
#include "visitor/Visitor.hpp"
#include "visitor/VisitorFactory.hpp"

#include "lab/Example.h"
#include "lab/Logger.h"

namespace {

void classic() {
  using namespace dp::visitor;

  LOG_SECTION("Building a document of Paragraph, Image and Table elements");
  std::vector<std::unique_ptr<Element>> document;
  document.push_back(
      std::make_unique<Paragraph>("Visitor separates data from behavior."));
  document.push_back(std::make_unique<Image>("diagram.png"));
  document.push_back(std::make_unique<Table>(3, 4));
  document.push_back(
      std::make_unique<Paragraph>("New exports need no element changes."));

  const auto apply = [&document](Visitor& visitor) {
    for (const auto& element : document) {
      element->accept(visitor);
    }
  };

  LOG_SECTION("HTML export");
  auto exporter = make_html_exporter();
  apply(*exporter);

  LOG_SECTION("JSON export");
  exporter = make_json_exporter();
  apply(*exporter);

  LOG_SECTION("Word count (a visitor that collects data)");
  auto counter = make_word_counter();
  apply(*counter);
  LOG_S("    words in paragraphs: " << counter->count());
}

void with_variant() {
  using namespace dp::visitor::with_variant;

  LOG_SECTION("Modern alternative: std::variant + std::visit");
  const std::vector<Element> document{Paragraph{"no base classes needed"},
                                      Image{"photo.jpg"}};
  for (const Element& element : document) {
    std::visit(
        Overloaded{
            [](const Paragraph& p) { LOG_S("    paragraph: " << p.text); },
            [](const Image& i) { LOG_S("    image: " << i.path); },
        },
        element);
  }
}

}  // namespace

LAB_EXAMPLE("Visitor",
            "add operations without changing element classes; std::variant "
            "alternative") {
  classic();
  with_variant();
}
