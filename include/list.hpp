#ifndef ETD_LIST_HPP
#define ETD_LIST_HPP

#include "etddef.hpp"

using namespace etd;

namespace etd {

  template <class T>
    class List {
      public:
        virtual ~List() {};
        virtual size_t length() const = 0;
        virtual void ins(size_t, const T&) = 0;
        virtual T& get(size_t) const = 0;
        virtual void set(size_t, const T&) = 0;
        virtual void del(size_t) = 0;

        const T& operator[] (const size_t i) const {
          return this->get(i);
        };

        T& operator[] (const size_t i) {
          return this->get(i);
        };
    };

}

#endif
