#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define SSIZE 1024

int main (void) {
  FILE *in;
  size_t n = SSIZE;
  char * s = malloc(n);
  int r;

  in = popen("ls -la", "r");
  if (!in) {
    fprintf (stderr, "incorrect parameters or too many files.\n");
    return EXIT_FAILURE;
  }
  while ((r = getline(&s, &n, in)) > 0) {
    printf("%s", s);
  }
  free(s);
  return EXIT_SUCCESS;
}
