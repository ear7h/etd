#include <queue.hpp>
#include <lists/array_list.hpp>

#include "test.h"

#define EN 0
#define DE 1
#define PEEK 2
#define LEN 3

struct tc_t {
  int val;
  int op;
};

void testQueue(Queue<int> * s) {
  tc_t tcs[] = {
    {0, LEN},
    {1, EN},
    {1, DE},
    {2, EN},
    {3, EN},
    {2, LEN},
    {2, DE},
    {1, LEN},
    {3, DE},
    {0, LEN},
  };

  tc_t tc;

  for (size_t i = 0; i < sizeof(tcs)/sizeof(tc_t); i++) {
    tc = tcs[i];

    switch (tc.op) {
      case EN:
        s->en(tc.val);
        break;
      case DE:
        TEST( s->de() == tc.val );
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

int main() {
  auto q1 = Queue<int>();
  testQueue(&q1);

  auto q2 = Queue<int>(*(new ArrayList<int>()));
  testQueue(&q2);
}
