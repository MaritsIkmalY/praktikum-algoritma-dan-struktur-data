#include <stdio.h>
#include <stdlib.h>
#define M 9999

typedef int itemType;
typedef struct
{
    itemType data[M];
    int count;
} stack;
int n;

void tampil(int[][n], int[][n], int[][n]);
void warshall(int[][n], int[][n], int[][n]);
void find_short_route(int[][n], int[][n]);
void initialize(stack *);
void push(itemType, stack *);
void pop(stack *);
void input(int[][n], int[][n], int[][n]);

int main()
{
input:
    printf("Mau berapa node ? ");
    scanf("%d", &n);
    if (n <= 1)
    {
        puts("node harus lebih dari 1");
        goto input;
    }
    printf("node diset dari %d - %d\n", 1, n);
    int Q[n][n], P[n][n], R[n][n];

    input(Q, P, R);

    puts("Graph - Warshall");
    puts("Matriks Q-P-R asal");
    tampil(Q, P, R);

    warshall(Q, P, R);

    puts("\nMatriks Q-P-R baru");
    tampil(Q, P, R);

    find_short_route(R, Q);

    return 0;
}

void input(int beban[][n], int jalur[][n], int rute[][n])
{
    char set_jalur;
    int set_beban;

    // inisialisasi jalur
    puts("\nInisialisasi Jalur");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                fflush(stdin);
                printf("Apakah ada jalur langsung dari %d ke %d (y/t): ", i + 1, j + 1);
                set_jalur = getchar();

                if (set_jalur == 'y' || set_jalur == 'Y')
                {
                    jalur[i][j] = 1;
                    rute[i][j] = 0;
                }
                else
                {
                    jalur[i][j] = 0;
                    rute[i][j] = M;
                }
            }
            else
            {
                jalur[i][j] = 0;
                rute[i][j] = M;
            }
        }
    }

    // inisialisasi beban
    puts("\nInisialisasi Beban");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (jalur[i][j] == 1)
            {
                printf("Berapa beban dari %d ke %d : ", i + 1, j + 1);
                scanf("%d", &set_beban);
                beban[i][j] = set_beban;
            }
            else
            {
                beban[i][j] = M;
            }
        }
    }
}

void warshall(int beban[][n], int jalur[][n], int rute[][n])
{
    int k, i, j;
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {

                // new jalur
                jalur[i][j] = jalur[i][j] || (jalur[i][k] && jalur[k][j]);

                if ((beban[i][k] + beban[k][j]) < beban[i][j])
                {
                    // new rute
                    if (rute[k][j] == 0)
                        rute[i][j] = k + 1;
                    else
                        rute[i][j] = rute[k][j];

                    // new beban
                    beban[i][j] = beban[i][k] + beban[k][j];
                }
            }
        }
    }
}

void find_short_route(int route[][n], int beban[][n])
{
    stack short_route;
    int origin, destin, temp;

    initialize(&short_route);

    printf("Masukkan nilai asal : ");
    scanf("%d", &origin);
    printf("Masukkan nilai tujuan : ");
    scanf("%d", &destin);

    push(destin, &short_route);
    temp = route[origin - 1][destin - 1];
    while (temp != 0)
    {
        if (temp == M)
        {
            puts("Rute tidak tersedia");
            exit(0);
        }
        else
        {
            push(temp, &short_route);
            temp = route[origin - 1][temp - 1];
        }
    }
    push(origin, &short_route);

    printf("Rute yang terpendek adalah : ");
    while (short_route.count != 0)
    {
        pop(&short_route);
        printf(" ");
    }
    puts("");

    printf("beban : %d\n", beban[origin - 1][destin - 1]);
}

void initialize(stack *s)
{
    s->count = 0;
}

void push(itemType data, stack *s)
{
    if (s->count == M)
        puts("Stack Penuh, tidak dapat memasukkan data lagi");
    else
    {
        s->data[s->count] = data;
        s->count++;
    }
}

void pop(stack *s)
{
    itemType x;
    if (s->count == 0)
    {
        puts("Stack kosong, tidak ada data");
    }
    else
    {
        x = s->data[--s->count];
        printf("%d", x);
    }
}

void tampil(int beban[][n], int jalur[][n], int rute[][n])
{

    puts("Matriks Beban (Q)");
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

    puts("\nMatriks Jalur (P)");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (jalur[i][j] == M)
                printf("M ");
            else
                printf("%d ", jalur[i][j]);
        }
        puts("");
    }

    puts("\nMatriks Rute (R)");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (rute[i][j] == M)
                printf("M ");
            else
                printf("%d ", rute[i][j]);
        }
        puts("");
    }
}