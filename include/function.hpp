#ifndef ETD_FUNCTION_H
#define ETD_FUNCTION_H

#include <cassert>

namespace etd {

// https://shaharmike.com/cpp/naive-std-function/
// I simultaneously do and do not understand what is happening here
template <class>
class Function;

template <class R, class ...Args>
class Function <R(Args...)> {
  class Callable {
  public:
    virtual ~Callable() = default;
    virtual R call(Args...) = 0;
  };

  template <class T>
  class CallableT : public Callable {
    T cble;
  public:
    CallableT(const T& cble) : cble(cble) {};
    ~CallableT() = default;

    R call(Args... args) {
      return this->cble(args...);
    };
  };

  Callable * func;
public:
  Function() : func(0) {};
  virtual ~Function() {
    if (this->func) {
      delete this->func;
    }
  }

  Function& operator= (const Function&) {
    assert( 0 && "don't do this yet, we need shared pointers" );
    return *this;
  }

  template <class T>
  Function& operator= (const T fn) {
    if (this->func) {
      delete this->func;
    }
    this->func = new CallableT<T>(fn);
    return *this;
  }

  R operator()(Args... args) const {
    assert(this->func);
    return this->func->call(args...);
  };
};

}

#endif
