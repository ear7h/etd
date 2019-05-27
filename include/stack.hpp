#ifndef ETD_STACK_H
#define ETD_STACK_H

#include "list.hpp"
#include "lists/linked_list.hpp"

template <class T, class L=LinkedList<T>>
class Stack : L {
  public:
    using L::length;

    T pop() {
      T ret = this->get(0);
      this->del(0);
      return ret;
    };

    T& peek() const {
      return this->get(0);
    };

    void push(const T & el) {
      this->ins(0, el);
    };
};

#endif
