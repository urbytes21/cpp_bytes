#include "builder/HttpRequest.hpp"

#include <stdexcept>
#include <utility>

namespace dp::builder {

std::string HttpRequest::describe() const {
  std::string text = method_ + " " + url_;
  for (const auto& [name, value] : headers_) {
    text += "\n      ";
    text += name;
    text += ": ";
    text += value;
  }

  if (!body_.empty()) {
    text += "\n      body: " + body_;
  }

  return text;
}

HttpRequest::Builder::Builder(std::string url) {
  request_.url_ = std::move(url);
}

HttpRequest::Builder& HttpRequest::Builder::method(std::string method) {
  request_.method_ = std::move(method);
  return *this;
}

HttpRequest::Builder& HttpRequest::Builder::header(std::string name,
                                                   std::string value) {
  request_.headers_[std::move(name)] = std::move(value);
  return *this;
}

HttpRequest::Builder& HttpRequest::Builder::body(std::string body) {
  request_.body_ = std::move(body);
  return *this;
}

HttpRequest HttpRequest::Builder::build() const {
  if (!request_.url_.starts_with("http")) {
    throw std::invalid_argument("URL must start with http: " + request_.url_);
  }

  if (request_.method_ == "GET" && !request_.body_.empty()) {
    throw std::invalid_argument("a GET request must not have a body");
  }

  return request_;
}

}  // namespace dp::builder
