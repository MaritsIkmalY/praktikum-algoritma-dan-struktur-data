#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    int id;
    char nama[25];
    float nilai;
}mahasiswa;

typedef struct simpul node;
struct simpul{
    mahasiswa student;
    node *next;
};
 node *head=NULL, *p, *tail;

void input(mahasiswa *);
void tampil();
void akhir();
void alokasi();
void menghapus_akhir();

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
    }while(jwb=='y');
    tampil();
    fflush(stdin);
    printf("Mau menghapus node terakhir? ");
    jwb = getchar();
    if(jwb == 'y'){
        puts("\nMenghapus simpul terakhir dari node...\n");
        menghapus_akhir();
    }
    tampil();
    return 0;
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


//Step 1) Memesan Alamat
void alokasi(){
    mahasiswa murid;

    input(&murid);
    p=(node *)malloc(sizeof(node));
    if(p == NULL)
        exit(0);
    else{
        p->student.id = murid.id;
        strcpy(p->student.nama, murid.nama);
        p->student.nilai = murid.nilai;
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
        printf("%d\t",baca->student.id);
        printf("%s\t", baca->student.nama);
        printf("%g\t", baca->student.nilai);
        puts("");
        baca=baca->next;
    }

}

void input(mahasiswa *student){
    int x, y;

    printf("No\t : ");
    scanf("%d",&student->id);
    fflush(stdin);
    printf("Nama\t : ");
    gets(student->nama);
    fflush(stdin);
    printf("Nilai\t : ");
    scanf("%f",&student->nilai);
}






