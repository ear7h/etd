#ifndef ETD_QUEUE_H
#define ETD_QUEUE_H

#include "list.hpp"
#include "lists/linked_list.hpp"

template <class T>
class Queue {
  List <T> & list;
  public:

  Queue(List<T> & list = *(new LinkedList<T>())) : list(list) {};

  virtual ~Queue() {
    delete &this->list;
  };

  size_t length() {
    return this->list.length();
  }

  void en(T & el) {
    this->list.ins(this->list.length(), el);
  };

  T de() {
    T ret = this->list.get(0);
    this->list.del(0);
    return ret;
  };

  T& peek() const {
    return this->list.get(0);
  }
};

#endif
