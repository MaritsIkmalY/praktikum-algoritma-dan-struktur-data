#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#define MAKS 10

int comparison, swapping;

void quickSort(int array[], int size);
void quickSortRecursive(int array[], int start, int end);
int partition(int[], int, int);
void tampil(int[], int);
void swap(int[], int, int);

int main()
{
    struct timeval start, stop;
    int array[MAKS] = {2, 3, 5, 4, 1, 7, 6, 9, 10, 8};
    int size = sizeof(array) / sizeof(array[0]);
    puts("Data sebelum : ");
    tampil(array, MAKS);

    gettimeofday(&start, NULL);
    quickSort(array, size);
    gettimeofday(&stop, NULL);
    puts("Data sesudah : ");
    tampil(array, MAKS);
    printf("Comparison = %d\n", comparison);
    printf("The process took %lu us\n", ((stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec));
}

void quickSort(int array[], int size)
{
    quickSortRecursive(array, 0, size - 1);
}

void quickSortRecursive(int array[], int start, int end)
{
    int q;
    if (start < end)
    {
        q = partition(array, start, end);
        quickSortRecursive(array, start, q);
        quickSortRecursive(array, q + 1, end);
    }
}

int partition(int A[], int p, int r)
{
    int x = A[p], i = p, j = r;

    while (i < j)
    {
        while (A[j] > x)
            j--;
        while (A[i] < x)
            i++;
        comparison++;
        usleep(1000);
        if (i < j)
        {
            swapping++;
            swap(A, i, j);
            j--;
            i++;
        }
        else
        {
            return j;
        }
    }
}

void swap(int item[], int elemen1, int elemen2)
{
    int temp;
    temp = item[elemen1];
    item[elemen1] = item[elemen2];
    item[elemen2] = temp;
}

void tampil(int item[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", item[i]);
    }
    puts("");
}