#ifndef ETD_ARRAY_LIST_HPP
#define ETD_ARRAY_LIST_HPP

#include <cassert>

#include "../etddef.hpp"
#include "../list.hpp"

namespace etd {

template <class T>
class ArrayList : public List<T> {
private:
	size_t cap;
	size_t len;
	T *arr;

	inline void expand() {
		size_t cap = (this->len + 1) * 2;
		T *arr = new T[cap];
		for (size_t i = 0; i < this->len; i++) {
			arr[i] = this->arr[i];
		}
    delete[] this->arr;
		this->arr = arr;
		this->cap = cap;
	};

public:
	ArrayList(size_t len = 0, size_t cap = 0) {
		if (cap == 0) {
			this->cap = (len + 1) * 2;
		} else {
			this->cap = len > cap ? len : cap;
		}

		this->len = len;
		this->arr = new T[this->cap];
	};

	~ArrayList() {
		delete[] this->arr;
	};

	size_t length() const;
	void ins(size_t i, const T &el);
	T &get(size_t i) const;
	void set(size_t i, const T &el);
	void del(size_t i);
};

template <class T>
size_t ArrayList<T>::length() const {
	return this->len;
}


template <class T>
void ArrayList<T>::ins(size_t i, const T &el) {
  assert(i <= this->len);
	if (this->len >= this->cap) {
		this->expand();
	}

	for (size_t j = this->len++; j > i; j--) {
		this->arr[j] = this->arr[j - 1];
	}

	this->arr[i] = el;
}

template <class T>
T &ArrayList<T>::get(size_t i) const {
  assert(i < this->len);
	return this->arr[i];
}

template <class T>
void ArrayList<T>::set(size_t i, const T &el) {
  assert(i < this->len);
	this->arr[i] = el;
}

template <class T>
void ArrayList<T>::del(size_t i) {
  assert(i < this->len);
	size_t len = --this->len;
	for (; i < len; i++) {
		this->arr[i] = this->arr[i + 1];
	}
}

} // namespace etd

#endif
