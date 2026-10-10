#include <string>

#include "adapter/AdapterFactory.hpp"
#include "adapter/PaymentProcessor.hpp"
#include "adapter/Target.hpp"

#include "lab/Example.h"
#include "lab/Logger.h"

using namespace dp::adapter;

namespace {

void client_code(Target& target) {
  LOG("  client calls request()");
  target.request();
}

void checkout(PaymentProcessor& processor, const std::string& customer,
              double amount) {
  const bool ok = processor.pay(customer, amount);  // unchanged client code
  LOG_S("  checkout for " << customer << ": " << (ok ? "paid" : "failed"));
}

void basic() {
  LOG_SECTION("Object adapter and class adapter");

  auto object_adapter = make_object_adapter();
  client_code(*object_adapter);

  auto class_adapter = make_class_adapter();
  client_code(*class_adapter);
}

void payments() {
  LOG_SECTION("Case study: plugging a third-party SDK into existing code");

  auto card = make_card_processor();
  auto paypal = make_paypal_adapter();
  checkout(*card, "alice", 19.99);
  checkout(*paypal, "bob", 42.50);
}

}  // namespace

LAB_EXAMPLE("Adapter",
            "make an incompatible class fit the interface the client expects") {
  basic();
  payments();
}
