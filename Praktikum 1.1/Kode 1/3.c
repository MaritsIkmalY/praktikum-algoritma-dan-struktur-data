#include<stdio.h>
#define MAKS 25

typedef struct{
    float tugas, uts, uas, akhir;
    char grade;
}nilai;

typedef struct{
    char nama[MAKS];
    nilai rapot;
}student;

void input(student *);
void cek(student *);
void tampil(student *);

int jumlah_mhs;
int j;

int main(){
    student mhs[MAKS];

    input(mhs);
    cek(mhs);
    tampil(mhs);
}

void input(student *maha){
    printf("Berapa jumlah mahasiswa ? ");
    scanf("%d",&jumlah_mhs);
    puts("Masukkan DATA Mahasiswa\n");
    for(j=0 ; j<jumlah_mhs ; j++){
        printf("Mahasiswa ke-%d\n",j+1);
        printf("Nama\t: ");
        fflush(stdin);
        gets(maha->nama);
        printf("Nilai Tugas\t: ");
        scanf("%f",&maha->rapot.tugas);
        printf("Nilai UTS\t: ");
        scanf("%f",&maha->rapot.uts);
        printf("Nilai UAS\t: ");
        scanf("%f",&maha->rapot.uas);
        maha++;
    }
}

void cek(student *maha){

    for(j=0 ; j<jumlah_mhs ; j++){
        maha->rapot.akhir = 0.2 * maha->rapot.tugas + 0.4 * maha->rapot.uts + 0.4 * maha->rapot.uas;
        if(maha->rapot.akhir >= 80 && maha->rapot.akhir <= 100)
            maha->rapot.grade = 'A';
        else if(maha->rapot.akhir >= 70)
            maha->rapot.grade = 'B';
        else if(maha->rapot.akhir >= 60)
            maha->rapot.grade = 'C';
        else if(maha->rapot.akhir >= 50)
            maha->rapot.grade = 'D';
        else
            maha->rapot.grade = 'E';
        maha++;
    }
}

void tampil(student *maha){
    puts("\t\t\tDAFTAR NILAI");
    puts("\t\tMATAKULIAH KONSEP PEMROGRAMAN");
    puts("---------------------------------------------------------------------");
    puts("No\tNama\t\t\t\tNilai\t\t\tGrade");
    puts("\tMahasiswa\t\tTugas\tUTS\tUAS\tAkhir");
    puts("---------------------------------------------------------------------");
    for(j=0 ; j<jumlah_mhs ; j++){
        printf("%d\t%s\t\t\t%g\t%g\t%g\t%g\t%c\n",j+1, maha->nama, maha->rapot.tugas,maha->rapot.uts, maha->rapot.uas, maha->rapot.akhir, maha->rapot.grade);
        maha++;
    }
    puts("---------------------------------------------------------------------\n");
    printf("Total Mahasiswa = %d\n", jumlah_mhs);
}

