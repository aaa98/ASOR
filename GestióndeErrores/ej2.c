
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

int main(){
  char *error;
  if (setuid(0) == -1){
	   //perror(error);
     printf("ERROR(%d): %s\n", errno, strerror(errno));
	}
  return 1;
}
