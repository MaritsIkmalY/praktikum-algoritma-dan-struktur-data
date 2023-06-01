#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAKS 255

typedef struct simpul node;
struct simpul
{
    char huruf;
    node *next;
};

node *head = NULL, *p, *hapus = NULL;

void push(char y);
char pop();
void alokasi(char y);
void pecah(char x[]);

int main()
{
    char kata[MAKS], jawab;

    puts("MENGECEK PALINDROM");
    do
    {
        int i = 0;
        fflush(stdin);
        printf("Masukkan kata yang dicek : ");
        gets(kata);
        fflush(stdin);
        pecah(kata);
        while (head != NULL)
        {
            if (pop() != kata[i])
            {
                printf("%s adalah bukan Palindrom", kata);
                puts(" ");
                while (head != NULL)
                    pop();
                break;
            }
            else
            {
                i++;
                if (i < strlen(kata))
                    continue;
            }
            printf("%s adalah PALINDROM", kata);
            puts(" ");
        }
        printf("Mau coba lagi (y/t) ? ");
        jawab = getchar();
    } while (toupper(jawab) == 'Y');
    return 0;
}

void pecah(char x[])
{
    for (int i = 0; i < strlen(x); i++)
        push(x[i]);
}

void alokasi(char y)
{
    p = (node *)malloc(sizeof(node));

    if (p == NULL)
    {
        printf("Failed to allocate");
        exit(0);
    }
    else
    {
        p->huruf = y;
        p->next = NULL;
    }
}

void push(char y)
{
    alokasi(y);
    if (head != NULL)
        p->next = head;
    head = p;
}

char pop()
{
    char y;

    hapus = head;
    y = hapus->huruf;
    head = head->next;
    free(hapus);
    hapus = NULL;
    return y;
}