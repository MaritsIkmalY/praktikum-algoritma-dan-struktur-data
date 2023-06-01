#include<stdio.h>
#include<stdlib.h>

typedef struct simpul Dnode;
struct simpul{
    int data;
    Dnode *prev, *next;
};

void alokasi();
void akhir();
void tampil();

Dnode *head = NULL, *p;

int main(){
    char jwb;

    puts("DLL Insert Akhir");
    do{
        fflush(stdin);
        alokasi();
        akhir();
        fflush(stdin);
        printf("Mau lagi (y/t) ? ");
        jwb = getchar();
    }while(jwb == 'Y' || jwb == 'y');
    tampil();
    return 0;
}

void alokasi(){
    int x;

    printf("Data yang mau disimpan ? ");
    scanf("%d",&x);
    p = (Dnode *) malloc(sizeof(Dnode));
    if(p == NULL){
        puts("Pemesanan Gagal");
        exit(0);
    }
    else{
        p->data = x;
        p->next = NULL;
        p->prev = NULL;
    }
}

void akhir(){
    Dnode *tail;

    tail = head;
    if(head == NULL)
        head = p;
    else{
        while(tail->next != NULL)
            tail = tail->next;
        p->prev = tail;
        tail->next = p;
        tail = p;
    }

}

void tampil(){
    Dnode *baca;

    puts("Isi dari DLL");
    baca = head;
    while(baca != NULL){
        printf("%d\n",baca->data);
        baca = baca->next;
    }

}



