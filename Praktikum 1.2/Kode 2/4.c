#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct employee_st
{
    char name[40];
    int id;
} Employee;

int main()
{
    Employee *workers, *wpt;
    int num, i;

    printf("How many employees do you want ? ");
    scanf("%d", &num);
    workers = (Employee *)malloc(num * sizeof(Employee));
    if (workers == NULL)
    {
        printf("Unable to allocated space for employees\n");
        exit(0);
    }
    wpt = workers;
    for (i = 1; i <= num; i++)
    {
        fflush(stdin);
        printf("Employee's name : ");
        gets(wpt->name);
        printf("Employee's id : ");
        scanf("%d", &wpt->id);
        wpt++;
    }
    puts("");
    wpt = workers;
    for (i = 1; i <= num; i++)
    {
        printf("Employee %d is %s\n", wpt->id, wpt->name);
        wpt++;
    }
    printf("%p\n",workers);
    printf("%p\n",wpt);
    free(workers);
    workers = NULL;
    printf("%p\n",wpt);
}
