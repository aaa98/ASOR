#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	if (argc != 2) {
    printf("ERROR\n");
    return -1;
  }
  sigset_t set;
  sigemptyset(&set);
  sigaddset(&set, SIGINT);
  sigaddset(&set, SIGTSTP);

  sigprocmask(SIG_BLOCK, &set, NULL);

  char *sleep_secs = getenv("SLEEP_SECS");
  int secs = atoi(sleep_secs);
  printf("El proceso se dormira durante %d segundo(s)\n", secs);
  sleep(secs);

  sigset_t pending;
  sigpending(&pending);

  if (sigismember(&pending, SIGINT) == 1) {
    printf("Se ha recibido la señal SIGINT\n");
    sigdelset(&set, SIGINT);

  } else {
      printf("No se ha recibido la señal\n");
  }
  if (sigismember(&pending, SIGTSTP) == 1) {
    printf("Se ha recibido la señal SIGTSTP\n");

    sigdelset(&set, SIGTSTP);
  } else {
    printf("No se ha recibido la señal\n");
  }

  sigprocmask(SIG_UNBLOCK, &set, NULL);

  return 0;
}
