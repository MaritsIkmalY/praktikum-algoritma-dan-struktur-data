#include <stdio.h>

int fakt(int);
int permutasi(int, int);
int kombinasi(int, int);

int main()
{

    int n, r;

    printf("n = ");
    scanf("%d", &n);
    printf("r = ");
    scanf("%d", &r);
    printf("P(%d, %d) = %d\n", n, r, permutasi(n, r));
    printf("C(%d, %d) = %d\n", n, r, kombinasi(n, r));

    return 0;
}

int fakt(int x)
{
    if (x < 0)
        return 0;
    else if (x == 0 || x == 1)
        return 1;
    else
        return x * fakt(x - 1);
}

int permutasi(int n, int r)
{
    return fakt(n) / fakt(n - r);
}

int kombinasi(int n, int r)
{
    return fakt(n) / (fakt(r) * fakt(n - r));
}
