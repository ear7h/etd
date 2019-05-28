#ifndef ETD_LIST_HPP
#define ETD_LIST_HPP

#include "etddef.hpp"


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

        virtual Iterator<T> iter() const {
        };

        const T& operator[] (const size_t i) const {
          return this->get(i);
        };

        T& operator[] (const size_t i) {
          return this->get(i);
        };
    };

  template <class T>
  T& lsearch(List<T>& list, T el) {
    size_t len = list.length();
    for (size_t i = 0; i < len; i++) {
      if
    }
  }

}

#endif
