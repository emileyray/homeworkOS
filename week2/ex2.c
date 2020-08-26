#include <stdio.h>
#include <string.h>

int main() {
    char line[100000];
    char newline[100000];
    fgets(line, sizeof(line), stdin);
    for (int i = 0; i < strlen(line); i++){
        newline[i] = line[strlen(line) - 1 - i];
    }
    printf(newline);
    return 0;
}