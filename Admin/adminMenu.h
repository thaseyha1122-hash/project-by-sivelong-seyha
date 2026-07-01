#ifndef ADMINMENU_H
#define ADMINMENU_H
#include "addCar.h"
#include <stdio.h>
#include "viewallCar.h"
#include "viewAllUser.h"
#include "deleteUser.h"
#include "updateUser.h"
#include "updateCar.h"
#include "../userLogin.h"
#include "deleteCar.h"
#include "deleteUser.h"
#include "addDriver.h"

extern User users[100];
extern int userCount;

void Register();


void adminMenu() {
    int choice;
    int i;
    system("cls");
    do {
        printf("\n======================== ADMIN MENU =====================\n");
        printf("1.  Car views\n");
        printf("2.  User views\n");
        printf("3.  View All Bookings\n");
        printf("4.  Add driver\n");
        printf("0.  Logout\n");

        printf("Enter Your choice : ");    scanf("%d", &choice);
        getchar();
    
        switch (choice)
        {
            case 1:
                do {
                    viewAllcar();
                    // printf("\n==================================== Car Views================================\n\n");
                    printf ("1. Add Car\n");
                    printf ("2. Delete Car\n");
                    printf ("3. update Car\n");
                    printf ("0. Back\n");
                    printf ("Enter choice : "); scanf("%d", &i);
                    
                    switch (i) {
                        case 1:
                            addCar();
                            break;
                        case 2:
                            deleteCar();
                            break;
                        case 3:
                            updateCar();
                            break;
                        case 0:
                            break;
                        default:
                            printf("Invalid choice!\n");
                            break;
                    }
                } while (i != 0);
                break;

            case 2:
                do
                {
                    // printf("\n================== User Views ==================\n");
                    viewAllUser();
                    printf("1. Add User\n");
                    printf("2. Delete User\n");
                    printf("3. update User\n");
                    printf("0. Back\n");
                    printf("Enter choice : ");
                    scanf("%d", &i);

                    switch (i)
                    {
                    case 1:
                        Register();
                        break;
                    case 2:
                        deleteUser();
                        break;
                    case 3:
                        updateUser();
                        break;
                    case 0:
                        break;
                    default:
                        printf("Invalid choice!\n");
                        break;
                    }
                } while (i != 0);
                break;
            
            case 4:
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