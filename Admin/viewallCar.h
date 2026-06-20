#ifndef VIEWALLCAR_H
#define VIEWALLCAR_H

#include <stdio.h>
#include "../Data.h"
extern int carCount;
extern Car cars[10];

void boarder() {
    printf("+");
}

void viewAllcar() {
    printf("\n========== ALL CARS ==========\n");

    if (carCount == 0) {
        printf("No cars available.\n");
        return;
    }

    for (int i = 0; i < carCount; i++) {
        printf("Car %d:\n", i + 1);
        printf("  ID: %d\n", cars[i].id);
        printf("  Pickup: %s\n", cars[i].pickup);
        printf("  Dropoff: %s\n", cars[i].dropoff);
        printf("  Travel Time: %s\n", cars[i].travelTime);
        printf("  Pickup Time: %s\n", cars[i].pickupTime);
        printf("  Drop Time: %s\n", cars[i].dropTime);
        printf("  Model: %s\n", cars[i].model);
        printf("  Price: %.2f\n", cars[i].price);
        printf("  Seats Available: %d\n", cars[i].seatAvailable);
        printf("--------------------------------\n");
    }
}

#endif