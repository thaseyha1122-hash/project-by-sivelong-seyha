#ifndef VIEW_BOOKING_H
#define VIEW_BOOKING_H

#include "../struct.h"
#include <stdio.h>
#include "Booking.h"
#include "../Data.h"

extern int carCount;
extern Car cars[10];

void boarder3() {
    printf("------------------------------------------------------------------------------------------------------------------------\n");
}

void view_booking() {
    LoadcarCount();
    LoadCarData();
    printf("\n============================================= LIST ALL CAR ============================================================\n");

    printf("\n%-5s %-5s %-15s %-15s %-18s %-12s %-12s %-12s %-10s %-10s\n",
       "No", "ID", "Pickup", "Dropoff", "Travel-Period", "Pick Time",
       "Drop Time", "Model", "Price", "Seats");
    printf("\n=======================================================================================================================\n\n");
    boarder3();
    if (carCount == 0) {
        printf("\t\t\tNo cars available.\n");
        return;
    }
    for (int i = 0; i < carCount; i++) {
        printf("%-5d %-5.3d %-15s %-15s %-18s %-12s %-12s %-12s %-10.2f %-10d\n",
        i+1,
        cars[i].id,
        cars[i].pickup,
        cars[i].dropoff,
        cars[i].travelTime,
        cars[i].pickupTime,
        cars[i].dropTime,
        cars[i].model,
        cars[i].price,
        cars[i].seatAvailable);
        boarder3();
    }
    booking();
}

#endif
