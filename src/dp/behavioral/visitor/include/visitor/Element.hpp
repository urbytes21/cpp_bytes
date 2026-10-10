#pragma once

#include <string>

namespace dp::visitor {

class Visitor;

/// Element interface.
class Element {
 public:
  virtual ~Element() = default;
  virtual void accept(Visitor& visitor) const = 0;
};

class Paragraph : public Element {
 public:
  explicit Paragraph(std::string text);
  const std::string& text() const;
  void accept(Visitor& visitor) const override;

 private:
  std::string text_;
};

class Image : public Element {
 public:
  explicit Image(std::string path);
  const std::string& path() const;
  void accept(Visitor& visitor) const override;

 private:
  std::string path_;
};

class Table : public Element {
 public:
  Table(int rows, int columns);
  int rows() const;
  int columns() const;
  void accept(Visitor& visitor) const override;

 private:
  int rows_;
  int columns_;
};

}  // namespace dp::visitor
