#pragma once

#include <memory>

#include "visitor/Visitor.hpp"
#include "visitor/Counter.hpp"

namespace dp::visitor {
std::unique_ptr<Visitor> make_html_exporter();
std::unique_ptr<Visitor> make_json_exporter();
std::unique_ptr<Counter> make_word_counter();
}  // namespace dp::visitor
