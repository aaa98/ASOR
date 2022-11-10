
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>

int main(){

  time_t tiempo = time(NULL);
  struct tm *info = localtime(&tiempo);
  int anio = info->tm_year;
  printf("Estamos en el año: %i\n", 1900 + anio);
  return 1;
}
