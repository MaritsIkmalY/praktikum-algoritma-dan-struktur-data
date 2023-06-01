#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#define MAKS 10

int comparison, swapping;

void merge(int array[], int left, int middle, int right);
void mergeSortRecursive(int array[], int kiri, int kanan);
void printArray(int array[], int size);
void mergeSort(int array[], int sz);

int main()
{
    int array[MAKS] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size = sizeof(array) / sizeof(array[0]);
    struct timeval start, stop;

    printArray(array, size);
    gettimeofday(&start, NULL);
    mergeSort(array, size);
    gettimeofday(&stop, NULL);
    printArray(array, size);
    printf("Comparison = %d\n", comparison);
    printf("Swapping = %d\n", swapping);
    printf("The process took %lu us\n", ((stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec));
    return 0;
}

void mergeSort(int array[], int sz)
{
    mergeSortRecursive(array, 0, sz - 1);
}

void mergeSortRecursive(int array[], int kiri, int kanan)
{
    int tengah;
    if (kiri < kanan)
    {
        tengah = kiri + (kanan - kiri) / 2;
        mergeSortRecursive(array, kiri, tengah);
        mergeSortRecursive(array, tengah + 1, kanan);
        merge(array, kiri, tengah, kanan);
    }
}

void merge(int array[], int left, int middle, int right)
{
    int temp[MAKS];
    int i = left, j = middle + 1, k = left;

    while (i <= middle && j <= right)
    {
        usleep(1000);
        comparison++;
        if (array[i] <= array[j])
        {
            temp[k] = array[i];
            i++;
            swapping++;
        }
        else
        {
            swapping++;
            temp[k] = array[j];
            j++;
        }
        k++;
    }

    while (i <= middle)
    {
        temp[k] = array[i];
        i++;
        k++;
        swapping++;
    }

    while (j <= right)
    {
        temp[k] = array[j];
        j++;
        k++;
        swapping++;
    }

    for (int a = left; a <= right; a++)
    {
        array[a] = temp[a];
    }
}

void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    puts(" ");
}
