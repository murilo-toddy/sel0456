#include <iostream>

#include "Range.hpp"

extern "C" {
#include "../oop1/range.h"
}

using namespace std;

void f1(void) {
  Range2 r2(0, 6, "R2 object");
  r2.repr(cout);
  r2.incVal();
  r2.repr(cout);
  cout << "Val of r2: " << r2.getVal() << endl;
}

int main(void) {
  cout << "Output stream aqui!!\n";

  range_t * rc = range_new(0, 9);
  range_inc(rc, 2);
  range_repr(rc, stdout);
  range_destroy(rc);

  Range r1(0, 10), r3(1, 8);
  f1();
  r1.repr(cout);
  r1.incVal(2);
  r1 += 3;
  r1 += r3;
  r1.repr();
  return 0;
}
