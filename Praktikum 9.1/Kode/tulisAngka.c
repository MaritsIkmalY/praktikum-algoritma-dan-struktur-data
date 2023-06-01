#include <stdio.h>

void mundur(int bil)
{
    if (bil >= 0)
    {
        printf("%d ", bil);
        mundur(bil - 1);
    }
}

int main()
{
    int bilangan;

    printf("Masukkan bilangan : ");
    scanf("%d", &bilangan);
    mundur(bilangan);
    return 0;
}
