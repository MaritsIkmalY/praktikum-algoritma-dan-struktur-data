#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

void printArray(int array[], int size);
void quickSort(int array[], int size);
void quickSortRecursive(int array[], int start, int end);
int partition(int array[], int start, int end);
int comparison, swapping, movement;

int main()
{
    int array[10] = {2, 3, 5, 4, 1, 7, 6, 9, 10, 8};
    int size = sizeof(array) / sizeof(array[0]);
    struct timeval start, stop;

    printArray(array, size);
    gettimeofday(&start, NULL);
    quickSort(array, size);
    gettimeofday(&stop, NULL);
    printArray(array, size);
    printf("Comparison = %d\n", comparison);
    printf("Swapping = %d\n", swapping);
    printf("The process took %lu us\n", ((stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec));
    return 0;
}

void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    puts(" ");
}

void quickSort(int array[], int size)
{
    int start = 0, end = size - 1;
    quickSortRecursive(array, start, end);
}

void quickSortRecursive(int array[], int start, int end)
{
    if (start < end)
    {
        int p = partition(array, start, end);
        quickSortRecursive(array, start, p - 1);
        quickSortRecursive(array, p + 1, end);
    }
}

int partition(int array[], int start, int end)
{
    int pivot = array[end], pIndex = start, temp;

    for (int i = start; i < end; i++)
    {
        usleep(1000);
        comparison++;
        if (array[i] <= pivot)
        {
            swapping++;
            temp = array[i];
            array[i] = array[pIndex];
            array[pIndex] = temp;
            pIndex++;
        }
    }
    swapping++;
    temp = array[end];
    array[end] = array[pIndex];
    array[pIndex] = temp;
    return pIndex;
}

// int partition(int array[], int start, int end)
// {
//     int x = array[start];
//     int i = start, j = end, temp;

//     do
//     {

//         while (array[j] > x)
//             j--;
//         while (array[i] < x)
//             i--;
//         if (i < j)
//         {
//             temp = array[i];
//             array[i] = array[j];
//             array[j] = temp;
//             j--;
//             i++;
//         }
//         else
//         {
//             return j;
//         }
//     } while (i <= j);
// }