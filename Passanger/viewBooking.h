#ifndef VIEW_BOOKING_H
#define VIEW_BOOKING_H

#include "../struct.h"
#include <stdio.h>
#include "../Data.h"

extern int carCount;
extern Car cars[10];


void view_booking() {
    LoadcarCount();
    LoadCarData();
    printf("\n========== Booking Views ==========\n");
    if (carCount == 0) {printf("No bookings available.\n"); return;}
    printf("%-5s %-5s %-10s %-10s %-11s %-10s %-10s %-10s %-15s %-15s\n", 
        "NO", "ID", "Pick-Up", "Drop-Off", "Time-Period", "From", "To", "Car-Model", "Price/Person", "Seat-Available");
    for (int i=0; i<carCount; i++) {
        printf("%-5d %-5.3d %-10s %-10s %-11s %-10s %-10s %-10s %-15.2f$ %-15d\n", 
            i+1, cars[i].id, cars[i].pickup, cars[i].dropoff, cars[i].travelTime, cars[i].pickupTime, cars[i].dropTime, cars[i].model, cars[i].price, cars[i].seatAvailable);
    }
    printf("===================================\n");
}

#endif
