#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    int id, nilai;
    char nama[25];
}emp;

typedef struct simpul node;
struct simpul{
    emp employees;
    node *next;
};
 node *head=NULL, *p, *tail;

void input(emp *);
void tampil();
void akhir();
void alokasi();
void setelah();


int main(){
    char jwb;

    puts("Linked List untuk aplikasi INSERT AFTER");
    puts("Membentuk linked list dengan Insert di akhir");
    do{
        fflush(stdin);
        alokasi();
        akhir();
        fflush(stdin);
        printf("Ada data lagi (y/t)? ");
        jwb=getchar();
        puts("");
    }while(jwb=='y');
    fflush(stdin);
    printf("\nIngin memasukkan data setelah ttt (y/t) ? ");
    jwb = getchar();
    fflush(stdin);
    if(jwb == 'y'){
        alokasi();
        setelah();
        puts("");
        tampil();
    }
    return 0;
}

void setelah(){
    int key;
    node *after;

    printf("Data tsb disisipkan setelah nomor berapa : ");
    scanf("%d",&key);
    after = head;
    while(after->employees.id != key){
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

void alokasi(){
    emp pegawai;

    input(&pegawai);
    p=(node *)malloc(sizeof(node));
    if(p == NULL)
        exit(0);
    else{
        p->employees.id = pegawai.id;
        strcpy(p->employees.nama, pegawai.nama);
        p->employees.nilai = pegawai.nilai;
        p->next=NULL;
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
    puts("Data yang telah diinputkan :");
    puts("No\tNama\tNilai");
    while(baca != NULL){
        printf("%d\t",baca->employees.id);
        printf("%s\t", baca->employees.nama);
        printf("%d\t", baca->employees.nilai);
        puts("");
        baca=baca->next;
    }

}

void input(emp *pegawaii){
    int x, y;

    printf("No\t : ");
    scanf("%d",&pegawaii->id);
    fflush(stdin);
    printf("Nama\t : ");
    gets(pegawaii->nama);
    fflush(stdin);
    printf("Nilai\t : ");
    scanf("%d",&pegawaii->nilai);
}






