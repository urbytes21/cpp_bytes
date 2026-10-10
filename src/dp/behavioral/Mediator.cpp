#include "mediator/Aircraft.hpp"
#include "mediator/ControlTowerFactory.hpp"

#include "lab/Example.h"
#include "lab/Logger.h"

using namespace dp::mediator;

LAB_EXAMPLE("Mediator",
            "components coordinate through a mediator instead of each other") {
  LOG_SECTION("Three aircraft, one runway, coordinated by the tower");

  auto tower = make_tower();
  Aircraft alpha{"VN-101", *tower};
  Aircraft bravo{"SQ-202", *tower};
  Aircraft charlie{"JL-303", *tower};

  alpha.request_landing();
  bravo.request_landing();
  charlie.request_landing();
  charlie.land();  // not cleared yet

  alpha.land();  // the tower now clears bravo
  bravo.land();  // ...then charlie
  charlie.land();
}
