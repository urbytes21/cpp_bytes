#include "PayPalAdapter.hpp"

#include <cmath>

namespace dp::adapter {

bool PayPalAdapter::pay(const std::string& customer, double amount_eur) {
  const std::string email =
      customer + "@example.com";  // look up the PayPal account
  const auto cents = std::lround(amount_eur * 100.0);

  return sdk_.send_payment(email, cents, "EUR") == 0;
}

}  // namespace dp::adapter
