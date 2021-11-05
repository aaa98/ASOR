
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>

int main(){
  struct timeval tv;
	int rc = gettimeofday(&tv, NULL);
  int comienzo = tv.tv_usec;
  int i;
  for (i = 0; i < 10000; i++);
  //Vuvelve a calcular 
  int rc2 = gettimeofday(&tv, NULL);
  int fin = tv.tv_usec;
  printf("Ha tardado (ms): %i\n", fin - comienzo);
  return 1;
}
