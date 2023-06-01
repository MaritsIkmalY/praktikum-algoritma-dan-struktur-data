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
void hapusTertentu();
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
    printf("Mau Delete Node Tertentu (y/t) ? ");
    jwb = getchar();
    if (jwb == 'Y' || jwb == 'y')
        hapusTertentu();
    tampil();
    return 0;
}

void hapusTertentu()
{
    int key;

    hapus = head;
    printf("Data yang mau dihapus ? ");
    scanf("%d", &key);
    if (hapus->data == key)
    {
        head = head->next;
        if (head != NULL)
            head->prev == NULL;
    }
    else
    {
        while (hapus->data != key)
        {
            if (hapus->next == NULL)
            {
                printf("Data %d tidak ada di dalam DLL\n", key);
                exit(0);
            }
            hapus = hapus->next;
        }
        if (hapus->next == NULL)
            hapus->prev->next = NULL;
        else
        {
            hapus->prev->next = hapus->next;
            hapus->next->prev = hapus->prev;
        }
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
    if (head == NULL)
        puts("DLL Kosong");
}
