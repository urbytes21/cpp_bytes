#pragma once

#include <string>

#include "PayPalSdk.hpp"
#include "adapter/PaymentProcessor.hpp"

namespace dp::adapter {

/// Adapter: translates the checkout's call into the SDK's call
class PayPalAdapter : public PaymentProcessor {
 public:
  bool pay(const std::string& customer, double amount_eur) override;

 private:
  PayPalSdk sdk_;
};

}  // namespace dp::adapter
