#include "struct.h"
#include<stdio.h>
userLogin user;
userRegister user_register;
void login(){

    printf("\n=============== Login Form ============\n");
    printf("Enter Phone Number : ");
    scanf("%d",&user.phone_number);
    printf("Enter password : ");
    scanf("%d",&user.password);
}

void registe(){
    printf("\n =============== Register Form ============= \n");
    printf("Enter Your Name : ");   scanf("%s",&user_register.name);
    printf("Enter Your Gender : ");  scanf("%s",&user_register.gender);
    printf("Enter Phone Number : ");    scanf("%s",&user_register.phone);
    printf("Enter password : ");    scanf("%s",&user_register.password);
}