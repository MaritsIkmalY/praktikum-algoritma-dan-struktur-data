#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Dnode;
struct simpul
{
    int data;
    Dnode *prev, *next;
};

void alokasi();
void akhir();
void hapusAkhir();
void tampil();

Dnode *head = NULL, *p, *hapus;

int main()
{
    char jwb;

    puts("DLL Insert Akhir");
    do
    {
        fflush(stdin);
        alokasi();
        akhir();
        fflush(stdin);
        printf("Mau lagi (y/t) ? ");
        jwb = getchar();
    } while (jwb == 'Y' || jwb == 'y');
    tampil();
    fflush(stdin);
    printf("Mau Delete Akhir (y/t) ? ");
    jwb = getchar();
    if (jwb == 'Y' || jwb == 'y')
        hapusAkhir();
    tampil();
    return 0;
}

void hapusAkhir()
{
    hapus = head;
    while (hapus->next != NULL)
        hapus = hapus->next;
    if (hapus == head)
    {
        head = head->next;
    }
    else
    {
        hapus->prev->next = NULL;
    }
    free(hapus);
    hapus == NULL;
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

void akhir()
{
    Dnode *tail;

    tail = head;
    if (head == NULL)
        head = p;
    else
    {
        while (tail->next != NULL)
            tail = tail->next;
        p->prev = tail;
        tail->next = p;
        tail = p;
    }
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
