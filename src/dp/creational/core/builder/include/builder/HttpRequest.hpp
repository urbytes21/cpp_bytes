#pragma once

#include <map>
#include <string>

namespace dp::builder {

/// Product of the fluent builder
class HttpRequest {
 public:
  class Builder;

  std::string describe() const;

 private:
  HttpRequest() = default;  // only the Builder can create requests

  std::string method_ = "GET";
  std::string url_;
  std::map<std::string, std::string> headers_;
  std::string body_;
};

/// Fluent builder: each setter returns *this, so calls can be chained
class HttpRequest::Builder {
 public:
  explicit Builder(std::string url);

  Builder& method(std::string method);
  Builder& header(std::string name, std::string value);
  Builder& body(std::string body);

  /// Validates before handing out the product
  HttpRequest build() const;

 private:
  HttpRequest request_;
};

}  // namespace dp::builder
