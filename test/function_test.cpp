#include <iostream>
#include <function.hpp>

#include "test.h"

using namespace std;
using namespace etd;


void myPrint() {
  cout << "in myPrint" << endl;
}

void myPrint2() {
  cout << "in myPrint2" << endl;
}

int retFive() {
  cout << "in retFive" << endl;
  return 5;
}

int retPlusOne(int n) {
  cout << "in retPlusOne" << endl;
  return n + 1;
}

int main() {
  Function<void ()> f1;
  f1 = myPrint;
  f1();
  f1 = myPrint2;
  f1();
  f1 = [](){cout << "in lambda" << endl;};
  f1();

  Function<int ()> f2;
  f2 = retFive;
  TEST( f2() == 5 );

  Function<int (int)> f3;
  f3 = retPlusOne;
  Function<int (int)> f4;
  f4 = retPlusOne;
  TEST( f3(1) == 2 );
  TEST( f4(1) == 2 );
  TEST( f3(f3(1)) == 3 );
  TEST( f4(f4(1)) == 3 );

  return 0;
}
