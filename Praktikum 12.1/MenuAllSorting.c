#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <math.h>

void menu_urut();
void menu();
void mengembalikan(int array[], int array_simpanan[], int size);
void generate(int array[], int array_simpanan[], int size);
void DescInsertionSort(int arr[], int sz);
void AscInsertionSort(int arr[], int sz);
void DescSelectionSort(int arr[], int sz);
void AscSelectionSort(int arr[], int sz);
void DescshellSort(int array[], int size);
void AscshellSort(int array[], int size);
void DescbubbleSort(int array[], int size);
void AscbubbleSort(int array[], int size);
void DescmergeSort(int array[], int size);
void Descmerge(int array[], int left, int middle, int right, int size);
void DescmergeSortRecursive(int array[], int kiri, int kanan, int size);
void AscmergeSort(int array[], int size);
void Ascmerge(int array[], int left, int middle, int right, int size);
void AscmergeSortRecursive(int array[], int kiri, int kanan, int size);
void printArray(int array[], int size);
int Descpartition(int array[], int start, int end);
void DescquickSortRecursive(int array[], int start, int end);
void DescquickSort(int array[], int size);
int Ascpartition(int array[], int start, int end);
void AscquickSortRecursive(int array[], int start, int end);
void AscquickSort(int array[], int size);

int perbandingan, penukaran, movement;

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
        if (pilihan == 7)
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
        else if (pilihan == 5)
        {
            switch (pilih)
            {
            case 1:
                AscmergeSort(array, size);
                break;
            case 2:
                DescmergeSort(array, size);
            }
        }
        else if (pilihan == 6)
        {
            switch (pilih)
            {
            case 1:
                AscquickSort(array, size);
                break;
            case 2:
                DescquickSort(array, size);
            }
        }
        gettimeofday(&stop, NULL);
        puts("\nSetelah di Sorting");
        printArray(array, size);
        mengembalikan(array, array_simpanan, size);
        printf("perbandingan = %d\n", perbandingan);
        printf("penukaran = %d\n", penukaran);
        printf("The process took %lu us\n", ((stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec));
    } while (pilihan != 7);
    return 0;
}

void menu()
{
    puts("1. Insertion Sort");
    puts("2. Selection Sort");
    puts("3. Bubble Sort");
    puts("4. Shell Sort");
    puts("5. Merge Sort");
    puts("6. Quick Sort");
    puts("7. Keluar");
}

void menu_urut()
{
    puts("1. Ascending");
    puts("2. Descending");
}

// Print Array
void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    puts(" ");
}

// Ascending Quick Sort
void AscquickSort(int array[], int size)
{
    int start = 0, end = size - 1;
    AscquickSortRecursive(array, start, end);
}

void AscquickSortRecursive(int array[], int start, int end)
{
    if (start < end)
    {
        int p = Ascpartition(array, start, end);
        AscquickSortRecursive(array, start, p - 1);
        AscquickSortRecursive(array, p + 1, end);
    }
}

int Ascpartition(int array[], int start, int end)
{
    int pivot = array[end], pIndex = start, temp;

    for (int i = start; i < end; i++)
    {
        usleep(100);
        perbandingan++;
        if (array[i] <= pivot)
        {
            penukaran++;
            temp = array[i];
            array[i] = array[pIndex];
            array[pIndex] = temp;
            pIndex++;
        }
    }
    penukaran++;
    temp = array[end];
    array[end] = array[pIndex];
    array[pIndex] = temp;
    return pIndex;
}

// Descending Quick Sort
void DescquickSort(int array[], int size)
{
    int start = 0, end = size - 1;
    DescquickSortRecursive(array, start, end);
}

void DescquickSortRecursive(int array[], int start, int end)
{
    if (start < end)
    {
        int p = Descpartition(array, start, end);
        DescquickSortRecursive(array, start, p - 1);
        DescquickSortRecursive(array, p + 1, end);
    }
}

int Descpartition(int array[], int start, int end)
{
    int pivot = array[end], pIndex = start, temp;

    for (int i = start; i < end; i++)
    {
        usleep(100);
        perbandingan++;
        if (array[i] >= pivot)
        {
            penukaran++;
            temp = array[i];
            array[i] = array[pIndex];
            array[pIndex] = temp;
            pIndex++;
        }
    }
    penukaran++;
    temp = array[end];
    array[end] = array[pIndex];
    array[pIndex] = temp;
    return pIndex;
}

// Ascending Merge
void AscmergeSort(int array[], int size)
{
    AscmergeSortRecursive(array, 0, size - 1, size);
}

void Ascmerge(int array[], int left, int middle, int right, int size)
{
    int temp[size];
    int i = left, j = middle + 1, k = left;

    while (i <= middle && j <= right)
    {
        usleep(100);
        perbandingan++;
        if (array[i] <= array[j])
        {
            temp[k] = array[i];
            i++;
            penukaran++;
        }
        else
        {
            penukaran++;
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
        penukaran++;
    }

    while (j <= right)
    {
        temp[k] = array[j];
        j++;
        k++;
        penukaran++;
    }

    for (int a = left; a <= right; a++)
    {
        array[a] = temp[a];
    }
}

void AscmergeSortRecursive(int array[], int kiri, int kanan, int size)
{
    int tengah;
    if (kiri < kanan)
    {
        tengah = kiri + (kanan - kiri) / 2;
        AscmergeSortRecursive(array, kiri, tengah, size);
        AscmergeSortRecursive(array, tengah + 1, kanan, size);
        Ascmerge(array, kiri, tengah, kanan, size);
    }
}

// Descending Merge
void DescmergeSort(int array[], int size)
{
    DescmergeSortRecursive(array, 0, size - 1, size);
}

void Descmerge(int array[], int left, int middle, int right, int size)
{
    int temp[size];
    int i = left, j = middle + 1, k = left;

    while (i <= middle && j <= right)
    {
        usleep(100);
        perbandingan++;
        if (array[i] >= array[j])
        {
            temp[k] = array[i];
            i++;
            penukaran++;
        }
        else
        {
            penukaran++;
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
        penukaran++;
    }

    while (j <= right)
    {
        temp[k] = array[j];
        j++;
        k++;
        penukaran++;
    }

    for (int a = left; a <= right; a++)
    {
        array[a] = temp[a];
    }
}

void DescmergeSortRecursive(int array[], int kiri, int kanan, int size)
{
    int tengah;
    if (kiri < kanan)
    {
        tengah = kiri + (kanan - kiri) / 2;
        DescmergeSortRecursive(array, kiri, tengah, size);
        DescmergeSortRecursive(array, tengah + 1, kanan, size);
        Descmerge(array, kiri, tengah, kanan, size);
    }
}

// Ascending Bubble
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

// Descending Bubble
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

// Ascending Shell
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

// Descending Shell
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

// Ascending Selection
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

// Descending Selection
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

// Ascending Insertion
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

// Descending Insertion
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
