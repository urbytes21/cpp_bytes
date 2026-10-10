#pragma once

#include <memory>
#include <string>

#include "prototype/Extension.hpp"

namespace dp::prototype {

/// Concrete prototype: clone() uses the (deep-copying) copy constructor
class AnalyticsExtension : public Extension {
 public:
  AnalyticsExtension(int sampling_rate, std::string endpoint);

  std::unique_ptr<Extension> clone() const override;
  std::string describe() const override;

 private:
  int sampling_rate_;
  std::string endpoint_;
};

}  // namespace dp::prototype
