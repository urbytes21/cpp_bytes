#include <string>

#include "facade/BackendFactory.hpp"
#include "facade/RequestFacade.hpp"
#include "facade/Subsystem.hpp"

#include "lab/Example.h"
#include "lab/Logger.h"

using namespace dp::facade;

namespace {

void problem() {
  LOG_SECTION("Problem: every client orchestrates the subsystem itself");

  const Validator validator;
  const Authenticator authenticator;
  const AuditLog log;
  const Backend backend;

  const std::string payload = R"({"order": 42})";
  if (validator.check(payload) &&
      authenticator.login("alice")) {  // must know the order...
    log.write("alice sends an order");
    backend.send(payload);  // ...and every step
  }
}

void with_facade() {
  LOG_SECTION("Facade: clients call one simple method");

  const RequestFacade facade;

  LOG_S("  result: " << std::boolalpha
                     << facade.send("alice", R"({"order": 42})"));
  LOG_S("  result: " << std::boolalpha
                     << facade.send("guest", R"({"order": 43})"));
  LOG_S("  result: " << std::boolalpha << facade.send("alice", ""));

  LOG_SECTION("Injecting a fake subsystem for testing");
  const RequestFacade test_facade{make_fake_backend()};
  test_facade.send("tester", R"({"order": "test"})");
}

}  // namespace

LAB_EXAMPLE("Facade",
            "one simple entry point in front of a complex subsystem") {
  problem();
  with_facade();
}
