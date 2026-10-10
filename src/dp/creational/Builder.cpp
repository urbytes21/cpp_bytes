#include <stdexcept>

#include "builder/Director.hpp"
#include "builder/HouseBuilderFactory.hpp"
#include "builder/HttpRequest.hpp"

#include "lab/Example.h"
#include "lab/Logger.h"

using namespace dp::builder;

namespace {

void classic() {
  LOG_SECTION("Director + builders: same steps, different representations");

  auto wood = make_wooden_house_builder();
  auto stone = make_stone_house_builder();

  Director::build_minimal(*wood);
  LOG_S("  minimal wooden house: " << wood->result()->describe());

  Director::build_luxury(*wood);  // the builder was reset by result()
  LOG_S("  luxury wooden house : " << wood->result()->describe());

  Director::build_luxury(*stone);
  LOG_S("  luxury stone house  : " << stone->result()->describe());

  stone->build_walls();  // clients can also drive a builder without a director
  stone->build_pool();
  LOG_S("  custom stone house  : " << stone->result()->describe());
}

void fluent() {
  LOG_SECTION("Fluent builder with validation");

  const HttpRequest request =
      HttpRequest::Builder("https://api.example.com/users")
          .method("POST")
          .header("Content-Type", "application/json")
          .header("Authorization", "Bearer token")
          .body(R"({"name": "Ada"})")
          .build();

  LOG_S("  " << request.describe());

  try {
    HttpRequest::Builder("https://example.com").body("oops").build();
  } catch (const std::invalid_argument& e) {
    LOG_S("  build() rejected an invalid request: " << e.what());
  }
}

}  // namespace

LAB_EXAMPLE("Builder",
            "step-by-step construction with builders, a director and a fluent "
            "builder") {
  classic();
  fluent();
}
