#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

#include "sqr.h"
#include "mult_acc.h"

double x = 9;

sem_t sem;

void * conta_a_toa(void * ptr) {
  /* volatile unsigned int i; */
  register int j;
  int n = *(int *)ptr;
  printf("Na thread no. %d\n", n);
  /* for(i=0; i < 0xffffffff ;i++); */
  sleep(3);
  sem_wait(&sem);
  printf("Thread no. %d entrando em código crítico\n", n);
  sleep(1);
  /* acessando recursos exclusivos */
  printf("Saindo do código crítico e finalizando a thread no. %d\n", n);
  sem_post(&sem);
  if (n == 3)
    sleep(20);
  pthread_exit(NULL);
  return NULL;
}

int main(void) {
  double y;
  int z;

  pthread_t thr1, thr2, thr3;

  sem_init(&sem, 0, 2);

#ifdef OPTION2
  y = 2;
#else
  x = 1.4142;
#endif
  int n1 = 1;
  int r = pthread_create(&thr1, NULL, conta_a_toa, &n1);
  if (r == 0) {
    printf("Ok criando a thread no. %d\n", n1);
  }
  else {
    perror("criando a thread");
    exit(1);
  }
  int n2 = 2;
  r = pthread_create(&thr2, NULL, conta_a_toa, &n2);
  if (r == 0) {
    printf("Ok criando a thread no. %d\n", n2);
  }
  else {
    perror("criando a thread");
    exit(1);
  }
  int n3 = 3;
  r = pthread_create(&thr3, NULL, conta_a_toa, &n3);
  if (r == 0) {
    printf("Ok criando a thread no. %d\n", n3);
  }
  else {
    perror("criando a thread");
    exit(1);
  }
  printf("O quadrado de %g é %g\n", y, sqr(y));
  /* inicializar x no módulo mult_acc */
  mult_set_x(1);
  z = mult_acc(2);
  printf("multacc=%d\n", z);
  z = mult_acc(4);
  printf("multacc=%d\n", z);

  /* volatile unsigned int i; */
  /* for(i=0; i < 0xffffffff ;i++); */


  sleep(2);

  printf("conta finalizou na main\n");

  pthread_join(thr1, NULL);
  pthread_join(thr2, NULL);
  pthread_join(thr3, NULL);
  return 0;
}
