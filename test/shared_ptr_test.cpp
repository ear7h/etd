#include <ptr/shared.hpp>

#include "test.h"
void ptrHoldingPtr() {
  int * n1 = new int;
  *n1 = 23;
  etd::SharedPtr<int> ptr1(n1);
  TEST( *n1 == *ptr1 );

  etd::SharedPtr<int> * ptr2 = new etd::SharedPtr<int>(ptr1);
  TEST( *n1 = *ptr2 );
  delete ptr2;

  TEST( *n1 == *ptr1 );
}

void ptrSharing() {
  etd::SharedPtr<int> ptr1(new int);
  *ptr1 = 1;
  TEST( *ptr1 == 1 );
  etd::SharedPtr<int> ptr2(new int);
  *ptr2 = 2;
  TEST( *ptr2 == 2);
  ptr2 = ptr1;
  TEST( *ptr1 == *ptr2 );

  int * x = new int;
  *x = 10;
  ptr1 = ptr2 = x;
  TEST( *ptr1 = *x);
  TEST( *ptr2 = *x);
}


int main() {
  ptrHoldingPtr();
  ptrSharing();
}

