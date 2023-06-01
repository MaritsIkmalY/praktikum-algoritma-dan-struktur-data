#include <stdio.h>
#include <stdlib.h>
#define MAKS 25

typedef struct
{
    char angka[MAKS];
    int hitung;
} stack;

void startMenu();
int kosong(stack *);
int penuh(stack *);
int push(stack *);
void pop(stack *);
void tampil(stack *);

int main()
{
    stack tumpukan;
    tumpukan.hitung = 0;
    int pilih;

    do
    {
        startMenu();
        printf("\nMasukkan pilihan Anda : ");
        scanf("%d", &pilih);
        switch (pilih)
        {
        case 1:
            push(&tumpukan);
            break;
        case 2:
            pop(&tumpukan);
            break;
        case 3:
            tampil(&tumpukan);
            break;
        case 4:
            exit(0);
        default:
            puts("Wrong Choice !");
        }
    } while (pilih != 4);
    return 0;
}

void startMenu()
{
    puts("MENU STACK using ARRAY :");
    puts("1. Mengisi Stack (PUSH)");
    puts("2. Mengambil isi Stack (POP)");
    puts("3. Menampilkan isi Stack -> LIFO");
    puts("4. Keluar");
}

int penuh(stack *tumpuk)
{
    if (tumpuk->hitung == MAKS)
        return 1;
    else
        return 0;
}

int kosong(stack *tumpuk)
{
    if (tumpuk->hitung == 0)
        return 1;
    else
        return 0;
}

int push(stack *tumpuk)
{
    int bil;

    if (penuh(tumpuk))
    {
        fprintf(stderr, "Stack Overflow");
        exit(0);
    }
    else
    {
        printf("\nMasukkan data Anda : ");
        scanf("%d", &bil);
        tumpuk->angka[tumpuk->hitung++] = bil;
        puts("Data berhasil ditambahkan\n");
    }
}

void pop(stack *tumpuk)
{
    if (kosong(tumpuk))
    {
        fprintf(stderr, "Stack is Empty\n\n");
    }
    else
    {
        printf("\nItem yang Anda ambil adalah %d\n", tumpuk->angka[--tumpuk->hitung]);
        puts("Data berhasil diambil\n");
    }
}

void tampil(stack *tumpuk)
{
    if (kosong(tumpuk))
        fprintf(stderr, "Stack is Empty\n\n");
    else
    {
        puts("Isi stack saat ini adalah :");
        for (int i = tumpuk->hitung - 1; i >= 0; i--)
        {
            printf("%d\n", tumpuk->angka[i]);
        }
        puts(" ");
    }
}