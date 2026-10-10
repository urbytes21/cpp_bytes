#include "PayPalSdk.hpp"

#include "lab/Logger.h"

namespace dp::adapter {

int PayPalSdk::send_payment(const std::string& email, long amount_cents,
                            const std::string& currency) const {
  LOG_S("    [PayPal SDK] sent " << amount_cents << " cents (" << currency
                                 << ") to " << email);

  return 0;  // 0 = success
}

}  // namespace dp::adapter
