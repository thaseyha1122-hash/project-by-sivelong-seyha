#include "struct.h"
#include<stdio.h>
userLogin user;
userRegister register;
void login(){

    printf("\n=============== Login Form ============\n");
    printf("Enter Phone Number : ");
    scanf("%d",&user.phone_number);
    printf("Enter password : ");
    scanf("%d",&user.password);
}

void register(){
    printf("\n =============== Register Form ============= \n");
    printf("Enter Your Name : ");   scanf("%s",&register.name);
    printf("Enter Your Gender : ");  scanf("%s",&register.gender);
    printf("Enter Phone Number : ");    scanf("%s",&register.phone);
    printf("Enter password : ");    scanf("%s",&register.password);
}