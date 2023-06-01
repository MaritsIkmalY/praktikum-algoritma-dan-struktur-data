#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <math.h>

int comparison, swapping, movement;

void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    puts(" ");
}

void AscbubbleSort(int array[], int size)
{
    int cek, akhir, temp;

    akhir = size;
    for (int i = 0; i < size; i++)
    {
        cek = 0;
        akhir--;
        for (int j = 0; j < akhir; j++)
        {
            usleep(100);
            comparison++;
            if (array[j] > array[j + 1])
            {
                swapping++;
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                cek = 1;
            }
        }
        if (cek == 0)
            break;
    }
}

void DescbubbleSort(int array[], int size)
{
    int cek, akhir, temp;

    akhir = size;
    for (int i = 0; i < size; i++)
    {
        cek = 0;
        akhir--;
        for (int j = 0; j < akhir; j++)
        {
            usleep(100);
            comparison++;
            if (array[j] < array[j + 1])
            {
                swapping++;
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                cek = 1;
            }
        }
        if (cek == 0)
            break;
    }
}

void AscshellSort(int array[], int size)
{
    for (int interval = size / 2; interval > 0; interval /= 2)
    {
        printf("\nIterasi dengan k = %d\n", interval);
        int did_swap = 1;
        while (did_swap)
        {
            did_swap = 0;
            for (int i = 0; i < size - interval; i++)
            {
                comparison++;
                usleep(100);
                if (array[i] > array[interval + i])
                {
                    swapping++;
                    int temp = array[interval + i];
                    array[interval + i] = array[i];
                    array[i] = temp;
                    did_swap = 1;
                }
            }
        }
    }
}

void DescshellSort(int array[], int size)
{
    for (int interval = size / 2; interval > 0; interval /= 2)
    {
        printf("\nIterasi dengan k = %d\n", interval);
        int did_swap = 1;
        while (did_swap)
        {
            did_swap = 0;
            for (int i = 0; i < size - interval; i++)
            {
                comparison++;
                usleep(100);
                if (array[i] < array[interval + i])
                {
                    swapping++;
                    int temp = array[interval + i];
                    array[interval + i] = array[i];
                    array[i] = temp;
                    did_swap = 1;
                }
            }
        }
    }
}

void generate(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 1000;
    }
}

void menu()
{
    puts("1. Bubble Sort");
    puts("2. Shell Sort");
}

void menu_urut()
{
    puts("1. Ascending");
    puts("2. Descending");
}

int main()
{

    int size, pilihan, pilih;
    struct timeval start, stop;

    printf("Masukkan Banyak Data : ");
    scanf("%d", &size);
    int array[size];

    generate(array, size);
    printArray(array, size);
    menu();
    printf("Masukkan pilihan Anda : ");
    scanf("%d", &pilihan);
    menu_urut();
    printf("Masukkan mode urut : ");
    scanf("%d", &pilih);
    gettimeofday(&start, NULL);
    if (pilihan == 1)
    {
        switch (pilih)
        {
        case 1:
            AscbubbleSort(array, size);
            break;
        case 2:
            DescbubbleSort(array, size);
        }
    }
    else
    {
        switch (pilih)
        {
        case 1:
            AscshellSort(array, size);
            break;
        case 2:
            DescshellSort(array, size);
        }
    }
    gettimeofday(&stop, NULL);
    printArray(array, size);
    printf("Comparison = %d\n", comparison);
    printf("Swapping = %d\n", swapping);
    printf("The process took %lu us\n", ((stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec));
    return 0;
}