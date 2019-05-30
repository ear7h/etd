#ifndef SHARED_POINTER_H
#define SHARED_POINTER_H

#include "../etddef.hpp"

namespace etd {

template <class T>
class SharedPtr {

  struct refCounter {
    size_t refCount;
    T * ref;

    refCounter(T * ref ) : refCount(1), ref(ref) {};

    ~refCounter() {
      delete ref;
    }

    T * getp() const {
      return this->ref;
    };

    T& getr() const {
      return *this->ref;
    };

    void dec() {
      if (refCount == 1) {
        delete this;
      } else {
        refCount--;
      }
    };

    void inc() {
      refCount++;
    }

  };

protected:
  refCounter * ref;
public:
  SharedPtr(T * ptr) {
    this->ref = new refCounter(ptr);
  };

  SharedPtr(SharedPtr<T> & sptr) {
    this->ref = sptr.ref;
    this->ref->inc();
  };

  ~SharedPtr() {
    this->ref->dec();
  };

  SharedPtr<T>& operator= (SharedPtr<T>& rhs) {
    this->ref->dec();
    this->ref = rhs.ref;
    this->ref->inc();
    return *this;
  };

  SharedPtr<T>& operator= (T * rhs) {
    this->ref->dec();
    this->ref = new refCounter(rhs);
    return *this;
  };

  T * get() const {
    return this->ref->getp();
  };

  T& operator*() const {
    return this->ref->getr();
  };

  T* operator->() const {
    return this->ref->getp();
  };

  explicit operator bool () const {
    return (bool) this->ref->getp();
  };
};

}

#endif
