#pragma once

#include <iosfwd>

#include "Registry.h"

namespace lab {
void runMenu(const Registry& registry, std::istream& in, std::ostream& out);
}  // namespace lab
