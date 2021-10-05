#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(void) {
  pid_t p;
  printf("Criando o processo\n");
  if ((p = fork()) == 0) {
    printf("Filho sleeping\n");
    sleep(10);
    printf("Filho terminou\n");
  }
  else {
    printf("Processo pai e o PID do filho é: %d\n", p);
    sleep(5);
    printf("Pai terminou\n");
  }
  return 0;
}
