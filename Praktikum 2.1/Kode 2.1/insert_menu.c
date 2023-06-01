#include<stdio.h>
#include<stdlib.h>

typedef struct simpul node;
struct simpul{
    int data;
    node *next;
};

node *head = NULL, *p;

int menu(int);
void alokasi();
void awal();
void akhir();
void setelah();
void sebelum();
void tampil();

int i;
int main(){
    int jawab;

    puts("Single Linked List - Insert Menu");
    while(jawab != 5){
        jawab = menu(jawab);
        if(jawab > 0 && jawab <= 5){
            alokasi();
            switch(jawab){
                case 1 :
                    awal();
                    break;
                case 2 :
                    akhir();
                    break;
                case 3 :
                    setelah();
                    break;
                case 4 :
                    sebelum();
                    break;
            }
            tampil();
            puts("");
            i++;
        }
        else if(jawab == 6)
            puts("SLL masih kosong, tidak bisa insert after\n");
        else if(jawab == 7)
            puts("SLL masih kosong, tidak bisa insert before\n");
        else
            puts("Pilih Yang Benar SHEESSHH");
        puts("");
    }
    return 0;

}

int menu(int pilih){
    puts("Menu Insert");
    puts("1. Awal");
    puts("2. Akhir");
    puts("3. After");
    puts("4. Before");
    puts("5. Keluar");
    printf("Masukkan Pilihan Anda : ");
    scanf("%d",&pilih);
    if(i == 0 && pilih == 3)
        return 6;
    else if(i == 0 && pilih == 4)
        return 7;
    else{
        switch(pilih){
            case 1:
                return 1;
                break;
            case 2:
                return 2;
                break;
            case 3:
                return 3;
                break;
            case 4:
                return 4;
                break;
            case 5:
                exit(0);
                break;
            default:
                return 8;
    }
    }

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

    printf("Disisipkan setelah data berapa ? ");
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

    printf("Disisipkan sebelum data berapa ? ");
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
        printf("%d\n",baca->data);
        baca = baca->next;
    }
}

