#include "memento/Editor.hpp"
#include "memento/History.hpp"

#include "lab/Example.h"
#include "lab/Logger.h"

using namespace dp::memento;

LAB_EXAMPLE("Memento",
            "save and restore state (undo) without breaking encapsulation") {
  Editor editor;
  History history{editor};

  LOG_SECTION("Editing and taking snapshots");
  history.backup("empty");
  editor.type("Hello");
  LOG_S("  typed           -> " << editor.show());

  history.backup("after Hello");
  editor.type(" World");
  LOG_S("  typed           -> " << editor.show());

  history.backup("after World");
  editor.moveCursor(5);
  editor.type(",");
  LOG_S("  inserted comma  -> " << editor.show());
  history.list();

  LOG_SECTION("Undo");
  history.undo();
  history.undo();
  history.undo();
  history.undo();
}
