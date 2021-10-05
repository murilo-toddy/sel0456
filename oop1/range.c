#include <stdlib.h>
#include <stdio.h>

#include "range.h"

typedef struct _range _range_t;

/* método */
void range_init(range_t * _self, int min, int max) {
  _range_t * self = (_range_t *) _self;
  if (max < min) {
    self->min = max;
    self->max = min;
  }
  else if (max == min) {
    self->max = max + 1;
    self->min = min;
  }
  else {
    self->min = min;
    self->max = max;
  }
  self->val = min;
}

/* método construtor */
range_t * range_new(int min, int max) {
  range_t * self = (range_t *) malloc(sizeof(_range_t));
  range_init(self, min, max);
  return self;
}

/* método destrutor */
void range_destroy(range_t * self) {
  free(self);
}

/* método */
void range_inc(range_t * _self, int step) {
  _range_t * self = (_range_t *) _self;
  self->val += step;
  if (self->val >= self->max) {
    self->val = self->max - 1;
  }
}

/* método para representação do objeto */
void range_repr(range_t * _self, FILE * stream) {
  _range_t * self = (_range_t *) _self;
  fprintf(stream, "range_t: [%d,%d[ = %d\n", self->min, self->max, self->val);
}

/* Ajustar o valor do objeto */
void range_set(range_t * _self, int val) {
  _range_t * self = (_range_t *) _self;
  if (val >= self->max)
    val = self->max - 1;
  else if (val < self->min)
    val = self->min;
  self->val = val;
}
