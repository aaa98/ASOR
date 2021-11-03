
#include <stdio.h>
#include <errno.h>
#include <unistd.h>

int main(){
  char *error;
  if (setuid(0) == -1){
	   perror(error);
	}
  return 1;
}
