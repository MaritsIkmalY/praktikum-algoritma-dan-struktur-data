#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAKS 25

typedef struct
{
    int no;
    char nama[MAKS];
    int nilai;
} siswa;

int banyak;

void menu()
{
    puts("MENU METODE SORTING");
    puts("1. Insertion Sort");
    puts("2. Selection Sort");
    puts("3. Bublle Short");
    puts("4. Shell Sort");
    puts("3. Keluar");
}

void modeUrut()
{
    puts("MENU METODE SORTING");
    puts("1. Ascending");
    puts("2. Descending");
}

void input(siswa arr[], int sz)
{
    char jwb;
    static int i = 0, cek = 0;

    if (cek != 0)
    {
        printf("Mau Input Data Lagi (y/t)? ");
        fflush(stdin);
        jwb = getchar();
        fflush(stdin);
        toupper(jwb);
    }
    if (cek == 0 || jwb == 'y')
    {
        cek++;
        do
        {
            fflush(stdin);
            printf("Masukkan data ke %d\n", ++i);
            printf("Masukkan No : ");
            scanf("%d", &arr[banyak].no);
            fflush(stdin);
            printf("Masukkan Nama : ");
            gets(arr[banyak].nama);
            fflush(stdin);
            printf("Isi nilai : ");
            scanf("%d", &arr[banyak].nilai);
            fflush(stdin);
            banyak++;
            printf("Mau lagi [y/t]? ");
            jwb = getchar();
            puts(" ");
            jwb = toupper(jwb);
            if (jwb == 'Y' && banyak == 9)
            {
                puts("Tidak Bisa Input lagi !");
                exit(0);
            }
        } while (jwb == 'Y' && banyak < sz);
    }
}

// Ascending
void AscSelectionSort(siswa arr[])
{
    for (int step = 0; step < banyak - 1; step++)
    {
        int min = step;
        for (int i = step + 1; i < banyak; i++)
        {
            if (arr[i].no < arr[min].no)
                min = i;
        }
        siswa temp = arr[min];
        arr[min] = arr[step];
        arr[step] = temp;
    }
}

// Descending
void DescSelectionSort(siswa arr[])
{

    for (int step = 0; step < banyak - 1; step++)
    {
        int min = step;
        for (int i = step + 1; i < banyak; i++)
        {
            if (arr[i].no > arr[min].no)
                min = i;
        }
        siswa temp = arr[min];
        arr[min] = arr[step];
        arr[step] = temp;
    }
}

// Ascending Insertion
void AscInsertionSort(siswa arr[])
{
    for (int step = 1; step < banyak; step++)
    {
        siswa temp = arr[step];
        int key = arr[step].no;
        int back = step - 1;

        while (key < arr[back].no && back >= 0)
        {
            arr[back + 1] = arr[back];
            back--;
        }
        arr[back + 1] = temp;
    }
}

// Descending Insertion
void DescInsertionSort(siswa arr[])
{
    for (int step = 1; step < banyak; step++)
    {
        siswa temp = arr[step];
        int key = arr[step].no;
        int back = step - 1;

        while (key > arr[back].no && back >= 0)
        {
            arr[back + 1] = arr[back];
            back--;
        }
        arr[back + 1] = temp;
    }
}

// Ascending Bubble Sort
void AscbubbleSort(siswa arr[])
{
    int cek, akhir;
    siswa temp;

    akhir = banyak;
    for (int i = 0; i < banyak; i++)
    {
        cek = 0;
        akhir--;
        for (int j = 0; j < akhir; j++)
        {
            if (arr[j].no > arr[j + 1].no)
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                cek = 1;
            }
        }
        if (cek == 0)
            break;
    }
}

// Descending Bubble Sort
void DescbubbleSort(siswa arr[])
{
    int cek, akhir;
    siswa temp;

    akhir = banyak;
    for (int i = 0; i < banyak; i++)
    {
        cek = 0;
        akhir--;
        for (int j = 0; j < akhir; j++)
        {
            if (arr[j].no < arr[j + 1].no)
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                cek = 1;
            }
        }
        if (cek == 0)
            break;
    }
}

// Ascending Shell Sort
void AscshellSort(siswa arr[])
{
    for (int interval = banyak / 2; interval > 0; interval /= 2)
    {
        printf("\nIterasi dengan k = %d\n", interval);
        int did_swap = 1;
        while (did_swap)
        {
            did_swap = 0;
            for (int i = 0; i < banyak - interval; i++)
            {

                if (arr[i].no > arr[interval + i].no)
                {
                    siswa temp = arr[interval + i];
                    arr[interval + i] = arr[i];
                    arr[i] = temp;
                    did_swap = 1;
                }
            }
        }
    }
}

// Descending Shell Sort
void DescshellSort(siswa arr[])
{
    for (int interval = banyak / 2; interval > 0; interval /= 2)
    {
        printf("\nIterasi dengan k = %d\n", interval);
        int did_swap = 1;
        while (did_swap)
        {
            did_swap = 0;
            for (int i = 0; i < banyak - interval; i++)
            {

                if (arr[i].no < arr[interval + i].no)
                {

                    siswa temp = arr[interval + i];
                    arr[interval + i] = arr[i];
                    arr[i] = temp;
                    did_swap = 1;
                }
            }
        }
    }
}

void printArray(siswa arr[])
{
    for (int i = 0; i < banyak; i++)
    {
        printf("No\t: %d\n", arr[i].no);
        printf("Nama\t: %s\n", arr[i].nama);
        printf("Nilai\t: %d\n", arr[i].nilai);
        puts(" ");
    }
    puts(" ");
}

void copyData(siswa Data[], siswa Data2[])
{
    for (int i = 0; i < banyak; i++)
    {
        Data2[i] = Data[i];
    }
}

int main()
{
    int pilihan, pilih;
    siswa Data[10], Data2[10];
    int size = sizeof(Data) / sizeof(Data[0]);
    char jawab;

    do
    {
        fflush(stdin);
        input(Data, size);
        copyData(Data, Data2);
        printArray(Data2);
        menu();
        printf("Pilihan Anda[1/2/3] : ");
        scanf("%d", &pilihan);
        if (pilihan == 5)
            exit(0);
        modeUrut();
        printf("Pilihan Anda[1/2] : ");
        scanf("%d", &pilih);
        if (pilihan == 1)
        {
            switch (pilih)
            {
            case 1:
                AscInsertionSort(Data2);
                break;
            case 2:
                DescInsertionSort(Data2);
                break;
            default:
                exit(0);
            }
        }
        else if (pilihan == 2)
        {
            switch (pilih)
            {
            case 1:
                AscSelectionSort(Data2);
                break;
            case 2:
                DescInsertionSort(Data2);
                break;
            default:
                exit(0);
            }
        }
        else if (pilihan == 3)
        {
            switch (pilih)
            {
            case 1:
                AscbubbleSort(Data2);
                break;
            case 2:
                DescbubbleSort(Data2);
                break;
            default:
                exit(0);
            }
        }
        else if (pilihan == 4)
        {
            switch (pilih)
            {
            case 1:
                AscshellSort(Data2);
                break;
            case 2:
                DescshellSort(Data2);
                break;
            default:
                exit(0);
            }
        }
        printArray(Data2);
        fflush(stdin);
        printf("Mau Lagi (y/t) ? ");
        jawab = getchar();
        jawab = toupper(jawab);
    } while (jawab == 'Y');
}