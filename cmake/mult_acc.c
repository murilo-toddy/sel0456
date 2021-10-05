#include "mult_acc.h"

static int x = 2;

void mult_set_x(int _x) {
  x = _x;
}

int mult_acc(int y) {
  static int z = 2;
  char a[512];
  x += z + x * y;
  z += x;

  return x;
}
