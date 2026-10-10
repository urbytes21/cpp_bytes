#include "chain_of_responsibility/HandlerFactory.hpp"
#include "chain_of_responsibility/Request.hpp"

#include "lab/Example.h"
#include "lab/Logger.h"

using namespace dp::chain_of_responsibility;

LAB_EXAMPLE("ChainOfResponsibility",
            "pass a request along handlers that handle, forward or stop it") {
  LOG_SECTION("Building the chain: auth -> log -> GET -> POST");

  auto auth = make_authentication_handler();
  auto logging = make_logging_handler();
  auto get = make_method_handler("GET");
  auto post = make_method_handler("POST");
  auth->set_next(*logging).set_next(*get).set_next(*post);

  const auto send = [&auth](const Request& request) {
    LOG_S("client sends " << request.method << ' ' << request.path);
    auth->handle(request);  // the client only talks to the head of the chain
  };

  send({"GET", "/users/123", "secret"});
  send({"POST", "/login", "secret"});
  send({"DELETE", "/users/123", "secret"});
  send({"GET", "/admin", "wrong"});

  LOG_SECTION("Changing the chain at run time: skip authentication");
  logging->handle({"POST", "/public/feedback", ""});
}
