#pragma once

#include "Adaptee.hpp"
#include "adapter/Target.hpp"

namespace dp::adapter {

/// Class adapter: IS implemented in terms of the adaptee (private inheritance)
class ClassAdapter : public Target, private Adaptee {
 public:
  void request() override;
};

}  // namespace dp::adapter
