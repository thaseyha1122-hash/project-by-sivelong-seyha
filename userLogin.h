#ifndef USERLOGIN_H
#define USERLOGIN_H

#include "struct.h"
#include <stdio.h>
#include "Data.h"

User user;
User users[100];
int UserCount = 0;

void login(){

    
    printf("\n=============== Login Form ============\n");
    printf("Enter Phone Number : ");    scanf("%19s", user.phone);
    printf("Enter password : ");    scanf("%19s", user.password);
    
}

void Register(){

    User *u = &users[UserCount];

    printf("\n =============== Register Form ============= \n");
    printf("Enter Your Name : ");   scanf("%[^\n]", u->name);
    printf("Enter Your Gender : ");  scanf("%9s", u->gender);
    printf("Enter Phone Number : ");    scanf("%19s", u->phone);
    printf("Enter password : ");    scanf("%19s", u->password);

    u->id = 2000 + UserCount;
    u->role = PASSENGER;

    
    SaveData(u);
    UserCount++;

}

#endif