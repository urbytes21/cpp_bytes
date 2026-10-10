

#include <utility>
#include <vector>

size_t left_idx(const size_t i) {
  return 2 * i + 1;
}

size_t right_idx(const size_t i) {
  return 2 * i + 2;
}

int parent_idx(const size_t i) {
  return (i - 1) / 2;
}

enum class Type { kMin = 0, kMax };

int main() {

  /// Go from idx to down
  auto sift_down = [](auto& list, int i, Type type = Type::kMax) {
    while (true) {
      size_t max_idx = i;
      size_t l_idx = left_idx(i);
      size_t r_idx = right_idx(i);

      switch (type) {
        case Type::kMax: {
          if (l_idx < list.size() && list[l_idx] >= list[max_idx]) {
            max_idx = l_idx;
          }

          if (r_idx < list.size() && list[r_idx] >= list[max_idx]) {
            max_idx = r_idx;
          }

          break;
        }

        case Type::kMin: {
          if (l_idx < list.size() && list[l_idx] <= list[max_idx]) {
            max_idx = l_idx;
          }

          if (r_idx < list.size() && list[r_idx] <= list[max_idx]) {
            max_idx = r_idx;
          }

          break;
        }
      }

      if (max_idx == i) {
        break;
      }

      std::swap(list[max_idx], list[i]);

      i = max_idx;
    }
  };

  auto sift_up = [](auto& list, int i, Type type = Type::kMax) {
    while (true) {
      int p_idx = parent_idx(i);

      if ((p_idx < 0) | (type == Type::kMax && list[p_idx] >= list[i]) |
          (type == Type::kMin && list[p_idx] <= list[i])) {
        break;
      }

      std::swap(list[p_idx], list[i]);

      i = p_idx;
    }
  };

  std::vector<int> list{7, 2, 9, 1, 5, 3, 8};

  /// O(n)
  for (int i = list.size() - 1; i >= 0; --i) {
    sift_down(list, i, Type::kMin);
  }

  /// O(nlogn)
  std::vector<int> list1{7, 2, 9, 1, 5, 3, 8};
  for (int i = 0; i < list1.size(); i++) {
    sift_up(list1, i, Type::kMin);
  }

  return 0;
}