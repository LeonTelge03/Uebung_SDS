#include <stdio.h>
#include <stdlib.h>

enum { BUFFER_SIZE = 256 };

int main() {
    int check1 = 0;
    char buffer[BUFFER_SIZE];
    int check2 = 0;
    fgets(buffer, BUFFER_SIZE, stdin);
    //printf(buffer);
    if(check1||check2) puts("You Win");
    return EXIT_SUCCESS;
}
// Altes Problem bei A*buffsize