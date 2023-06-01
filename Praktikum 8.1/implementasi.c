#include <stdio.h>
#include <stdlib.h>
#define MAKS 5

typedef char itemType;
typedef struct
{
	itemType nomor[MAKS];
	int front;
	int rear;
	int count;
} antrian;
