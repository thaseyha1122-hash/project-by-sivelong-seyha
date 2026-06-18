#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "userLogin.h"
#include "Data.h"

// Global declarations
User users[100];
int userCount = 0;
int loggedInuser = -1;
int carCount = 0;

Car cars[10];

int main(){
    createDefaultAdmin();
    LoadUserCount();


    int choice;
    printf("======================||======================\n");
    printf("||      CAR BOOKING SEYSTEM MANAGEMENT      ||\n");
    printf("======================||======================\n");

    do {
        printf("\n===================MANU CHOICES====================\n");
        printf(" 1. Login \n");
        printf(" 2. Register \n");
        printf(" 0. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:     login();    break;
            case 2:     Register(); break; 
            case 0:     printf("\nGoodbye!\n");   break;
            default:    printf("Invalid choice.\n");
        }

    } while(choice!=0);

    return 0;
    
}