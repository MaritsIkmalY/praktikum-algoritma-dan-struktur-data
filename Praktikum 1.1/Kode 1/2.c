#include<stdio.h>
#define MAKS 25

typedef struct{
    int tanggal, bulan, tahun;
}date;

typedef struct{
    int id, gaji;
    char nama[MAKS], jenis;
    date birthday ;
}pegawai;

int  n;

void input(pegawai *);
void tampil(pegawai *);

int main(){
    pegawai emp[MAKS];

    puts("\t\tDATA PEGAWAI\n");
    input(emp);
    tampil(emp);
    return 0;
}

void input(pegawai *employee){
   printf("Masukkan Jumlah Pegawai : ");
   scanf("%d",&n);
   for(int i=0 ; i<n ; i++){
    employee -> id = i+1;
    printf("\nData Pegawai ke-%d\n",employee->id);
    printf("Nama\t\t\t : ");
    fflush(stdin);
    gets(employee -> nama);
    printf("Tgl Lahir (dd-mm-yyyy)\t : ");
    scanf("%d-%d-%d",&employee->birthday.tanggal, &employee->birthday.bulan, &employee -> birthday.tahun);
    fflush(stdin);
    printf("Jenis Kelamin (L/P)\t : ");
    employee -> jenis = getchar();
    printf("Gaji/bln\t\t : ");
    scanf("%d",&employee -> gaji);
    employee++;
   }
}

void tampil(pegawai *employees){
    puts("\nData Pegawai yang telah diinputkan\n");
    for(int i=0 ; i<n ; i++){
        printf("No id\t\t\t : %d\n",employees->id);
        printf("Nama\t\t\t : %s\n",employees->nama);
        printf("Tgl Lahir\t\t : %d-%d-%d\n",employees -> birthday.tanggal, employees -> birthday.bulan, employees -> birthday.tahun);
        printf("Jenis Kelamin\t\t : ");
        if(employees->jenis == 'L' || employees->jenis == 'l')
            puts("Laki-laki");
        else
            puts("Perempuan");
        printf("Gaji/bln\t\t : %d\n", employees->gaji);
        employees++;
        puts("");
   }
}
