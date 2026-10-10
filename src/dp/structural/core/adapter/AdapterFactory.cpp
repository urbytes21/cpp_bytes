#include "adapter/AdapterFactory.hpp"

#include <memory>

#include "Adaptee.hpp"
#include "CardProcessor.hpp"
#include "ClassAdapter.hpp"
#include "ObjectAdapter.hpp"
#include "PayPalAdapter.hpp"

namespace dp::adapter {

std::unique_ptr<Target> make_object_adapter() {
  return std::make_unique<ObjectAdapter>(std::make_unique<Adaptee>());
}

std::unique_ptr<Target> make_class_adapter() {
  return std::make_unique<ClassAdapter>();
}

std::unique_ptr<PaymentProcessor> make_card_processor() {
  return std::make_unique<CardProcessor>();
}

std::unique_ptr<PaymentProcessor> make_paypal_adapter() {
  return std::make_unique<PayPalAdapter>();
}

}  // namespace dp::adapter
