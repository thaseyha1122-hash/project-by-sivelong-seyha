#ifndef USERLOGIN_H
#define USERLOGIN_H
#include <unistd.h>
//time sleep
#include <conio.h>
//getch
#include "struct.h"
#include <stdio.h>
#include <string.h>
#include "Data.h"
#include "Passanger/passangerMenu.h"
#include "Admin/adminMenu.h"
#include "Admin/addCar.h"
#include "Driver/driverMenu.h"
extern User users[100];
extern int userCount;
extern int loggedInuser;


int login_check(const char *phone, const char *pass) {
    
    LoadData();
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].phone, phone) == 0 && strcmp(users[i].password, pass) == 0) {
            return i;
        }
    }
    return -1;
}

void login(){
    
    
    LoadData();

    char *phone = malloc(20), *pass = malloc(20);
    printf("\n======================  Login Form ===================== \n\n");
    printf("\t\tEnter Phone Number : ");    scanf("%s", phone);
    printf("\n\t\tEnter password : ");    scanf("%s", pass);

    int tmp = login_check(phone, pass);
    system("cls");
    printf("\n\t Checking.");
    for(int i =0;i<3;i++){
            sleep(1.2);
            printf(".");
        }
    system("cls");
    if(tmp<0) {
        printf("\nLogin Failed...\n");
        
        free(phone);
        free(pass);
        phone = NULL;
        pass = NULL;
        login();
    }
    loggedInuser = tmp;
    
    if(users[loggedInuser].role == ADMIN){
        printf("\nLogin Successfully\n");
        printf("\n\t============================================================\n");
        printf("\t        PRESS ANY KEY TO DISPLAY MENU\n");
        printf("\t============================================================");
        getch();   
        adminMenu();
        free(phone);
        free(pass);
        phone = NULL;
        pass = NULL;
        return;
    }
    else if(users[loggedInuser].role == DRIVER) {
        printf("\nLogin Successfully\n");
        driverMenu();
        free(phone);
        free(pass);
        phone = NULL;
        pass = NULL;
        return;
    }
    else{
        printf("\nLogin Successfully\n");
    
        passangerMenu();
        free(phone);
        free(pass);
        phone = NULL;
        pass = NULL;
        return;
    }
    free(phone);
    free(pass);
    phone = NULL;
    pass = NULL;
    
}



void Register(){
    LoadUserCount();
    LoadData();

    if(userCount >= 100) {
        printf("\nError: User limit reached! Cannot register more users.\n");
        return;
    }

    User *u = &users[userCount];

    printf("\n =============== Register Form ============= \n");
    printf("Enter Your Name : ");   scanf(" %99[^\n]", u->name);
    getchar();
    printf("Enter Your Gender : ");  scanf(" %9s", u->gender);
    getchar();
    printf("Enter Phone Number : ");    scanf(" %19s", u->phone);
    getchar();
    for(int i=0; i<userCount; i++) {
        if(strcmp(users[i].phone, u->phone) == 0) {printf("\nPhone already registered.\n"); return;}
    }
    printf("Enter password : ");    scanf(" %19s", u->password);
    getchar();

    u->id = 2000 + userCount;
    u->role = PASSENGER;
    u->balance = 1;
    u->rating = 0;
    u->totalRides = 0;
    u->modelCar[0] = '\0';
    strcat(u->modelCar, "N/A");
    

    SaveData(u);
    printf("\nRegistration successful! You get 1$.\n");

}

#endif