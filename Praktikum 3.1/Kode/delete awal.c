#include<stdio.h>
#include<stdlib.h>

typedef struct simpul node;
struct simpul{
    int data;
    node *next;
};

node *head = NULL, *p;

void alokasi();
void akhir();
void tampil();
void menghapus_awal();

int main(){
    char jawab;

    puts("Single Linked List - Insert Akhir - Delete Awal");
    do{
        fflush(stdin);
        alokasi();
        akhir();
        fflush(stdin);
        printf("Lagi (y/t)? ");
        jawab = getchar();
    }while(jawab == 'y' || jawab == 'Y');
    tampil();
    while(head != NULL){
        puts("\nMenghapus data posisi awal ...");
        menghapus_awal();
        tampil();
    }
    return 0;
}

void menghapus_awal(){
    node *hapus;

    hapus = head;
    head = hapus->next;
    free(hapus);
    hapus == NULL;
}

void alokasi(){
    int bilangan;

    printf("Nilai yang akan disimpan : ");
    scanf("%d",&bilangan);
    p = (node *)malloc(sizeof(node));
    if(p == NULL){
        puts("Gagal memesam alamat");
        exit(0);
    }
    else{
        p->data = bilangan;
        p->next = NULL;
    }
}

void akhir(){
    node *tail;

    if(head == NULL)
        head = p;
    else{
        tail = head;
        while(tail->next != NULL)
            tail = tail->next;
        tail->next = p;
        tail = tail->next;
    }
}

void tampil(){
    node *baca;

    baca = head;
    puts("");
    puts("Isi dari SLL");
    while(baca != NULL){
        printf("%d\n", baca->data);
        baca = baca->next;
    }
    if(head == NULL)
        puts("Kosong");
}



