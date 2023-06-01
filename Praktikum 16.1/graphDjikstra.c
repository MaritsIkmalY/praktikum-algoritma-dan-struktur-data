#include <stdio.h>
#include <stdlib.h>
#define n 5
#define M 99999

typedef int itemType;
typedef struct
{
    int data[n];
    int front;
    int rear;
    int count;
} queue;

void inisialisasi(queue *);
void enqueue(itemType, queue *);
itemType dequeue(queue *);
int in_queue(int, queue *);
void tampil(int[][n]);
void djikstra(int, int, int[][n]);

int main()
{
    int asal, tujuan;
    int Q[n][n] = {
        {M, 1, 3, M, M},
        {M, M, 1, M, 5},
        {3, M, M, 2, M},
        {M, M, M, M, 1},
        {M, M, M, M, M}};

    puts("Graph DJIKSTRA");
    puts("\nMatriks Beban Asal(Q) : ");
    tampil(Q);

    printf("\nMasukkan asal: ");
    scanf("%d", &asal);
    printf("Masukkan tujuan: ");
    scanf("%d", &tujuan);

    djikstra(asal, tujuan, Q);
    return 0;
}

void djikstra(int origin, int destin, int beban[][n])
{
    int TQ[n], R[n], cn, i, cepat[n];
    queue antrian;

    // inisialisasi TQ
    for (int i = 0; i < n; i++)
    {
        if (i == origin - 1)
            TQ[i] = 0;
        else
            TQ[i] = M;
    }

    // inisialisasi R
    for (int i = 0; i < n; i++)
        R[i] = -1;

    // inisialisasi queue
    inisialisasi(&antrian);
    enqueue(origin - 1, &antrian);
    while (antrian.count != 0)
    {
        cn = dequeue(&antrian);
        i = 0;
        while (i < n)
        {
            if (beban[cn][i] != M)
            {
                if ((beban[cn][i] + TQ[cn]) < TQ[i])
                {
                    TQ[i] = beban[cn][i] + TQ[cn];
                    // printf("accessed\n");
                    R[i] = cn;
                    if (i != origin - 1 && i != destin - 1 && !in_queue(i, &antrian))
                    {
                        // printf("if akses\n");
                        enqueue(i, &antrian);
                    }
                }
            }
            i++;
        }
    }

    printf("\nMatriks TQ : ");
    for (i = 0; i < n; i++)
    {
        if (TQ[i] == 99999)
            printf("M ");
        else
            printf("%d ", TQ[i]);
    }

    printf("\nMatriks R : ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", R[i]);
    }

    puts("\nRute Tercepat");
    cepat[destin - 1] = destin;
    if (origin > destin)
    {
        int j = destin - 1;
        cepat[0] = origin;
        while (j != 0)
        {
            printf("%d", R[destin]);
            cepat[j--] = R[destin] - 1;
            j--;
        }
    }
    else
    {
        int i = destin - 1;
        while (R[i] != -1)
        {
            cepat[i - 1] = R[i] + 1;
            i--;
        }
    }
    if (origin > destin)
    {
        for (int i = 0; i < destin + 1; i++)
        {
            printf("%d ", cepat[i]);
        }
    }
    else
    {
        for (int i = origin - 1; i < destin; i++)
        {
            printf("%d ", cepat[i]);
        }
    }

    printf("\n Beban Total = %d\n", TQ[destin - 1]);
}

void inisialisasi(queue *tunjuk)
{
    tunjuk->count = 0;
    tunjuk->front = -1;
    tunjuk->rear = -1;
}

void enqueue(itemType x, queue *tunjuk)
{
    if (tunjuk->count == n)
    {
        puts("STOP!!!");
        puts("Queue Penuh! Data terakhir gak bs masuk!\n");
    }
    else if (tunjuk->count == 0)
    {
        tunjuk->front = 0;
        tunjuk->rear = 0;
    }
    else
    {
        tunjuk->rear == ++tunjuk->rear;
        if (tunjuk->rear == n)
            tunjuk->rear = 0;
    }
    tunjuk->data[tunjuk->rear] = x;
    tunjuk->count++;
    puts(" ");
}

itemType dequeue(queue *tunjuk)
{
    itemType kar;

    if (tunjuk->count == 0)
    {
        puts("STOP!!!");
        puts("Tidak bisa Mengambil Data\n");
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
        if (tunjuk->front == n)
            tunjuk->front = 0;
    }
    tunjuk->count--;
    return kar;
}

int in_queue(int x, queue *tunjuk)
{
    int current_front = tunjuk->front, current_count = tunjuk->count;
    if (tunjuk->count == 0)
        return 0;
    else
    {
        while (current_count != 0)
        {
            if (tunjuk->data[current_front] == x)
                return 1;
            current_front++;
            if (current_front == n)
                current_front = 0;
            current_count--;
        }
    }
    return 0;
}

void tampil(int beban[][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (beban[i][j] == M)
                printf("M ");
            else
                printf("%d ", beban[i][j]);
        }
        puts("");
    }
}