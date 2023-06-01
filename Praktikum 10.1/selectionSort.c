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

void selectionSort(int arr[], int sz)
{
    for (int step = 0; step < sz - 1; step++)
    {
        int min = step;
        for (int i = step + 1; i < sz; i++)
        {
            usleep(1000);
            perbandingan++;
            if (arr[i] < arr[min])
            {
                min = i;
            }
        }
        if (arr[min] != arr[step])
            penukaran++;
        int temp = arr[min];
        arr[min] = arr[step];
        arr[step] = temp;
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
    selectionSort(array, size);
    gettimeofday(&stop, NULL);
    puts("Data Setelah Sorting");
    printArray(array, size);
    printf("Sorting %lu us\n", ((stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec));
    printf("Perbandingan = %d\n", perbandingan);
    printf("Penukaran = %d\n", penukaran);
    return 0;
}