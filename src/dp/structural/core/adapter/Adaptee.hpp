#pragma once

namespace dp::adapter {

/// Adaptee: useful, but with a different interface
class Adaptee {
 public:
  void specific_request(int code) const;
};

}  // namespace dp::adapter
