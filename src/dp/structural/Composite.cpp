#include "composite/File.hpp"
#include "composite/Folder.hpp"
#include "composite/Node.hpp"
#include "composite/Shortcut.hpp"

#include "lab/Example.h"
#include "lab/Logger.h"

using namespace dp::composite;

namespace {

/// Client code: works with any Node
void report(const Node& node) {
  LOG_S("  " << node.name() << " uses " << node.size_bytes() << " bytes");
}

}  // namespace

LAB_EXAMPLE("Composite",
            "tree structures where leaves and groups share one interface") {
  LOG_SECTION("Building a tree");

  Folder root{"root"};
  root.add<File>("readme.md", 1200);
  Folder& src = root.add<Folder>("src");
  src.add<File>("main.cpp", 5400);
  Folder& lab = src.add<Folder>("lab");
  lab.add<File>("Registry.cpp", 4100);
  lab.add<File>("Menu.cpp", 6300);
  root.add<Shortcut>("latest-log", "/var/log/cpplab.log");
  root.print(1);

  LOG_SECTION("The client treats leaves and composites alike");
  report(root);
  report(src);
  report(lab);

  LOG_SECTION("Removing a subtree");
  src.remove("lab");  // unique_ptr frees the whole subtree
  root.print(1);
}
