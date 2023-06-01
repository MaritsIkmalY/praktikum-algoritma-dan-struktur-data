#include <stdio.h>
#include <stdlib.h>

typedef struct simpul node;
struct simpul
{
    int konversi;
    node *next;
};

node *head = NULL, *p, *hapus = NULL;

void push(int y);
int pop();
void menu();
void alokasi(int y);
void biner(int x);
void oktal(int x);
void heksadesimal(int x);

int main()
{
    int desimal, pilihan;

    puts("KONVERSI BILANGAN DESIMAL");
    printf("Masukkan bil desimal yang akan dikonversi : ");
    scanf("%d", &desimal);
    do
    {
        menu();
        printf("Masukkan pilihan anda : ");
        scanf("%d", &pilihan);
        switch (pilihan)
        {
        case 1:
            biner(desimal);
            break;
        case 2:
            oktal(desimal);
            break;
        case 3:
            heksadesimal(desimal);
            break;
        case 4:
            exit(0);
        default:
            puts("Invalid");
        }
        while (head != NULL)
            printf("%d", pop());
        puts(" ");
    } while (pilihan != 4);
    return 0;
}

void menu()
{
    puts("MENU KONVERSI");
    puts("1. Biner");
    puts("2. Oktal");
    puts("3. Heksadesimal");
    puts("4. Keluar");
}

void alokasi(int y)
{
    p = (node *)malloc(sizeof(node));

    if (p == NULL)
    {
        printf("Failed to allocate");
        exit(0);
    }
    else
    {
        p->konversi = y;
        p->next = NULL;
    }
}

void push(int y)
{
    alokasi(y);
    if (head != NULL)
        p->next = head;
    head = p;
}

int pop()
{
    int y;

    hapus = head;
    y = hapus->konversi;
    head = head->next;
    free(hapus);
    hapus = NULL;
    return y;
}

void biner(int x)
{
    int temp = x;
    while (temp >= 1)
    {
        push(temp % 2);
        temp = temp / 2;
    }
    printf("Hasil Konversi %d ke Biner = ", x);
}

void oktal(int x)
{
    int temp = x;

    while (temp >= 1)
    {
        push(temp % 8);
        temp /= 8;
    }
    printf("Hasil Konversi %d ke oktal = ", x);
}

void heksadesimal(int x)
{
    int temp = x;

    while (temp >= 1)
    {
        push(temp % 16);
        temp /= 16;
    }
    printf("Hasil Konversi %d ke Biner = ", x);
}