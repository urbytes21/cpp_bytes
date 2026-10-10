#include <numeric>
#include <string>

#include "iterator/Iterator.hpp"
#include "iterator/ListCollection.hpp"
#include "iterator/Ring.hpp"
#include "iterator/VectorCollection.hpp"

#include "lab/Example.h"
#include "lab/Logger.h"

using namespace dp::iterator;

LAB_EXAMPLE("Iterator",
            "traverse collections without exposing their storage; "
            "begin()/end() in C++") {
  LOG_SECTION("Classic Iterator: one client, two storages");

  auto print_all = [](const char* label,
                      const Aggregate<std::string>& collection) {
    std::string line;

    for (auto it = collection.create_iterator(); it->has_next();) {
      line += it->next() + " ";
    }

    LOG_S("  " << label << line);
  };

  VectorCollection<std::string> vector_names;
  ListCollection<std::string> list_names;
  for (const char* name : {"Ada", "Grace", "Linus"}) {
    vector_names.add(name);
    list_names.add(name);
  }
  print_all("vector-backed: ", vector_names);
  print_all("list-backed:   ", list_names);

  LOG_SECTION("The C++ way: begin()/end() iterators");
  const Ring ring{3};  // starts at the fourth element and wraps around
  std::string line;
  for (const int value : ring) {  // range-based for uses begin() and end()
    line += std::to_string(value) + " ";
  }
  LOG_S("  range-for over Ring(3): " << line);
  LOG_S("  std::accumulate works too: " << std::accumulate(ring.begin(),
                                                           ring.end(), 0));
}
