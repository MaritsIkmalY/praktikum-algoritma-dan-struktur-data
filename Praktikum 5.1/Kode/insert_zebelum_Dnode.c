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
void tampil();
void sebelum();

Dnode *head = NULL, *p;

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
    puts("Insert Before");
    alokasi();
    sebelum();
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

void sebelum()
{
    int key;
    Dnode *before;

    printf("Sisip before brp ? ");
    scanf("%d", &key);
    before = head;
    while (before->data != key)
    {
        if (before->next == NULL)
        {
            puts("Data Tidak ada dalam DLL");
            exit(0);
        }
        before = before->next;
    }
    p->next = before;
    if (before->prev == NULL)
        head = p;
    else
    {
        before->prev->next = p;
        p->prev = before->prev;
    }

    before->prev = p;
}

void tampil()
{
    Dnode *baca;

    puts("\nIsi dari DLL");
    baca = head;
    while (baca != NULL)
    {
        printf("%d\n", baca->data);
        baca = baca->next;
    }
}
