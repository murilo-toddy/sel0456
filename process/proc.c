#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(void) {
  pid_t p;
  printf("Criando o processo\n");
  if ((p = fork()) == 0) {
    execl("/usr/bin/ls", "ls", NULL);
  }
  else {
    printf("Processo pai e o PID do filho é: %d\n", p);
    sleep(20);
  }
  return 0;
}
