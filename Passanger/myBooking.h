#ifndef MY_BOOKING_H
#define MY_BOOKING_H

#include "../struct.h"
#include <stdio.h>

extern int loggedInuser;

void my_booking_display() {
    if(loggedInuser < 0) {
        printf("No user logged in!\n");
        return;
    }
    
    printf("\n========== My Bookings ==========\n");
    printf("You have no active bookings at the moment.\n");
    printf("===================================\n");
}

#endif
