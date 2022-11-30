#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#define PIPE_W 1
#define PIPE_R 0

int main() {

	int p_h[2];
	int h_p[2];

	pipe(p_h); pipe(h_p);

	switch (fork()) {
	case -1:
		perror("ERROR al hacerl el fork");
		return 1;
		break;
	case 0:
		//Hijo
		close(p_h[1]); close(h_p[0]);
		int cont = 0;
		char mensajePadre[255];
		char flag[1] = { 'l' };

		while (cont < 10) {
			ssize_t bytes = read(p_h[0], mensajePadre, 255);
			mensajePadre[bytes] = '\0';
			printf("[HIJO] Recibido: %s\n", mensajePadre);
			cont++;
			sleep(1);
			if (cont == 10) flag[0] = 'q';
			write(h_p[1], &flag, 1);
		}

		break;
	default:

		//Padre
		close(p_h[0]); close(h_p[1]);
		char mensaje[255];
		char stop[1] = { 'l' };
		while (stop[0] != 'q') {
			printf("%s\n", "[PADRE] Mensaje: ");
			ssize_t bytes = read(0, mensaje, 255);
			mensaje[bytes] = '\0';
			write(p_h[1], mensaje, 255);
			read(h_p[0], &flag, 1);
		}
		wait(NULL);
		close(p_h[PIPE_W]);
		close(h_p[PIPE_R]);
		printf("10 mensajes enviados con éxito. Saliendo...\n");
		break;
	}
}