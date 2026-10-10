#include "ObjectAdapter.hpp"

#include <utility>

namespace dp::adapter {

ObjectAdapter::ObjectAdapter(std::unique_ptr<Adaptee> adaptee)
    : adaptee_{std::move(adaptee)} {}

void ObjectAdapter::request() {
  adaptee_->specific_request(42);
}

}  // namespace dp::adapter
