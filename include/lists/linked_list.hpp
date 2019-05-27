#ifndef ETD_LINKED_LIST_HPP
#define ETD_LINKED_LIST_HPP

#include <cassert>

#include "../etddef.hpp"
#include "../list.hpp"

using namespace std;
using namespace etd;

namespace etd {

template <class T>
class LinkedList : public List<T> {
private:
    struct Node {
      T val;
      Node * next;
      Node() {
        this->next = nullptr;
      }
      Node(const T& el) {
        this->next = nullptr;
        this->val = el;
      };
      ~Node() {
      };
    };

    Node * head;
    Node * tail;
    size_t len;
    Node & getNode(size_t) const;
  public:
    LinkedList() {
      Node * root = new Node();
      this->head = root;
      this->tail = root;
      this->len = 0;
    };

    ~LinkedList() {
      Node * cursor = this->head;
      Node * cursor1 = cursor->next;
      while (cursor && cursor1) {
        delete cursor;
        cursor = cursor1;
        cursor1 = cursor->next;
      }
      if (cursor) {
        delete cursor;
      }
    };

    size_t length() const;
    void ins(size_t, const T&);
    T& get(size_t) const;
    void set(size_t, const T&);
    void del(size_t);
};

template <class T>
size_t LinkedList<T>::length() const {
  return this->len;
}

template <class T>
typename LinkedList<T>::Node & LinkedList<T>::getNode(size_t i) const {
  assert(i <= this->len);

  Node * cursor = this->head;
  for (size_t j = 0; j < i; j++) {
    cursor = cursor->next;
  }

  return *cursor;
}

template <class T>
T& LinkedList<T>::get(size_t i) const {
  if (i + 1 == this->len) {
    return this->tail->val;
  }
  return this->getNode(i).next->val;
}

template <class T>
void LinkedList<T>::set(size_t i, const T& el) {
  if (i + 1 == this->len) {
    this->tail->val = el;
  }
  this->getNode(i).next->val = el;
}

template <class T>
void LinkedList<T>::ins(size_t i, const T& el) {
  if (i == this->len) {
    this->tail = this->tail->next = new Node(el);
    this->len++;
    return;
  }

  Node& node = this->getNode(i);
  Node * node1 = new Node(el);
  node1->next = node.next;
  node.next = node1;
  this->len++;
}

template <class T>
void LinkedList<T>::del(size_t i) {
  Node& node = this->getNode(i);
  Node * node1 = node.next;
  node.next = node1->next;
  delete node1;
  this->len--;
}

}

#endif
