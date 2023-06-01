#include<stdio.h>

typedef struct{
    int tgl, bln, thn;
}date;

int sameday(date, date);

int main(){
    date day1, day2;

    printf("Masukkan Tanggal pertama dd-mm-yyyy: ");
    scanf("%d-%d-%d", &day1.tgl, &day1.bln, &day1.thn);
    printf("Masukkan Tanggal Kedua dd-mm-yyyy: ");
    scanf("%d-%d-%d", &day2.tgl, &day2.bln, &day2.thn);
    if(sameday(day1, day2))
        printf("It is the same day\n");
    else
        printf("It is not the same day\n");
    return 0;
}

int sameday(date hari1, date hari2){
    if(hari1.tgl == hari2.tgl && hari1.bln == hari1.bln && hari1.thn == hari2.thn)
        return 1;
    else
        return 0;

};

