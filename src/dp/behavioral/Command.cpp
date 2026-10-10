#include <memory>
#include <utility>
#include <vector>

#include "command/CommandFactory.hpp"
#include "command/Editor.hpp"
#include "command/TextDocument.hpp"

#include "lab/Example.h"
#include "lab/Logger.h"

using namespace dp::command;

LAB_EXAMPLE("Command",
            "requests as objects: execute, undo history and macro commands") {
  TextDocument document;
  Editor editor{document};

  LOG_SECTION("Executing commands");
  editor.run(makeInsertTextCommand(document, "Hello"));
  editor.run(makeInsertTextCommand(document, " World"));
  editor.run(makeClearCommand(document));

  LOG_SECTION("Undo");
  editor.undo();  // restores "Hello World"
  editor.undo();  // removes " World"

  LOG_SECTION("Macro command: one undo step for several commands");
  std::vector<std::unique_ptr<Command>> signature;
  signature.push_back(makeInsertTextCommand(document, "\n--\n"));
  signature.push_back(makeInsertTextCommand(document, "Best regards"));
  editor.run(makeMacroCommand(std::move(signature)));
  editor.undo();
  editor.undo();
  editor.undo();
}
