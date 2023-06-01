#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

int perbandingan, penukaran;

void printArray(int arr[], int sz)
{
    for (int i = 0; i < sz; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Ascending
void AscSelectionSort(int arr[], int sz)
{
    for (int step = 0; step < sz - 1; step++)
    {
        int min = step;
        for (int i = step + 1; i < sz; i++)
        {
            usleep(100);
            perbandingan++;
            if (arr[i] < arr[min])
                min = i;
        }
        if (arr[min] != arr[step])
            penukaran++;
        int temp = arr[min];
        arr[min] = arr[step];
        arr[step] = temp;
    }
}

// Descending
void DescSelectionSort(int arr[], int sz)
{
    for (int step = 0; step < sz - 1; step++)
    {
        int min = step;
        for (int i = step + 1; i < sz; i++)
        {
            usleep(100);
            perbandingan++;
            if (arr[i] > arr[min])
                min = i;
        }
        if (arr[min] != arr[step])
            penukaran++;
        int temp = arr[min];
        arr[min] = arr[step];
        arr[step] = temp;
    }
}

// Ascending
void AscInsertionSort(int arr[], int sz)
{
    for (int step = 1; step < sz; step++)
    {
        int key = arr[step];
        int back = step - 1;

        while (key < arr[back] && back >= 0)
        {
            usleep(100);
            perbandingan++;
            arr[back + 1] = arr[back];
            back--;
        }
        if (key > arr[back])
        {
            perbandingan++;
            usleep(100);
        }
        if (arr[back + 1] != key)
            penukaran++;
        arr[back + 1] = key;
    }
}

// Descending
void DescInsertionSort(int arr[], int sz)
{
    for (int step = 1; step < sz; step++)
    {
        int key = arr[step];
        int back = step - 1;

        while (key > arr[back] && back >= 0)
        {

            usleep(100);
            perbandingan++;
            arr[back + 1] = arr[back];
            back--;
        }
        if (key < arr[back])
        {
            perbandingan++;
            usleep(100);
        }
        if (arr[back + 1] != key)
            penukaran++;
        arr[back + 1] = key;
    }
}

void menu()
{
    puts("MENU METODE SORTING");
    puts("1. Insertion Sort");
    puts("2. Selection Sort");
    puts("3. Keluar");
}

void insertion()
{
    puts("MENU METODE SORTING");
    puts("1. Ascending");
    puts("2. Descending");
}

void selection()
{
    puts("MENU METODE SORTING");
    puts("1. Ascending");
    puts("2. Descending");
}

int main()
{
    struct timeval start, stop;
    int array[10] = {3, 10, 4, 6, 8, 9, 7, 2, 1, 5};
    int size = sizeof(array) / sizeof(array[0]);
    int pilihan, pilih;

    printArray(array, size);
    menu();
    printf("Pilihan Anda [1/2/3] : ");
    scanf("%d", &pilihan);
    switch (pilihan)
    {
    case 1:
        insertion();
        break;
    case 2:
        selection();
        break;
    case 3:
        exit(0);
    default:
        exit(0);
    }
    printf("Pilihan Anda [1/2] : ");
    scanf("%d", &pilih);
    gettimeofday(&start, NULL);
    if (pilihan == 1)
    {
        switch (pilih)
        {
        case 1:
            AscInsertionSort(array, size);
            break;
        case 2:
            DescInsertionSort(array, size);
            break;
        default:
            exit(0);
        }
    }
    else
    {
        switch (pilih)
        {
        case 1:
            AscSelectionSort(array, size);
            break;
        case 2:
            DescSelectionSort(array, size);
            break;
        default:
            exit(0);
        }
    }
    gettimeofday(&stop, NULL);
    printf("Perbandingan = %d\n", perbandingan);
    printf("Penukaran = %d\n", penukaran);
    printf("Sorting %lu us\n", ((stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec));
    printArray(array, size);
    return 0;
}