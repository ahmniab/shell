#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>


int main(){
    char dir[100];
    getcwd(dir , 100);
    printf("wd = %s\n",dir);

    system("ls");
    getcwd(dir , 100);
    printf("wd = %s\n",dir);

    const char *homedir;

    if ((homedir = getenv("HOME")) == NULL) {
        homedir = getpwuid(getuid())->pw_dir;
    }
    printf("%s\n",homedir);
}