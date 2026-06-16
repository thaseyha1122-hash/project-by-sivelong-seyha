#include<stdio.h>

int main(){
    FILE *fptr;
    int id;
    char name[100];
    int age;
    fptr = fopen("user.csv","a");
    // fprintf(fptr,"Enter your name : "); for write to the file 
    // scanf("%d",&name);
    printf("Enter id : ");
    scanf("%d",&id);
    printf("Enter name : ");
    scanf("%s",&name);
    printf("Enter AGe : ");
    scanf("%d",&age);

    fprintf(fptr,"\nID : %d,Name : %s,Age : %d",id,name,age);


}