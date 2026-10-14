#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char cmd[6];
    strcpy(cmd, "clear");

    char name[10];

    scanf("%10s", name);
    //scanf("%s", name);

    system(cmd);
    printf("Hallo %s\n", name);
}

// python -c "print('A'*10+'calc')" | .\cod_injection.exe
//                          ^xcalc für windus
// da cmd den ausfür string für System enthält und 'Nach' name steht, kann mit scanf ohne limitierung der gelesenen character über name, cmd beschrieben werden.