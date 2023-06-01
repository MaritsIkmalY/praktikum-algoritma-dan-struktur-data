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
    puts("3. Keluar");
}

void selection()
{
    puts("MENU METODE SORTING");
    puts("1. Ascending");
    puts("2. Descending");
}

void insertion()
{
    puts("Pengurutan yang dipilih :");
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
        switch (pilihan)
        {
        case 1:
            insertion();
            break;
        case 2:
            selection();
            break;
        default:
            exit(0);
        }
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
        else
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
        printArray(Data2);
        fflush(stdin);
        printf("Mau Lagi (y/t) ? ");
        jawab = getchar();
        jawab = toupper(jawab);
    } while (jawab == 'Y');
}