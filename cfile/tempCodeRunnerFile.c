#include<stdio.h>

int main(){
    FILE *file;
    int id,age;
    char name[100];
    file = fopen("user.csv","r");
    if( file == NULL){
        printf("Nothing");
        return 0;
    }
    while(fscanf(file, "%d,%s,%d", &id,name,&age) == 11){
        printf("Id : %d, Name : %s, Age : %d",id,name,age);
    }
    fclose(file);
}