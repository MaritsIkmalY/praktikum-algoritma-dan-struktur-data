#include <stdio.h>
#include <stdlib.h>

typedef char itemType;
typedef struct simpul node;
struct simpul
{
    itemType data;
    node *next;
};

node *head = NULL, *p, *hapus = NULL;

void menu();
void alokasi(itemType x);
void enqueue();
void tampil();
void dequeue();

int main()
{
    int pilihan;

    do
    {
        fflush(stdin);
        menu();
        printf("\nPilihan Anda : ");
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
        default:
            puts("Invalid");
        }
    } while (pilihan != 4);
    return 0;
}

void menu()
{
    puts("MENU STACK using SINGLE LINKED LIST");
    puts("1. Mengisi Queue (ENQUEUE)");
    puts("2. Mengambil isi Queue (DEQUEUE)");
    puts("3. Menampilkan isi STACK -> FIFO");
    puts("4. Keluar");
}

void alokasi(itemType x)
{
    p = (node *)malloc(sizeof(node));

    if (p == NULL)
    {
        puts("Alokasi Gagal");
        exit(0);
    }
    else
    {
        p->data = x;
        p->next = NULL;
    }
}

void enqueue()
{
    fflush(stdin);
    itemType dataa;
    node *tail;

    printf("Masukkan datanya : ");
    scanf("%c", &dataa);
    alokasi(dataa);
    if (head == NULL)
        head = p;
    else
    {
        tail = head;
        while (tail->next != NULL)
            tail = tail->next;
        tail->next = p;
        tail = tail->next;
    }
    puts("Data berhasil ditambahkan\n");
}

void dequeue()
{
    if (head == NULL)
    {
        puts("Invalid");
        exit(0);
    }
    else
    {
        hapus = head;
        head = head->next;
        printf("Data yang diambil dari Stack = %c\n\n", hapus->data);
        free(hapus);
        hapus = NULL;
    }
}

void tampil()
{
    node *baca;

    baca = head;
    while (baca != NULL)
    {
        printf("%c\n", baca->data);
        baca = baca->next;
    }
    if (head == NULL)
    {
        puts("Empty");
    }
    puts(" ");
}
