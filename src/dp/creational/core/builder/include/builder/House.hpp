#pragma once

#include <string>
#include <vector>

namespace dp::builder {

/// Product
class House {
 public:
  void add_part(std::string part);
  std::string describe() const;

 private:
  std::vector<std::string> parts_;
};

}  // namespace dp::builder
