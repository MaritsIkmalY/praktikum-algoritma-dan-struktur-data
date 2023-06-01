#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>

int iterasi(int bil)
{
    int temp = 1;

    for (int i = 1; i <= bil; i++)
    {
        usleep(1000);
        temp *= i;
    }
    return temp;
}

int rekursi(int bil)
{
    usleep(1000);
    if (bil < 0)
        return 0;
    else if (bil == 1 || bil == 0)
        return 1;
    else
        return bil * rekursi(bil - 1);
}

int rekursiTail(int bil, int a)
{
    usleep(1000);
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
    struct timeval stop, start;

    menu();
    printf("Masukkan pilihan : ");
    scanf("%d", &pilihan);
    printf("Masukkan bilangan : ");
    scanf("%d", &bilangan);
    // clock_t start = clock();
    gettimeofday(&start, NULL);
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
    gettimeofday(&stop, NULL);
    printf("took %lu us\n", ((stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec));
    // clock_t finish = clock();
    // double selisih = (double)(finish - start) / CLOCKS_PER_SEC;
    // printf("Ini selisih %lf\n", selisih);
    return 0;
}