// -----------------------------------------------------------------------------
// std::list (C++98) - doubly linked list
// -----------------------------------------------------------------------------

#include "lab/Example.h"
#include "lab/Logger.h"

#include <iterator>
#include <list>
#include <string>
#include <string_view>

namespace {

using List = std::list<std::string_view>;

// Takes the list by const reference (no copy) and logs it as one line.
void print_out(std::string_view title, const List& l) {
  std::string line{title};
  line += ":";
  for (const auto& n : l) {
    line += ' ';
    line += n;
  }
  LOG(line);
}

void outline() {
  List l{"1", "2", "3"};
  print_out("initial", l);

  // O(1) insertion at both ends
  l.emplace_front("0");
  print_out("emplace_front(0)", l);

  l.emplace_back("4");
  print_out("emplace_back(4)", l);

  // Doubly linked: insert goes *before* the iterator, no "after" variants
  auto it = std::next(l.begin(), 2);  // -> "2"
  it = l.insert(it, "x");             // inserts before "2", returns new element
  print_out("insert(before 2, x)", l);

  // Iterators stay valid after insert/erase of other elements
  it = l.erase(it);          // erases "x", returns the next element
  print_out("erase(x)", l);  // `it` now points to "2"

  l.pop_front();
  l.pop_back();
  print_out("pop_front + pop_back", l);

  // Remove by value / by predicate
  l.remove("2");
  print_out("remove(2)", l);

  l.assign({"c", "a", "b", "a"});
  print_out("assign", l);

  // Whole-list algorithms are members (no random access, so std::sort
  // cannot be used)
  l.sort();
  print_out("sort()", l);

  l.unique();  // removes consecutive duplicates
  print_out("unique()", l);

  l.reverse();
  print_out("reverse()", l);

  // splice moves nodes between lists without copying
  List other{"y", "z"};
  l.splice(l.begin(), other);
  print_out("splice(begin, other)", l);
  print_out("other (now empty)", other);

  // merge combines two *sorted* lists into one sorted list
  List a{"1", "3", "5"};
  List b{"2", "4"};
  a.merge(b);
  print_out("merge", a);
}

}  // namespace

LAB_EXAMPLE("List",
            "std::list: a doubly linked list with O(1) insert/erase anywhere, "
            "splice and merge") {
  outline();
}