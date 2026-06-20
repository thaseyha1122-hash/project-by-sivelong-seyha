#ifndef ADMINMENU_H
#define ADMINMENU_H
#include "addCar.h"
#include <stdio.h>
#include "viewallCar.h"
void adminMenu(){
    int choice;
    do {
        printf("\n========== ADMIN MENU ==========\n");
        printf("1. Add Car\n");
        printf("2. View All Cars\n");
        printf("3. Delete Car\n");
        printf("4. View All Users\n");
        printf("5. View All Bookings\n");
        printf("6. Update Car\n");
        printf("0. Logout\n");

        printf("Enter Your choice : ");    scanf("%d", &choice);
        getchar();
    
        switch (choice)
        {
            case 1:
                addCar();
                break;
            // case 2:
            //     viewAllcar();
            //     break;
            // case 3:
            //     deleteCar();
            case 0:
                break;
            default:
                break;
        }

    } while(choice != 0);
    
<<<<<<< HEAD
=======
    switch (choice) {
    case 1:
        addCar(); break;
    case 2:
        viewAllcar();
        break;
    // case 3:
    //     deleteCar();
    default:
        break;
    }
>>>>>>> 047c3776d76560fd4239cd96ac7c0416f1d64659
}

#endif