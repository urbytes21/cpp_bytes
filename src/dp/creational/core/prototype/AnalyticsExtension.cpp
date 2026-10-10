#include "prototype/AnalyticsExtension.hpp"

#include <utility>

namespace dp::prototype {

AnalyticsExtension::AnalyticsExtension(int sampling_rate, std::string endpoint)
    : sampling_rate_{sampling_rate}, endpoint_{std::move(endpoint)} {}

std::unique_ptr<Extension> AnalyticsExtension::clone() const {
  return std::make_unique<AnalyticsExtension>(*this);
}

std::string AnalyticsExtension::describe() const {
  return "analytics, sampling " + std::to_string(sampling_rate_) + " Hz to " +
         endpoint_;
}

}  // namespace dp::prototype
