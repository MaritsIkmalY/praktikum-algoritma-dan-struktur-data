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
void setelah();

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
    puts("Insert After");
    alokasi();
    setelah();
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

void setelah()
{
    int key;
    Dnode *after;

    printf("Sisip after brp ? ");
    scanf("%d", &key);
    after = head;
    while (after->data != key)
    {
        if (after->next == NULL)
        {
            puts("Data Tidak ada dalam DLL");
            exit(0);
        }
        after = after->next;
    }
    p->next = after->next;
    p->prev = after;
    if (after->next != NULL)
        after->next->prev = p;
    after->next = p;
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
