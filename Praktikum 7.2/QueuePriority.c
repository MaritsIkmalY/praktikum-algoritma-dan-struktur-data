#include <stdio.h>
#include <stdlib.h>

typedef char itemType;
typedef struct simpul Dnode;
struct simpul
{
    itemType data;
    int priority;
    Dnode *next;
    Dnode *prev;
};

Dnode *head = NULL, *p, *hapus = NULL;

void dequeue();
void enqueue();
void tampil();
void menu();
void alokasi(itemType, int);
void awal();
void akhir();

int main()
{
    int pilihan;

    do
    {
        menu();
        printf("Masukkan pilihan Anda : ");
        scanf("%d", &pilihan);
        switch (pilihan)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            tampil();
            break;
        case 4:
            exit(0);
        }
    } while (pilihan != 4);
    return 0;
}

void menu()
{
    puts("MENU PRIORITY QUEUE using Linked List");
    puts("1. Mengisi Queue (ENQUEUE)");
    puts("2. Mengambil isi Queue (DEQUEUE)");
    puts("3. Menampilkan isi Queue");
    puts("4. Keluar");
}

void tampil()
{
    Dnode *baca;

    puts("\nIsi dari DLL");
    baca = head;
    while (baca != NULL)
    {
        printf("%c\n", baca->data);
        baca = baca->next;
    }
    if (head == NULL)
        puts("Kosong\n");
}

void alokasi(itemType data, int prioritas)
{
    p = (Dnode *)malloc(sizeof(Dnode));
    if (p == NULL)
    {
        puts("Pemesanan Gagal");
        exit(0);
    }
    else
    {
        p->data = data;
        p->priority = prioritas;
        p->prev = NULL;
        p->next = NULL;
    }
}

void dequeue()
{
    if (head == NULL)
    {
        puts("Data Kosong");
    }
    else
    {
        hapus = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        printf("Data yang diambil adalah %c\n", hapus->data);
        free(hapus);
        hapus = NULL;
    }
}

void enqueue()
{
    itemType kar;
    int priority;
    int static priorityMaks;
    Dnode *tunjuk;

    fflush(stdin);
    printf("Masukkan data Anda : ");
    scanf("%c", &kar);
    fflush(stdin);
    printf("Nilai Prioritasnya : ");
    scanf("%d", &priority);
    alokasi(kar, priority);
    if (head == NULL)
    {
        head = p;
        priorityMaks = p->priority; /*priorityMaks = 2*/
    }
    else if (head != NULL)
    {
        if (p->priority < priorityMaks)
        {
            priorityMaks = p->priority; /* 1 */
            awal();
        }
        else if (p->priority >= priorityMaks)
        {
            tunjuk = head;
            while (p->priority >= tunjuk->priority)
            {
                if (tunjuk->next == NULL)
                {
                    akhir();
                    break;
                }
                tunjuk = tunjuk->next;
            }
            if (p->priority < tunjuk->priority)
            {
                p->next = tunjuk;
                p->prev = tunjuk->prev;
                tunjuk->prev->next = p;
                tunjuk->prev = p;
            }
        }
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

void awal()
{
    if (head != NULL)
    {
        p->next = head;
        head->prev = p;
    }
    head = p;
}
