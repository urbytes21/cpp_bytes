#include "HtmlExporter.hpp"

#include "lab/Logger.h"

namespace dp::visitor {

void HtmlExporter::visit(const Paragraph& paragraph) {
  LOG_S("    <p>" << paragraph.text() << "</p>");
}

void HtmlExporter::visit(const Image& image) {
  LOG_S("    <img src=\"" << image.path() << "\"/>");
}

void HtmlExporter::visit(const Table& table) {
  LOG_S("    <table rows=\"" << table.rows() << "\" cols=\"" << table.columns()
                             << "\"/>");
}

}  // namespace dp::visitor
