#ifndef ETD_STACK_H
#define ETD_STACK_H

#include "list.hpp"
#include "lists/linked_list.hpp"

template <class T>
class Stack {
  List<T> & list;
  public:

    Stack(List<T> & list = *(new LinkedList<T>())) : list(list) {};

    virtual ~Stack() {
      delete &this->list;
    }

    size_t length() {
      return this->list.length();
    };

    T pop() {
      T ret = this->list.get(0);
      this->list.del(0);
      return ret;
    };

    T& peek() const {
      return this->list.get(0);
    };

    void push(const T & el) {
      this->list.ins(0, el);
    };
};

#endif
