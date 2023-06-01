#include<stdio.h>
#include<stdlib.h>

typedef struct simpul node;
struct simpul{
    int data;
    node *next;
};

node *head = NULL, *p;

void menu();
void masukkan();
void menghapus();
void alokasi();
void awal();
void akhir();
void setelah();
void sebelum();
void menghapus_awal();
void menghapus_akhir();
void menghapus_tertentu();
void tampil();

int main(){
    menu();

    return 0;

}

void menu(){
    int pilihan;

    do{
        puts("\nMenu SLL");
        puts("1. Insert");
        puts("2. Delete");
        puts("3. Keluar");
        printf("Masukkan Pilihan Anda : ");
        scanf("%d", &pilihan);
        if(head == NULL && pilihan == 2)
            puts("Tidak Bisa Melakukan Delete karena Data Kosong");
        else{
             switch(pilihan){
                case 1 :
                    masukkan();
                    break;
                case 2 :
                    menghapus();
                    break;
                case 3 :
                    exit(0);
                default :
                    puts("Pilih yang benar");
            }
        }
        tampil();
    }while(pilihan != 3);
}

void masukkan(){
    int pilih;

    puts("Menu Insert");
    puts("1. Awal");
    puts("2. Akhir");
    puts("3. Sebelum");
    puts("4. Sesudah");
insert:
    printf("Masukkan Pilihan Anda : ");
    scanf("%d",&pilih);
    if(head == NULL && pilih == 3 || head == NULL && pilih == 4){
        puts("Data masih kosong tidak bisa melakukan insert sebelum atau sesudah");
        goto insert;
    }
    else{
        switch(pilih){
            case 1 :
                alokasi();
                awal();
                break;
            case 2 :
                alokasi();
                akhir();
                break;
            case 3 :
                alokasi();
                sebelum();
                break;
            case 4 :
                alokasi();
                setelah();
                break;
            default :
                puts("Pilih yang benar");
                goto insert;
        }
    }
}

void menghapus(){
    int jawab;

    puts("Menu Delete");
    puts("1. Awal");
    puts("2. Akhir");
    puts("3. Tertentu");
hapus:
    printf("Masukkan Pilihan Anda : ");
    scanf("%d",&jawab);
    switch(jawab){
        case 1 :
            menghapus_awal();
            break;
        case 2 :
            menghapus_akhir();
            break;
        case 3 :
            menghapus_tertentu();
            break;
        default :
            puts("Pilih yang benar");
            goto hapus;
    }

}

void menghapus_tertentu(){
    int key;
    node *hapus, *phapus;

input:
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
                goto input;
            }
        }
        phapus->next = hapus->next;
    }
    free(hapus);
    hapus == NULL;
}

void menghapus_akhir(){
    node *hapus, *phapus;

    hapus = head;
    while(hapus->next != NULL){
        phapus = hapus;
        hapus = hapus->next;
    }
    if(hapus == head)
        head = NULL;
    else
        phapus->next = NULL;
    free(hapus);
    hapus == NULL;
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

sesudah:
    printf("Disisipkan setelah data berapa ? ");
    scanf("%d",&key);
    after = head;
    while(after->data != key){
        if(after->next == NULL){
            printf("%d tidak ditemukan di dalam SLL\n",key);
            goto sesudah;
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

before:
    printf("Disisipkan sebelum data berapa ? ");
    scanf("%d",&key);
    bef = head;
    while(bef->data != key){
        if(bef->next == NULL){
            printf("%d tidak ditemukan di dalam SLL\n",key);
            goto before;
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
    if(head == NULL)
        puts("Kosong\n");
}

