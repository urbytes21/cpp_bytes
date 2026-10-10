#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include "lab/Example.h"
#include "lab/Logger.h"

namespace {
struct TreeNode {
  int value;
  TreeNode* left{};
  TreeNode* right{};
  explicit TreeNode(int v) : value(v) {}
};

/// @brief reverse inorder_traverse
void print_tree(const TreeNode* node, int depth = 0) {
  if (node == nullptr) {
    return;
  }

  print_tree(node->right, depth + 1);  // 1. right first

  LOG_S(std::string(depth * 4, ' ') << node->value);  // 2. print node

  print_tree(node->left, depth + 1);  // 3. then left
}

void postorder_traverse(const TreeNode* root,
                        std::vector<const TreeNode*>& arr) {
  if (root == nullptr) {
    return;
  }

  postorder_traverse(root->left, arr);
  postorder_traverse(root->right, arr);

  arr.push_back(root);
}

void pretorder_traverse(const TreeNode* root,
                        std::vector<const TreeNode*>& arr) {
  if (root == nullptr) {
    return;
  }

  arr.push_back(root);

  pretorder_traverse(root->left, arr);
  pretorder_traverse(root->right, arr);
}

void inorder_traverse(const TreeNode* root, std::vector<const TreeNode*>& arr) {
  if (root == nullptr) {
    return;
  }
  inorder_traverse(root->left, arr);

  arr.push_back(root);

  inorder_traverse(root->right, arr);
}

// Inorder Traverse Using Stack
void inorder_traverse_stack(const TreeNode* root,
                            std::vector<const TreeNode*>& arr) {
  if (root == nullptr) {
    return;
  }

  std::stack<const TreeNode*> stack;
  auto push_left = [&](const TreeNode* node) {
    while (node != nullptr) {
      stack.push(node);
      node = node->left;
    }
  };

  push_left(root);
  while (!stack.empty()) {
    const auto* node = stack.top();
    stack.pop();
    arr.push_back(node);
    push_left(node->right);
  }
}

std::vector<const TreeNode*> level_order_traverse(const TreeNode& root) {
  std::queue<const TreeNode*> queue;
  queue.push(&root);

  std::vector<const TreeNode*> array;

  while (!queue.empty()) {
    const auto* node = queue.front();
    queue.pop();

    if (node->left != nullptr) {
      queue.push(node->left);
    }

    if (node->right != nullptr) {
      queue.push(node->right);
    }

    array.push_back(node);
  }

  return array;
}

void bst_insert(TreeNode*& root, int value) {
  if (root == nullptr) {
    root = new TreeNode(value);
    return;
  }

  if (value > root->value) {
    bst_insert(root->right, value);
  } else {
    bst_insert(root->left, value);
  }
}

/// @brief Create a Binary Search Tree
/// @return root noot
TreeNode* create_bst(const std::vector<int>& values) {
  TreeNode* root = nullptr;
  for (const auto& v : values) {
    bst_insert(root, v);
  }

  return root;
}

void clean_bst(TreeNode* node) {
  if (node == nullptr) {
    return;
  }

  clean_bst(node->left);
  clean_bst(node->right);
  delete node;
}

}  // namespace

LAB_EXAMPLE("Tree", "") {
  LOG_SECTION("DST - Tree");

  /**
//       1
//      / \
//     2   3
//    / \   \
//   4   5   6
//      /
//     7
 */
  TreeNode n1(1);
  TreeNode n2(2);
  TreeNode n3(3);
  TreeNode n4(4);
  TreeNode n5(5);
  TreeNode n6(6);
  TreeNode n7(7);

  n1.left = &n2;
  n1.right = &n3;
  n2.left = &n4;
  n2.right = &n5;
  n3.right = &n6;
  n5.left = &n7;

  const TreeNode& root = n1;
  print_tree(&root);

  auto traversal = [](const std::vector<const TreeNode*>& arr,
                      const std::string& title) {
    LOG_S(title);
    std::ostringstream oss;
    for (const auto* v : arr) {
      oss << " " << v->value;
    }
    LOG(oss.view());
  };

  std::vector<const TreeNode*> arr = level_order_traverse(root);
  traversal(arr, "Level Order Travese");
  arr.clear();

  postorder_traverse(&root, arr);
  traversal(arr, "Post Order Travese");
  arr.clear();

  pretorder_traverse(&root, arr);
  traversal(arr, "Pre Order Travese");
  arr.clear();

  inorder_traverse(&root, arr);
  traversal(arr, "In Order Travese");
  arr.clear();

  inorder_traverse_stack(&root, arr);
  traversal(arr, "In Order Travese Using Stack");
  arr.clear();

  auto* bst_root = create_bst({4, 2, 6, 1, 3, 5, 7});
  print_tree(bst_root);
  clean_bst(bst_root);
}