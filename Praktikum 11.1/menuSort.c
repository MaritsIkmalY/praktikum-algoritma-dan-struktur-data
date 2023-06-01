#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <math.h>

int perbandingan, penukaran, movement;

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
            perbandingan++;
            if (array[j] > array[j + 1])
            {
                penukaran++;
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
            perbandingan++;
            if (array[j] < array[j + 1])
            {
                penukaran++;
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
                perbandingan++;
                usleep(100);
                if (array[i] > array[interval + i])
                {
                    penukaran++;
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
                perbandingan++;
                usleep(100);
                if (array[i] < array[interval + i])
                {
                    penukaran++;
                    int temp = array[interval + i];
                    array[interval + i] = array[i];
                    array[i] = temp;
                    did_swap = 1;
                }
            }
        }
    }
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

void generate(int array[], int array_simpanan[], int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = array_simpanan[i] = rand() % 1000;
    }
}

void mengembalikan(int array[], int array_simpanan[], int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = array_simpanan[i];
    }
}

void menu()
{
    puts("1. Insertion Sort");
    puts("2. Selection Sort");
    puts("3. Bubble Sort");
    puts("4. Shell Sort");
    puts("5. Shell Sort");
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
    int array_simpanan[size];

    generate(array, array_simpanan, size);
    do
    {
        puts("\nSebelum di Sorting");
        printArray(array, size);
        menu();
        printf("Masukkan pilihan Anda : ");
        scanf("%d", &pilihan);
        if (pilihan == 5)
            exit(0);
        menu_urut();
        printf("Masukkan mode urut : ");
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
            }
        }
        else if (pilihan == 2)
        {
            switch (pilih)
            {
            case 1:
                AscSelectionSort(array, size);
                break;
            case 2:
                DescSelectionSort(array, size);
            }
        }
        else if (pilihan == 3)
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
        else if (pilihan == 4)
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
        puts("\nSetelah di Sorting");
        printArray(array, size);
        mengembalikan(array, array_simpanan, size);
        printf("perbandingan = %d\n", perbandingan);
        printf("penukaran = %d\n", penukaran);
        printf("The process took %lu us\n", ((stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec));
    } while (pilihan != 5);
    return 0;
}