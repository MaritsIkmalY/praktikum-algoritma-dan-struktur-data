#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAKS 50

typedef struct
{
    char operasi[MAKS];
    int hitung;
} stack;

void info();
int prioritas(char x);
void push(stack *operator, char x);
char pop(stack *operator);

int main()
{
    stack tumpukan;
    tumpukan.hitung = 0;
    char *p, ekspresi[MAKS], temp;
    int i, cek = 0;

    info();
    printf("Masukkan Ekspresi dalam notasi infix : ");
    gets(ekspresi);
    p = ekspresi;

    while (*p != '\0')
    {
        if (isalnum(*p))
            printf("%c", *p);
        else if (*p == '(')
            push(&tumpukan, *p);
        else if (*p == ')')
        {
            while ((temp = pop(&tumpukan)) != '(')
                printf("%c", temp);
        }
        else if (*p == ' ')
        {
            i++;
            cek++;
            if (i != 2)
                printf("%c", *p);
            else
                i = 0;
        }
        else
        {
            while (prioritas(tumpukan.operasi[tumpukan.hitung - 1]) >= prioritas(*p))
            {
                if (cek > 0)
                    printf("%c ", pop(&tumpukan));
                else
                    printf("%c", pop(&tumpukan));
            }
            push(&tumpukan, *p);
        }
        p++;
    }

    while (tumpukan.hitung != 0)
    {
        if (cek > 0)
            printf(" %c", pop(&tumpukan));
        else
            printf("%c", pop(&tumpukan));
    }

    return 0;
}

void info()
{
    puts("Mengubah Notasi Infix Menjadi Postfix");
    puts("Dengan Memanfaatkan Struktur Stack");
}

void push(stack *operator, char x)
{
    operator->operasi[operator->hitung++] = x;
}

char pop(stack *operator)
{
    if (operator->hitung == 0)
        return -1;
    else
        return operator->operasi[--operator->hitung];
}

int prioritas(char x)
{
    if (x == '(')
        return 0;
    else if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
}
