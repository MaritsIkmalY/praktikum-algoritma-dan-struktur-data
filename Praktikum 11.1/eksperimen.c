#include <stdio.h>
#define MAKS 10

void swap(int *, int *);
void shellSort(int[], int);
void tampil(int[], int);

int jmlBanding = 0, jmlGeser = 0, jmlTukar = 0;

int main()
{
    int data[MAKS] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}, i, j;

    puts("Data sebelum diurutkan");
    tampil(data, MAKS);
    puts("\nProses pengurutan");
    shellSort(data, MAKS);
    printf("\nJumlah perbandingan = %d\n", jmlBanding);
    printf("Jumlah penukaran = %d\n", jmlTukar);
    printf("Jumlah pergeseran = %d\n", jmlGeser);

    return 0;
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void shellSort(int data[], int n)
{
    int i, gap, didSwap, iterasi = 0;

    gap = n;
    while (gap > 1)
    {
        iterasi++;
        gap /= 2;
        didSwap = 1;
        while (didSwap)
        {
            didSwap = 0;
            i = 0;
            while (i < n - gap)
            {
                jmlBanding++;
                if (data[i] > data[i + gap])
                {
                    jmlTukar++;
                    jmlGeser += 3;
                    swap(&data[i], &data[i + gap]);
                    didSwap = 1;
                }
                i++;
            }
        }
        printf("iterasi ke-%d : ", iterasi);
        tampil(data, n);
    }
}

void tampil(int data[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", data[i]);
    puts("");
}