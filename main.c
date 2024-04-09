#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "Mab/Mab.h"
#include "invoke.h"
#include "analyser.h"

#define MAX_LENGTH 1024

int main() {
    char input[MAX_LENGTH];
    char path[MAX_LENGTH];
    char command[MAX_LENGTH];

    Mab commands;
    init_mab(&commands);
    extract_lines(&commands);

    while (1) {
        printf("%s> ", getcwd(path, sizeof(path)));
        fflush(stdout);
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("Error reading input.\n");
            continue;
        }
        input[strcspn(input, "\n")] = '\0';
        if (strcmp(input, "exit") == 0) {
            //printf("Exiting...\n");
            break;
        }
        handle_command(input , &commands);
    }
    return 0;
}
