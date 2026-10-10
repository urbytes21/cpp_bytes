#pragma once

#include <string>

namespace dp::facade {

class Validator {
 public:
  bool check(const std::string& payload) const;
};

class Authenticator {
 public:
  bool login(const std::string& user) const;
};

class AuditLog {
 public:
  void write(const std::string& entry) const;
};

class Backend {
 public:
  virtual ~Backend() = default;

  virtual void send(const std::string& payload) const;
};

}  // namespace dp::facade
