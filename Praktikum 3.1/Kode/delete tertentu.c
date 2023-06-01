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
void menghapus_tertentu();

int main(){
    char jawab;

    puts("Single Linked List - Insert Akhir - Delete Node Tertentu");
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
        menghapus_tertentu();
        tampil();
    }
    return 0;
}

void menghapus_tertentu(){
    int key;
    node *hapus, *phapus;

    printf("Masukkan Node berapa yang ingin dihapus : ");
    scanf("%d", &key);
    hapus = head;
    if(hapus->data == key){
        head = hapus->next;
    }
    else{
        while(hapus->data != key){
            if(hapus->next != NULL){
                phapus = hapus;
                hapus = hapus->next;
            }
            else{
                printf("%d tidak ada di dalam SLL\n", key);
                exit(0);
            }
        }
        phapus->next = hapus->next;
    }
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





