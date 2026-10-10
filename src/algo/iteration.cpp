#include "lab/Example.h"
#include "lab/Logger.h"

namespace {

/// O(n)
int for_loop(const int n) {
  int r = 0;
  for (int i = 0; i <= n; ++i) {
    r += i;
  }

  return r;
}

/// O(n-1)
int while_loop(const int n) {
  int r = 0;
  int s = 0;
  while (s <= n) {
    r += s;
    s++;
  }

  return r;
}

/// O(n^2)
std::string nested_loop(const int n) {
  std::ostringstream res;
  // Loop i = 1, 2, ..., n-1, n
  for (int i = 1; i <= n; ++i) {

    // Loop j = 1, 2, ..., n-1, n
    for (int j = 1; j <= n; ++j) {
      res << "(" << i << ", " << j << "), ";
    }
  }
  return res.str();
}

}  // namespace

LAB_EXAMPLE("Iteration", "") {
  LOG_S("sum 0 -> 100 = " << for_loop(10));
  LOG_S("sum 0 -> 100 = " << while_loop(10));
  LOG_S("Traversal " << nested_loop(4));
}