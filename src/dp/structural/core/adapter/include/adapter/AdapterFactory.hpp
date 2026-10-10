#pragma once

#include <memory>

#include "adapter/PaymentProcessor.hpp"
#include "adapter/Target.hpp"

namespace dp::adapter {

/// Object adapter: HAS an adaptee
std::unique_ptr<Target> make_object_adapter();

/// Class adapter: IS implemented in terms of the adaptee
std::unique_ptr<Target> make_class_adapter();

std::unique_ptr<PaymentProcessor> make_card_processor();

/// Plugs a third-party PayPal SDK into the checkout
std::unique_ptr<PaymentProcessor> make_paypal_adapter();

}  // namespace dp::adapter
