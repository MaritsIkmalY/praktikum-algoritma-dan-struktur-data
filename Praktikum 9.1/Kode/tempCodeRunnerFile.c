#include <stdio.h>
#include <time.h>

time_t begin, end;

int iterasi(int bil)
{
    int temp = 1;

    for (int i = 1; i <= bil; i++)
    {
        temp *= i;
    }
    return temp;
}

int rekursi(int bil)
{
    if (bil < 0)
        return 0;
    else if (bil == 1 || bil == 0)
        return 1;
    else
        return bil * rekursi(bil - 1);
}

int rekursiTail(int bil, int a)
{
    if (bil < 0)
        return 0;
    else if (bil == 1 || bil == 0)
        return a;
    else
        return rekursiTail(--bil, a * bil);
}

void menu()
{
    puts("1. Iterasi");
    puts("2. Rekursi");
    puts("3. Rekursi Tail");
}
int main()
{

    int pilihan, bilangan;

    menu();
    printf("Masukkan pilihan : ");
    scanf("%d", &pilihan);
    printf("Masukkan bilangan : ");
    scanf("%d", &bilangan);
    time(&begin);
    switch (pilihan)
    {
    case 1:
        printf("%d ! = %d\n", bilangan, iterasi(bilangan));
        break;
    case 2:
        printf("%d ! = %d\n", bilangan, rekursi(bilangan));
        break;
    case 3:
        printf("%d ! = %d\n", bilangan, rekursiTail(bilangan, 1));
        break;
    default:
        puts("input yang benar");
    }
    time(&end);
    double selisih = difftime(end, begin);
    printf("Ini selisih %lf\n", selisih);
    return 0;
}