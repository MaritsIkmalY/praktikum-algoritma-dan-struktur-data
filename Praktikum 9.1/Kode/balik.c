#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAKS 25

void balik(char kalimat[], int panjang)
{
    if (panjang > 0)
    {
        printf("%c", kalimat[panjang - 1]);
        balik(kalimat, --panjang);
    }
}

int main()
{
    char string[MAKS];

    printf("Masukkan String : ");
    gets(string);
    balik(string, strlen(string));
    return 0;
}