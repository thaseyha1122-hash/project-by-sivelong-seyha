#ifndef PASSANGER_MENU_H
#define PASSANGER_MENU_H

#include "../struct.h"
#include "profile.h"
#include "Booking.h"
#include "myBooking.h"
#include "viewBooking.h"
#include "TopUpBalance.h"
#include <stdio.h>
#include <stdlib.h>

void passangerMenu(){
    int choice;
    do {
        printf("\n =========== Welcome ============ \n");
        printf("1.  Profile Account\n");
        printf("2.  Booking \n");
        printf("3.  My Booking\n");
        printf("4.  Top up balance\n");
        printf("5.  ViewBooking\n");
        printf("0.  Exit\n");
        printf("Enter Your Choice : "); scanf("%d", &choice);
        getchar();
        
        switch(choice) {
            case 1:
                profile_display();
                break;
            case 2:
                //create_booking();
                break;
            case 3:
                my_booking_display();
                break;
            case 4:
                TopUp();
                break;
            case 5:
                //view_booking();
                break;
            case 0:
                printf("Thank you for using our service!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 0);
}

#endif

