#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Dnode;
struct simpul
{
    int data;
    Dnode *prev, *next;
};

void menu();
void alokasi();
void awal();
void akhir();
void setelah();
void sebelum();
void tampil();

Dnode *head = NULL, *p;

int main()
{
    menu();

    return 0;
}

void menu()
{
    int pilih;

    do
    {
        puts("Menu Insert");
        puts("1. Insert Awal");
        puts("2. Insert Akhir");
        puts("3. Insert After");
        puts("4. Insert Before");
        puts("5. Keluar");
        printf("Masukkan pilihan Anda : ");
        scanf("%d", &pilih);
        if (head == NULL && pilih == 3 || head == NULL && pilih == 4)
        {
            puts("Tidak bisa melakukan insert after dan before karena DLL masih kosong");
            exit(0);
        }
        else
        {
            if (pilih != 5)
                alokasi();
            switch (pilih)
            {
            case 1:
                awal();
                break;
            case 2:
                akhir();
                break;
            case 3:
                setelah();
                break;
            case 4:
                sebelum();
                break;
            case 5:
                exit(0);
            }
        }
        tampil();
    } while (pilih != 5);
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

void setelah()
{
    Dnode *after;
    int key;

    printf("Sisip after brp ? ");
    scanf("%d", &key);
    after = head;
    while (after->data != key)
    {
        if (after->next == NULL)
        {
            printf("%d tidak ada di DLL\n", key);
            exit(0);
        }
        after = after->next;
    }
    p->next = after->next;
    if (after->next != NULL)
        after->next->prev = p;
    after->next = p;
    p->prev = after;
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

    puts("\nIsi dari DLL");
    baca = head;
    while (baca != NULL)
    {
        printf("%d\n", baca->data);
        baca = baca->next;
    }
    puts("");
    if (head == NULL)
        puts("Kosong");
}
