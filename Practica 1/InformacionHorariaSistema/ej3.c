#include <time.h>
#include <errno.h>

#include <stdio.h>
#include <stdlib.h>

int main() {

	time_t tiempo = time(NULL);
	char *date= ctime(&tiempo);
	printf("CTIME: %s\n", date);
	return 0;
}
