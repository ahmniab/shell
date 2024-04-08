#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 1024
int main() {
    char input[MAX_LENGTH];
    char path[MAX_LENGTH];
    char command[MAX_LENGTH];
    while (1) {
        printf("Current Path: %s\n", getcwd(path, sizeof(path)));
        printf("Enter a command: ");
        fflush(stdout);
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("Error reading input.\n");
            continue;
        }
        input[strcspn(input, "\n")] = '\0';
        if (strcmp(input, "exit") == 0) {
            printf("Exiting...\n");
            break;
        }
        printf("Command entered: %s\n", input);
    }
    return 0;
}
