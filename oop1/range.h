#ifndef _range_h
#define _range_h

/* Não use essa estrutura diretamente */
struct _range {
  int val;
  int max, min;
};

/*
 * Conta do valor mínimo (min) ao valor máximo (max) => [min,max[, sempre limitado a eles.
 */
struct range {
  /* opaque object */
  char buf[sizeof(struct _range)];
};

typedef struct range range_t;

/* método inicializador */
void range_init(range_t * _self, int min, int max);
/* método construtor */
range_t * range_new(int min, int max);
/* método destrutor */
void range_destroy(range_t * self);
/* método */
void range_inc(range_t * _self, int step);
/* método para representação do objeto */
void range_repr(range_t * _self, FILE * stream);
/* Ajustar o valor do objeto */
void range_set(range_t * _self, int val);

#endif
