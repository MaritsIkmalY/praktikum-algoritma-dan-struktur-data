#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Dnode;
struct simpul
{
    int data;
    Dnode *prev, *next;
};

void alokasi();
void awal();
void tampil();

Dnode *head = NULL, *p;

int main()
{
    char jwb;

    puts("DLL Insert Awal");
    do
    {
        fflush(stdin);
        alokasi();
        awal();
        fflush(stdin);
        printf("Mau lagi (y/t) ? ");
        jwb = getchar();
    } while (jwb == 'Y' || jwb == 'y');
    tampil();
    return 0;
}

void alokasi()
{
    int x;

    printf("Data yang mau disimpan ? ");
    scanf("%d", &x);
    p = (Dnode *)malloc(sizeof(Dnode));
    if (p == NULL)
    {
        puts("Pemesanan Gagal");
        exit(0);
    }
    else
    {
        p->data = x;
        p->next = NULL;
        p->prev = NULL;
    }
}

void awal()
{
    if (head != NULL)
    {
        p->next = head;
        head->prev = p;
    }
    head = p;
}

void tampil()
{
    Dnode *baca;

    puts("Isi dari DLL");
    baca = head;
    while (baca != NULL)
    {
        printf("%d\n", baca->data);
        baca = baca->next;
    }
}
