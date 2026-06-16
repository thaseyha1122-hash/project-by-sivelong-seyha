#include "struct.h"
#include<stdio.h>
userLogin user;

void login(){

    printf("\n=============== Login from ============\n");
    printf("Enter Phone Number : ");
    scanf("%d",&user.phone_number);
    printf("Enter password : ");
    scanf("%d",&user.password);
}