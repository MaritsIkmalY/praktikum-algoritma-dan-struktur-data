#include<stdio.h>

typedef struct{
    int tgl, bln, thn;
}birthday;

int isYounger(birthday, birthday);

int main(){
    birthday student1, student2;

    printf("Masukkan Tanggal Lahir Student 1 dd-mm-yyyy: ");
    scanf("%d-%d-%d", &student1.tgl, &student1.bln, &student1.thn);
    printf("Masukkan Tanggal Lahir Student 2 dd-mm-yyyy: ");
    scanf("%d-%d-%d", &student2.tgl, &student2.bln, &student2.thn);
    if(isYounger(student1, student2))
        printf("Student 1 is younger than student 2\n");
    else
        printf("Student 1 isn't younger than student 2\n");
    return 0;
}

int isYounger(birthday stud1, birthday stud2){
    if(stud1.thn > stud2.thn)
        return 1;
    else if(stud1.thn == stud2.thn){
        if(stud1.bln > stud2.bln)
            return 1;
        else if(stud1.bln == stud2.bln){
            if(stud1.tgl > stud2.tgl)
                return 1;
            else
                return 0;
        }
        else
            return 0;
    }
    else
        return 0;

};
