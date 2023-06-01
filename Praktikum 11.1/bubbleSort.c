#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

int comparison, swapping, movement;

void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    puts(" ");
}

void bubbleSort(int array[], int size)
{
    int cek, akhir, temp;

    akhir = size;
    for (int i = 0; i < size; i++)
    {
        cek = 0;
        akhir--;
        for (int j = 0; j < akhir; j++)
        {
            usleep(1000);
            comparison++;
            if (array[j] > array[j + 1])
            {
                swapping++;
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                cek = 1;
            }
            printArray(array, size);
        }
        if (cek == 0)
            break;
    }
}

int main()
{
    int array[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size = sizeof(array) / sizeof(array[0]);
    struct timeval start, stop;

    gettimeofday(&start, NULL);
    bubbleSort(array, size);
    gettimeofday(&stop, NULL);
    printf("Comparison = %d\n", comparison);
    printf("Swapping = %d\n", swapping);
    printf("The process took %lu us\n", ((stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec));
    return 0;
}