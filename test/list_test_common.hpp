#include <iostream>
#include <cassert>

#include <list.hpp>

using namespace std;
using namespace etd;

void TestAppends(List<int>& list) {
	for (int i = 0; i < 4; i++) {
		list.ins(list.length() , i);
	}

	for (int i = 0; i < 5; i++) {
		list.ins(list.length(), i*10);
	}

	for (int i = 0; i < 4; i++) {
		assert(list.get(i) == i);
	}

	for (int i = 0; i < 5; i++) {
		assert(list.get(i+4) == i*10);
	}

	assert(list.length() == 9);
}


void TestPreppends(List<int>& list) {
	for (int i = 0; i < 4; i++) {
		list.ins(0, i);
	}

	for (int i = 0; i < 5; i++) {
		list.ins(0, i*10);
	}

	for (int i = 0; i < 4; i++) {
		assert(list.get(8-i) == i);
	}

	for (int i = 0; i < 5; i++) {
		assert(list.get(i) == (4-i)*10);
	}

	assert(list.length() == 9);
}

void TestDel1(List<int>& list) {
	for (int i = 0; i < 100; i++) {
		list.ins(list.length(), i);
	}

	for (int i = 0; i < 100; i++) {
		list.del(0);
	}

	assert(list.length() == 0);
}


void TestDel2(List<int>& list) {
	for (int i = 0; i < 100; i++) {
		list.ins(list.length(), i);
	}

	assert(list.length() == 100);

	for (int i = 0; i < 50; i++) {
		list.del(i);
	}

	for (int i = 0; i < 50; i++) {
		assert(list.get(i) == i*2+1);
	}
}

template <class LIST>
void ListTestAll() {

  LIST l1 = LIST();
  TestAppends(l1);
	cout << "PASS TestAppends1" << endl;


  LIST l3 = LIST();
	TestPreppends(l3);
	cout << "PASS TestPrepends" << endl;

  LIST l5 = LIST();
	TestDel1(l5);
	cout << "PASS TestDel1" << endl;

  LIST l6 = LIST();
	TestDel2(l6);
	cout << "PASS TestDel2" << endl;
}
