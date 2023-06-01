#include <stdio.h>
#include <stdlib.h>

typedef struct simpul node;
struct simpul
{
    int angka;
    node *next;
};

node *head = NULL, *p, *hapus = NULL;

void menu();
void alokasi(int x);
void push();
void tampil();
void pop();

int main()
{
    int pilihan;

    do
    {
        menu();
        printf("\nPilihan Anda : ");
        scanf("%d", &pilihan);
        switch (pilihan)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
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
    puts("1. Mengisi STACK (PUSH)");
    puts("2. Mengambil isi STACK (POP)");
    puts("3. Menampilkan isi STACK -> LIFO");
    puts("4. Keluar");
}

void alokasi(int x)
{
    p = (node *)malloc(sizeof(node));

    if (p == NULL)
    {
        puts("Alokasi Gagal");
        exit(0);
    }
    else
    {
        p->angka = x;
        p->next = NULL;
    }
}

void push()
{
    int bilangan;

    printf("Masukkan datanya : ");
    scanf("%d", &bilangan);
    alokasi(bilangan);
    if (head != NULL)
        p->next = head;
    head = p;
    puts("Data berhasil ditambahkan\n");
}

void pop()
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
        printf("Data yang diambil dari Stack = %d\n\n", hapus->angka);
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
        printf("%d\n", baca->angka);
        baca = baca->next;
    }
    if (head == NULL)
    {
        puts("Empty");
    }
    puts(" ");
}
