#include <string>
#include "lab/Example.h"
#include "lab/Logger.h"

namespace {
/// @brief A Linked List Node
struct Node {
  int value;
  Node* next{};

  explicit Node(int v) : value(v) {}
};

void raw_linkedlist() {
  // Create nodes
  Node head(1);
  Node n1(2);
  Node n2(3);
  Node n3(4);

  // Create references
  head.next = &n1;
  n1.next = &n2;
  n2.next = &n3;
  n3.next = nullptr;

  // Access
  auto traverse = [](Node& head, std::string_view msg) {
    LOG(msg);

    // auto* cur = &head;
    // while (cur != nullptr) {
    //   LOG(std::to_string(cur->value));
    //   cur = cur->next;
    // }
    for (auto* cur = &head; cur != nullptr; cur = cur->next) {
      LOG(std::to_string(cur->value));
    }
  };

  traverse(head, "Initial");

  // Insert
  Node new_node(5);
  n1.next = &new_node;
  new_node.next = &n2;
  traverse(head, "Insert");

  // Remove
  head.next = &n2;
  traverse(head, "Remove");
}

}  // namespace

LAB_EXAMPLE("LinkedList", "") {
  raw_linkedlist();
}