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
void awal();
void alokasi();


int main(){
    char jwb;

    puts("Linked List untuk aplikasi INSERT DI AWAL");
    puts("Membentuk linked list dengan Insert di awal");
    do{
        fflush(stdin);
        alokasi();
        awal();
        fflush(stdin);
        printf("Ada data lagi (y/t)? ");
        jwb=getchar();
        puts("");
    }while(jwb=='y');
    tampil();
    return 0;
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

void awal(){
    if(head != NULL)
        p->next = head;
    head = p;
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




