#include<stdio.h>
#include<stdlib.h>

typedef struct simpul node;
struct simpul{
    int data;
    node *next;
};

node *head = NULL, *p;

void alokasi();
void awal();
void akhir();
void setelah();
void sebelum();
void tampil();
int pemilihan(int);

int main(){
    int pilih;

    puts("Single Linked List - Insert Menu");
    do{
        pilih = pemilihan(pilih);
        if(pilih == 1)
            awal();
        else if(pilih == 2)
            akhir();
        alokasi();
        tampil();
    }while(pilih != 5);
    exit(0);
    return 0;
}

int pemilihan(int jawab){
    if(jawab == 1)
        return 1;
    else if(jawab == 2)
        return 2;
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

void awal(){
    if(head != NULL)
        p->next = head;
    head = p;
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

void setelah(){
    int key;
    node *after;

    printf("Disisipkan setelah node : ");
    scanf("%d",&key);
    after = head;
    while(after->data != key){
        if(after->next == NULL){
            printf("Data Tidak Ditemukan");
            exit(0);
        }
        else{
            after = after->next;
        }
    }
        p->next = after->next;
        after->next = p;
}

void sebelum(){
    int key;
    node *bef, *pbef;

    printf("Disisipkan sebelum node : ");
    scanf("%d",&key);
    bef = head;
    while(bef->data != key){
        if(bef->next == NULL){
            printf("Data Tidak Ditemukan");
            exit(0);
        }
        else{
            pbef = bef;
            bef = bef->next;
        }
    }
    if(bef == head){
        p->next = bef;
        head = p;
    }
    else{
        p->next = bef;
        pbef->next = p;
    }
}

void tampil(){
    node *baca;

    baca = head;
    puts("");
    puts("Data yang ada dalam SLL");
    while(baca != NULL){
        printf("%d\n", baca->data);
        baca = baca->next;
    }
}

