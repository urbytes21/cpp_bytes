// #include "lab/Example.h"
// #include "lab/Logger.h"

// namespace {
// const int kModulus = 1000000007;

// int additive_hash(std::string key) {
//   long long hash = 0;
//   for (unsigned char c : key) {
//     hash = (hash + static_cast<int>(c)) % kModulus;
//   }
//   return static_cast<int>(hash);
// }

// int multiplicative_hash(std::string key) {
//   long long hash = 0;
//   for (unsigned char c : key) {
//     hash = (31 * hash + static_cast<int>(c)) % kModulus;
//   }
//   return static_cast<int>(hash);
// }

// int xor_hash(std::string key) {
//   int hash = 0;
//   for (unsigned char c : key) {
//     hash ^= static_cast<int>(c);
//   }
//   return hash & kModulus;
// }

// int rotational_hash(std::string key) {
//   long long hash = 0;
//   for (unsigned char c : key) {
//     hash = ((hash << 4) ^ (hash >> 28) ^ static_cast<int>(c)) % kModulus;
//   }
//   return static_cast<int>(hash);
// }

// void basics_bash() {
//   LOG_SECTION("Basics");
//   const std::string key = "000";
//   LOG_S("additive_hash(\"000\") = " << additive_hash(key));
//   LOG_S("multiplicative_hash(\"000\") = " << multiplicative_hash(key));
//   LOG_S("xor_hash(\"000\") = " << xor_hash(key));
//   LOG_S("rotational_hash(\"000\") = " << rotational_hash(key));
// }

// }  // namespace

// LAB_EXAMPLE("Hash Algorithm", "Hash") {
//   basics_bash();
// }
