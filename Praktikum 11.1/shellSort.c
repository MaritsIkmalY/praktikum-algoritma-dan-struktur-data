#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

int comparison, swapping;

void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    puts(" ");
}

void shellSort(int array[], int size)
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
                usleep(1000);
                if (array[i] > array[interval + i])
                {
                    swapping++;
                    int temp = array[interval + i];
                    array[interval + i] = array[i];
                    array[i] = temp;
                    did_swap = 1;
                }
                printArray(array, size);
            }
        }
    }
}

int main()
{
    int array[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size = sizeof(array) / sizeof(array[0]);
    struct timeval start, stop;

    gettimeofday(&start, NULL);
    shellSort(array, size);
    gettimeofday(&stop, NULL);
    printf("Comparison = %d\n", comparison);
    printf("Swapping = %d\n", swapping);
    printf("The process took %lu us\n", ((stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec));
    return 0;
}