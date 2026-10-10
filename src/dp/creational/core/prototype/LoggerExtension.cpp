#include "prototype/LoggerExtension.hpp"

#include <utility>

namespace dp::prototype {

LoggerExtension::LoggerExtension(std::string level)
    : level_{std::move(level)} {}

std::unique_ptr<Extension> LoggerExtension::clone() const {
  return std::make_unique<LoggerExtension>(*this);
}

std::string LoggerExtension::describe() const {
  return "logger, level " + level_;
}

void LoggerExtension::set_level(std::string level) {
  level_ = std::move(level);
}

}  // namespace dp::prototype
