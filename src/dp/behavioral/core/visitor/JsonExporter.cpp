#include "JsonExporter.hpp"

#include "lab/Logger.h"

namespace dp::visitor {

void JsonExporter::visit(const Paragraph& paragraph) {
  LOG_S(R"(    {"type": "text", "content": ")" << paragraph.text() << "\"}");
}

void JsonExporter::visit(const Image& image) {
  LOG_S(R"(    {"type": "image", "path": ")" << image.path() << "\"}");
}

void JsonExporter::visit(const Table& table) {
  LOG_S(R"(    {"type": "table", "rows": )"
        << table.rows() << ", \"cols\": " << table.columns() << '}');
}

}  // namespace dp::visitor
