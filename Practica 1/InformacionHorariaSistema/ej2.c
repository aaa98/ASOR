#include <time.h>
#include <errno.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
	time_t tiempo = time(NULL);
	printf("Seconds since 1/1/1970 00:00:00 UTC: %li\n", tiempo);
	return 0;
}
