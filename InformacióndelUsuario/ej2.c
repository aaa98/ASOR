#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <sys/utsname.h>
#include <sys/types.h>
#include <pwd.h>

int main(){

    uid_t uid = getuid();

    printf("UID Real: %d\n", getuid());
    printf("UID efectivo: %d\n", geteuid());

    struct passwd *contrasena= getpwuid(uid);

    char *nombre = contrasena->pw_name;
    char *dir = contrasena->pw_dir;
    char *info = contrasena->pw_gecos;

    printf("Username: %s\n", nombre);
    printf("Home: %s\n", dir);
    printf("Info: %s\n",info);

  return 1;
}
