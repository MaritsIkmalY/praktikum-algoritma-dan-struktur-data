#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define MAKS 5

typedef char itemType;
typedef struct
{
    itemType data[MAKS];
    int count;
    int front;
    int rear;
} queue;

void menu();
void enqueue(queue *);
void dequeue(queue *);
void inisialisasi(queue *);
void tampil(queue *);
void start(queue *);

int main()
{
    queue antri;

    inisialisasi(&antri);
    start(&antri);
    return 0;
}

void start(queue *data)
{
    int pilihan;

    do
    {
        fflush(stdin);
        menu();
        printf("Masukkan pilihan Anda : ");
        scanf("%d", &pilihan);
        switch (pilihan)
        {
        case 1:
            enqueue(data);
            break;
        case 2:
            dequeue(data);
            break;
        case 3:
            tampil(data);
            break;
        case 4:
            exit(0);
        }
    } while (pilihan != 4);
}

void menu()
{
    puts("MENU QUEUE USING ARRAY:");
    puts("1. Mengisi Queue (ENQUEUE)");
    puts("2. Mengambil isi Queue (DEQUEUE)");
    puts("3. Menampilkan isi -> FIFO");
    puts("4. Keluar");
}

void inisialisasi(queue *tunjuk)
{
    tunjuk->count = 0;
    tunjuk->front = -1;
    tunjuk->rear = -1;
}

void enqueue(queue *tunjuk)
{
    fflush(stdin);
    itemType kar;

    if (tunjuk->count == MAKS)
    {
        puts("STOP!!!");
        puts("Queue Penuh! Data terakhir gak bs masuk!\n");
        return start(tunjuk);
    }
    else if (tunjuk->count == 0)
    {
        tunjuk->front = 0;
        tunjuk->rear = 0;
    }
    else
    {
        tunjuk->rear == ++tunjuk->rear;
        if (tunjuk->rear == MAKS)
            tunjuk->rear = 0;
    }
    printf("Masukkan data Anda: ");
    scanf("%c", &kar);
    tunjuk->data[tunjuk->rear] = kar;
    tunjuk->count++;
    puts(" ");
}

void dequeue(queue *tunjuk)
{
    itemType kar;

    if (tunjuk->count == 0)
    {
        puts("STOP!!!");
        puts("Tidak bisa Mengambil Data\n");
        return start(tunjuk);
    }
    kar = tunjuk->data[tunjuk->front];
    if (tunjuk->count == 1)
    {
        tunjuk->front = -1;
        tunjuk->rear = -1;
    }
    else
    {
        tunjuk->front = ++tunjuk->front;
        if (tunjuk->front == MAKS)
            tunjuk->front = 0;
    }
    tunjuk->count--;
    printf("Data yang anda ambil adalah : %c\n\n", kar);
}

void tampil(queue *tunjuk)
{
    int temp = tunjuk->front;
    if (tunjuk->count == 0)
        puts("Kosong\n");
    else
    {
        for (int i = 0; i < tunjuk->count; i++)
        {
            printf("%c\n", tunjuk->data[temp]);
            temp = ++temp;
            if (temp == MAKS)
                temp = 0;
        }
    }
}