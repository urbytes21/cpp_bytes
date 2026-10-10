#pragma once

#include <functional>
#include <string>
#include <vector>

namespace dp::observer {

class Listener;
enum class Event;

/// Subject
class Button {
 public:
  explicit Button(std::string name);

  void attach(Listener& listener);
  void detach(Listener& listener);

  void press();
  void release();

 private:
  void notify(Event event);

  std::string name_;

  ///< container references to listener
  std::vector<std::reference_wrapper<Listener>> listeners_;
};

}  // namespace dp::observer
