#ifndef ADMINMENU_H
#define ADMINMENU_H
#include "addCar.h"
#include <stdio.h>
#include "viewallCar.h"
#include "viewAllUser.h"
#include "delete-user.h"

void adminMenu(){
    int choice;
    do {
        printf("\n========== ADMIN MENU ==========\n");
        printf("1. Add Car\n");
        printf("2. View All Cars\n");
        printf("3. Delete Car\n");
        printf("4. View All Users\n");
        printf("5. Delete user\n");
        printf("6. View All Bookings\n");
        printf("7. Update Car\n");
        printf("0. Logout\n");

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
            // case 3:
            //     deleteCar();
            case 5:
                deleteUser();
                break;
            case 4:
                viewAllUser();
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