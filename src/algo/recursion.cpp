#include <stack>
#include "lab/Example.h"
#include "lab/Logger.h"

namespace {

/// f(x) = f(x-1) + f(x-2)
/// T/O(2^n) , S/O(n)
int find_fib(int n) {
  // terminal condition
  // f(1) = 0
  // f(2) = 1
  if (n == 1 || n == 2) {
    return n - 1;
  }

  // Recursive call f(n) = f(n-1) + f(n-2)
  int res = find_fib(n - 1) + find_fib(n - 2);

  // Return result f(n)
  return res;
};

/// brief: f(x) = x + f(x-1)
int recursion(int n) {
  // terminate condition
  if (n == 1) {
    return 1;
  }

  // recursive call
  int r = recursion(n - 1);

  // return result
  return n + r;
}

int sim_recursion(int n) {
  std::stack<int> stack;

  if (n == 1) {
    return 1;
  }

  // recursive call
  for (int i = n; i > 0; --i) {
    stack.push(i);
  }

  // return result
  int res = 0;
  while (!stack.empty()) {
    res += stack.top();
    stack.pop();
  }

  return res;
}

int tail_recursion(int n, int sum_so_far) {
  if (n == 0) {
    return sum_so_far;
  }

  return tail_recursion(n - 1, sum_so_far + n);
}
}  // namespace

LAB_EXAMPLE("Recursion", "") {
  LOG_S("sum 0 -> 100 = " << recursion(100));
  LOG_S("sum 0 -> 100 = " << sim_recursion(100));
  LOG_S("sum 0 -> 100 = " << tail_recursion(100, 0));
  LOG_S("fibonacci 10th = " << find_fib(10));
}