#include <stdlib.h>
#include <stdio.h>

#include "range.h"

/* .bss */
range_t r1;

/* /\* .data *\/ */
/* range_t r2 = { */
/*   .min = 10, */
/*   .max = 20, */
/*   .val = 100 */
/* }; */

int main(void) {
  range_t r, * r3;
  r3 = range_new(0, 10);

  range_init(&r, 0, 10);
  range_inc(&r, 1);
  range_inc(&r, 1);
  range_inc(&r, 1);
  range_inc(&r, 1);
  range_inc(&r, 1);
  range_inc(&r, 1);
  range_inc(&r, 1);
  range_inc(&r, 1);
  range_inc(&r, 1);
  range_inc(&r, 1);
  range_inc(&r, 1);
  range_inc(&r, 1);
  range_inc(&r, 1);
  range_inc(&r, 1);
  range_inc(&r, 1);
  range_inc(&r, 1);
  range_inc(&r, 1);

  range_set(&r, 1000);

  range_inc(r3, 100);

  range_repr(&r, stdout);
  range_repr(r3, stdout);

  range_destroy(r3);
  return 0;
}
