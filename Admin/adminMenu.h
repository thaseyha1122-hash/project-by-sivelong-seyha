#ifndef ADMINMENU_H
#define ADMINMENU_H
#include "addCar.h"
#include <stdio.h>
#include "viewallCar.h"
#include "viewAllUser.h"
#include "delete-user.h"
#include "updateUser.h"
#include "updateCar.h"
#include "../userLogin.h"
#include "delete-car.h"
#include "addDriver.h"

extern User users[100];
extern int userCount;

void Register();


void adminMenu() {
    int choice;
    do {
        printf("\n========== ADMIN MENU ==========\n");
        printf("1. Add Car\n");
        printf("2.  View All Cars\n");
        printf("3.  Delete Car\n");
        printf("4.  View All Users\n");
        printf("5.  Delete user\n");
        printf("6.  View All Bookings\n");
        printf("7.  Update Car\n");
        printf("8.  Add user\n");
        printf("9.  Update user\n");
        printf("10. Add driver\n");
        printf("0.  Logout\n");

        printf("Enter Your choice : ");    scanf("%d", &choice);
        getchar();
    
        switch (choice)
        {
            case 1:
                addCar();
                break;
            case 2:
                viewAllcar();
                break;
            case 3:
                deleteCar();
                break;
            case 4:
                viewAllUser();
                break;
            case 5:
                deleteUser();
                break;
            case 7:
                updateCar();
                break;
            case 8:
                Register();
                break;
            case 9:
                updateUser();
                break;
            case 10:
                addDriver();
                break;
            case 0:
                break;
            default:
                printf("Invalid choice!");
                break;
        }

    } while(choice != 0);
    
}

#endif