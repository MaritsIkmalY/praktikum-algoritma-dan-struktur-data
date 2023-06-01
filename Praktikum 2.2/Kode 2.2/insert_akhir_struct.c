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


int main(){
    char jwb;

    puts("Linked List untuk aplikasi INSERT DI AKHIR");
    puts("Membentuk linked list dengan Insert di akhir");
    do{
        fflush(stdin);
        alokasi();
        akhir();
        fflush(stdin);
        printf("Ada data lagi (y/t)? ");
        jwb=getchar();
        puts("");
    }while(jwb == 'y');
    tampil();
    return 0;
}

//Step 1) Memesan Alamat
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
    //Step 2) Mencari Posisi
    else{
        tail = head;
        while(tail->next != NULL)
            tail = tail->next;
        //Step 3) Menyambungkan Node
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





