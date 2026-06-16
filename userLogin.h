#include "struct.h"
#include<stdio.h>
User user;
void login(){

    printf("\n=============== Login Form ============\n");
    printf("Enter Phone Number : ");    scanf("%d",&user.phone);
    printf("Enter password : ");    scanf("%d",&user.password);
    
}

void Register(){
    printf("\n =============== Register Form ============= \n");
    printf("Enter Your Name : ");   scanf("%s",&user.name);
    printf("Enter Your Gender : ");  scanf("%s",&user.gender);
    printf("Enter Phone Number : ");    scanf("%s",&user.phone);
    printf("Enter password : ");    scanf("%s",&user.password);
}