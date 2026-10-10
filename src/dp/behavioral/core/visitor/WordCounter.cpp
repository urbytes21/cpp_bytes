#include "WordCounter.hpp"

#include <sstream>
#include <string>

namespace dp::visitor {

void WordCounter::visit(const Paragraph& paragraph) {
  std::istringstream words(paragraph.text());
  for (std::string word; words >> word;) {
    ++count_;
  }
}

}  // namespace dp::visitor
