#pragma once

#include <string>

namespace dp::adapter {

/// Adaptee: a third-party SDK we cannot change. Different method name,
/// different parameters, amounts in cents and an error code instead of bool
class PayPalSdk {
 public:
  int send_payment(const std::string& email, long amount_cents,
                   const std::string& currency) const;
};

}  // namespace dp::adapter
