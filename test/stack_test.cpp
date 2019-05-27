#include <stack.hpp>

#include "test.h"

#define PUSH 0
#define POP 1
#define PEEK 2
#define LEN 3

struct tc_t {
  int val;
  int op;
};

int main() {
  tc_t tcs[] = {
    {1, PUSH},
    {1, LEN},
    {1, POP},
    {0, LEN},
    {2, PUSH},
    {3, PUSH},
    {3, PEEK},
    {2, LEN},
    {3, POP},
    {2, POP},
    {0, LEN},
  };

  Stack<int> * s = new Stack<int>();

  tc_t tc;
  for (size_t i = 0; i < sizeof(tcs) / sizeof(tc_t); i++) {
    tc = tcs[i];

    switch (tc.op) {
      case PUSH:
        s->push(tc.val);
        break;
      case POP:
        TEST( s->pop() == tc.val );
        break;
      case PEEK:
        TEST( s->peek() == tc.val );
        break;
      case LEN:
        TEST( s->length() == (size_t) tc.val );
        break;
    }
  }
}
