#pragma once

#include <memory>

#include "Adaptee.hpp"
#include "adapter/Target.hpp"

namespace dp::adapter {

/// Object adapter: HAS an adaptee (composition, preferred)
class ObjectAdapter : public Target {
 public:
  explicit ObjectAdapter(std::unique_ptr<Adaptee> adaptee);

  void request() override;

 private:
  std::unique_ptr<Adaptee> adaptee_;
};

}  // namespace dp::adapter
