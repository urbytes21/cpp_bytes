#pragma once

namespace dp::template_method {

/// Abstract class with the template method
class Beverage {
 public:
  virtual ~Beverage() = default;

  /// The template method: fixed order, cannot be overridden
  void prepare() const;

 private:
  // Fixed steps
  void boilWater() const;
  void pourInCup() const;

  // Abstract steps: subclasses must provide them
  virtual void brew() const = 0;
  virtual void addCondiments() const = 0;

  // Hook: optional customization point with a default
  virtual bool wantsCondiments() const { return true; }
};

}  // namespace dp::template_method
