#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define MAKS 5

typedef int itemType;
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
void minMax(queue *);
void cari(queue *);

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
            minMax(data);
            break;
        case 4:
            cari(data);
            break;
        case 5:
            tampil(data);
            break;
        case 6:
            exit(0);
        }
    } while (pilihan != 6);
}

void menu()
{
    puts("MENU QUEUE USING ARRAY:");
    puts("1. Mengisi Queue (ENQUEUE)");
    puts("2. Mengambil isi Queue (DEQUEUE)");
    puts("3. Tampilkan data min dan max");
    puts("4. Cari data");
    puts("5. Menampilkan isi -> FIFO");
    puts("6. Keluar");
}

void inisialisasi(queue *tunjuk)
{
    tunjuk->count = 0;
    tunjuk->front = -1;
    tunjuk->rear = -1;
}

void cari(queue *tunjuk)
{
    int temp = tunjuk->front;
    int cari, valid = 1;

    if (tunjuk->count == 0)
        puts("Kosong\n");
    else
    {
        printf("Data yang dicari : ");
        scanf("%d", &cari);
        for (int i = 0; i < tunjuk->count; i++)
        {
            if (cari == tunjuk->data[temp])
            {
                printf("%d ada di dalam QUEUE\n\n", cari);
                valid = 0;
                break;
            }
            temp = ++temp;
            if (temp == MAKS)
                temp = 0;
        }
        if (valid)
            printf("%d tidak ada di dalam QUEUE\n\n", cari);
    }
}

void minMax(queue *tunjuk)
{
    int temp = tunjuk->front;
    int min, max;

    if (tunjuk->count == 0)
        puts("Kosong\n");
    else
    {
        min = tunjuk->data[temp];
        max = tunjuk->data[temp];
        for (int i = 0; i < tunjuk->count; i++)
        {
            if (tunjuk->data[temp] < min)
                min = tunjuk->data[temp];
            if (tunjuk->data[temp] > max)
                max = tunjuk->data[temp];
            temp = ++temp;
            if (temp == MAKS)
                temp = 0;
        }
        printf("Data terkecil = %d\n", min);
        printf("Data terbesar = %d\n\n", max);
    }
}

void enqueue(queue *tunjuk)
{
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
    scanf("%d", &kar);
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
    printf("Data yang anda ambil adalah : %d\n\n", kar);
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
            printf("%d\n", tunjuk->data[temp]);
            temp = ++temp;
            if (temp == MAKS)
                temp = 0;
        }
    }
}