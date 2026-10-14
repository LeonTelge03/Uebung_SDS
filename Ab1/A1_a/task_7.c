#include <stdio.h>
#include <string.h>
#define str_size 255

char *strrev(char *str) //needs to be implemented manually on unix
{
    char *p1, *p2;

    if (!str || !*str)
        return str;
    for (p1 = str, p2 = str + strlen(str) - 2; p2 > p1; ++p1, --p2) { //Jetzt ohne \n =)
        *p1 ^= *p2;
        *p2 ^= *p1;
        *p1 ^= *p2;
    }
    return str;
}

int main() { //isThisAPalindrom
    char str[str_size]; // declare the size of character string
    char strCopy[str_size];
    printf("Welcome to: \"Is this word a palindrome?!\". Please enter your string to start: \n");
    fgets(str, sizeof(str),stdin);  //Jetzt mit \n =)

    strcpy(strCopy, str); //copy string to backup so strrev doesnt overwrite our only source

    if (strcmp(strCopy, strrev(str)) == 0) {
        printf("\nYippie that word is a palindrome!\n\n");
    } else {
        printf("\nNu-Uh! Not a palindrome!\n\n");
    }

    return 0;
}

//Wenn zu viele Buchstaben eingegeben werden, Scheitetrts auch bei palindromen. (eg A*41)