#ifndef USERLOGIN_H
#define USERLOGIN_H

#include "struct.h"
#include <stdio.h>
#include <string.h>
#include "Data.h"
User user;
User users[100];
extern int userCount;
//int UserCount = 0;

void login(){
    
    printf("\n=============== Login Form ============\n");
    printf("Enter Phone Number : ");    scanf("%19s", user.phone);
    printf("Enter password : ");    scanf("%19s", user.password);
    
}

void Register(){

    User *u = &users[userCount];

    printf("\n =============== Register Form ============= \n");
    printf("Enter Your Name : ");   scanf("%[^\n]", u->name);
    getchar();  // Clear the newline from input buffer
    printf("Enter Your Gender : ");  scanf("%9s", u->gender);
    printf("Enter Phone Number : ");    scanf("%19s", u->phone);
    printf("Enter password : ");    scanf("%19s", u->password);

    u->id = 2000 + userCount;
    u->role = PASSENGER;

    
    SaveData(u);

}

#endif