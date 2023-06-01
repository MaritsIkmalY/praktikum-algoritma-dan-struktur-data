#include<stdio.h>
#define MAKS 25

struct nilai{
    float tugas, uts, uas, akhir;
    char grade;
};

struct student{
    char nama[MAKS];
    struct nilai rapot;
};

void input(struct student[]);
void cek(struct student[]);
void tampil(struct student[]);

int jumlah_mhs;
int j;

int main(){
    struct student mhs[MAKS];

    input(mhs);
    cek(mhs);
    tampil(mhs);
}

void input(struct student maha[]){
    extern int jumlah_mhs;

    printf("Berapa jumlah mahasiswa ? ");
    scanf("%d",&jumlah_mhs);
    puts("Masukkan DATA Mahasiswa\n");
    for(j=0 ; j<jumlah_mhs ; j++){
        printf("Mahasiswa ke-%d\n",j+1);
        printf("Nama\t\t: ");
        fflush(stdin);
        gets(maha[j].nama);
        printf("Nilai Tugas\t: ");
        scanf("%f",&maha[j].rapot.tugas);
        printf("Nilai UTS\t: ");
        scanf("%f",&maha[j].rapot.uts);
        printf("Nilai UAS\t: ");
        scanf("%f",&maha[j].rapot.uas);
    }
}

void cek(struct student maha[]){

    for(j=0 ; j<jumlah_mhs ; j++){
        maha[j].rapot.akhir = 0.2 * maha[j].rapot.tugas + 0.4 * maha[j].rapot.uts + 0.4 * maha[j].rapot.uas;
        if(maha[j].rapot.akhir >= 80 && maha[j].rapot.akhir <= 100)
            maha[j].rapot.grade = 'A';
        else if(maha[j].rapot.akhir >= 70)
            maha[j].rapot.grade = 'B';
        else if(maha[j].rapot.akhir >= 60)
            maha[j].rapot.grade = 'C';
        else if(maha[j].rapot.akhir >= 50)
            maha[j].rapot.grade = 'D';
        else
            maha[j].rapot.grade = 'E';
    }
}

void tampil(struct student maha[]){
    puts("\t\t\tDAFTAR NILAI");
    puts("\t\tMATAKULIAH KONSEP PEMROGRAMAN");
    puts("---------------------------------------------------------------------");
    puts("No\tNama\t\t\t\tNilai\t\t\tGrade");
    puts("\tMahasiswa\t\tTugas\tUTS\tUAS\tAkhir");
    puts("---------------------------------------------------------------------");
    for(j=0 ; j<jumlah_mhs ; j++){
        printf("%d\t%s\t\t\t%g\t%g\t%g\t%g\t%c\n",j+1, maha[j].nama, maha[j].rapot.tugas,maha[j].rapot.uts, maha[j].rapot.uas, maha[j].rapot.akhir, maha[j].rapot.grade);
    }
    puts("---------------------------------------------------------------------\n");
    printf("Total Mahasiswa = %d\n", jumlah_mhs);
}
