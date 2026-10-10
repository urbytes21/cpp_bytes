
#include <string>

using namespace std;

struct Pair {
  int key;
  string value;
  Pair(int k, string& v) : key(k), value(v){};
};

class ArrayHashMap {
 private:
  vector<Pair*> buckets;

 public:
  ArrayHashMap() : buckets(vector<Pair*>(100)) {}

  ~ArrayHashMap() {
    // Free memory
    for (const auto& bucket : buckets) {
      delete bucket;
    }
    buckets.clear();
  }

  /* Hash function */
  int hashFunc(int key) {
    int index = key % 100;
    return index;
  }

  /* Query operation */
  string get(int key) {
    int index = hashFunc(key);
    const Pair* pair = buckets[index];
    if (pair == nullptr)
      return "";
    return pair->val;
  }

  /* Add operation */
  void put(int key, string val) {
    Pair* pair = new Pair(key, val);
    int index = hashFunc(key);
    buckets[index] = pair;
  }

  /* Remove operation */
  void remove(int key) {
    int index = hashFunc(key);
    // Free memory and set to nullptr
    delete buckets[index];
    buckets[index] = nullptr;
  }

  /* Get all key-value pairs */
  vector<Pair*> pairSet() {
    vector<Pair*> pairSet;
    for (Pair* pair : buckets) {
      if (pair != nullptr) {
        pairSet.push_back(pair);
      }
    }
    return pairSet;
  }

  /* Get all keys */
  vector<int> keySet() {
    vector<int> keySet;
    for (Pair* pair : buckets) {
      if (pair != nullptr) {
        keySet.push_back(pair->key);
      }
    }
    return keySet;
  }

  /* Get all values */
  vector<string> valueSet() {
    vector<string> valueSet;
    for (Pair* pair : buckets) {
      if (pair != nullptr) {
        valueSet.push_back(pair->val);
      }
    }
    return valueSet;
  }

  /* Print hash table */
  void print() {
    for (const auto* kv : pairSet()) {
      cout << kv->key << " -> " << kv->val << endl;
    }
  }
};
