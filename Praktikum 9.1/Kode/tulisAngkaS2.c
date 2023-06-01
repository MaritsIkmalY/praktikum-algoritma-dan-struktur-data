#include <stdio.h>

void maju(int bil)
{
    int static number = 0;

    if (bil >= 0)
    {
        printf("%d ", number++);
        maju(bil - 1);
    }
}

int main()
{
    int bilangan;

    printf("Masukkan bilangan : ");
    scanf("%d", &bilangan);
    maju(bilangan);
    return 0;
}
