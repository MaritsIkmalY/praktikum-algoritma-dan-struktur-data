#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

int perbandingan, pergeseran, penyisipan;

void printArray(int arr[], int sz)
{
    for (int i = 0; i < sz; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSort(int arr[], int sz)
{
    for (int step = 1; step < sz; step++)
    {
        int key = arr[step];
        int back = step - 1;

        // best case comparison is n-1

        while (key < arr[back] && back >= 0)
        {
            // worst case comparison is n(n-1)/2
            usleep(1000);
            pergeseran++;
            arr[back + 1] = arr[back];
            back--;
            perbandingan++;
        }
        if (key > arr[back])
        {
            perbandingan++;
            usleep(1000);
        }
        if (arr[back + 1] != key)
            penyisipan++;
        arr[back + 1] = key;
    }
}

int main()
{
    struct timeval start, stop;
    // int array[10] = {3, 10, 4, 6, 8, 9, 7, 2, 1, 5};
    // int array[10] = {1, 2, 3, 4, 5, 9, 7, 6, 8, 10};
    // int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int array[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size = sizeof(array) / sizeof(array[0]);

    puts("Data Sebelum Sorting");
    printArray(array, size);
    gettimeofday(&start, NULL);
    insertionSort(array, size);
    gettimeofday(&stop, NULL);
    puts("Data Setelah Sorting");
    printArray(array, size);
    printf("Sorting %lu us\n", ((stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec));
    printf("Perbandingan = %d\n", perbandingan);
    printf("Pergeseran = %d\n", pergeseran);
    printf("Penyisipan = %d\n", penyisipan);
    return 0;
}