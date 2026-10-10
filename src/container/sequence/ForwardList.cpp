// -----------------------------------------------------------------------------
// std::forward_list (C++11) - single linked list
// -----------------------------------------------------------------------------

#include "lab/Example.h"
#include "lab/Logger.h"

#include <forward_list>
#include <string>
#include <string_view>

namespace {

using List = std::forward_list<std::string_view>;

// Takes the list by const reference (no copy) and logs it as one line.
void print_out(std::string_view title, const List& fl) {
  std::string line{title};
  line += ":";
  for (const auto& n : fl) {
    line += ' ';
    line += n;
  }
  LOG(line);
}

void outline() {
  List fl{"1", "2", "3"};
  print_out("initial", fl);

  fl.assign({"1", "2", "3", "4", "5"});

  // O(1) insertion at the front
  fl.emplace_front("4");
  print_out("emplace_front(4)", fl);

  // Singly linked: all positional operations work "after" an iterator.
  // before_begin() is a sentinel that allows inserting/erasing at the head.
  fl.insert_after(fl.before_begin(), "0");
  print_out("insert_after(before_begin, 0)", fl);

  auto it = fl.begin();            // -> "0"
  it = fl.emplace_after(it, "x");  // inserts after "0", returns new element
  print_out("emplace_after(begin, x)", fl);

  fl.erase_after(it);  // erases the element after "x" (that's "4")
  print_out("erase_after(x)", fl);

  // Remove by value / by predicate
  fl.remove("1");
  print_out("remove(1)", fl);

  fl.remove_if([](std::string_view s) { return s == "x"; });
  print_out("remove_if(x)", fl);

  // Whole-list algorithms are members (no random access, so std::sort
  // cannot be used)
  fl.sort();
  print_out("sort()", fl);

  fl.reverse();
  print_out("reverse()", fl);

  // splice_after moves nodes between lists without copying
  List other{"a", "b"};
  fl.splice_after(fl.before_begin(), other);
  print_out("splice_after(before_begin, other)", fl);
  print_out("other (now empty)", other);
}

}  // namespace

LAB_EXAMPLE("ForwardList",
            "std::forward_list: a singly linked list with before_begin and "
            "insert_after") {
  outline();
}