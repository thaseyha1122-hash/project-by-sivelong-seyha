#ifndef VIEWALLCAR_H
#define VIEWALLCAR_H

#include <stdio.h>
#include "../Data.h"
extern int carCount;
extern Car cars[10];

void boarder() {
    printf("\n---------------------------------------------------------------------------------------------------\n");
}

void viewAllcar() {
    printf("\n========== ALL CARS ==========\n");

    printf("\n%-5s %-5s %-15s %-15s %-12s %-12s %-12s %-12s %-10s %-10s\n",
       "No", "ID", "Pickup", "Dropoff", "Travel", "Pick Time",
       "Drop Time", "Model", "Price", "Seats");
       boarder();
    if (carCount == 0) {
        printf("\t\t\tNo cars available.\n");
        return;
    }
    
    for (int i = 0; i < carCount; i++) {
        printf("%-5d %-5d %-15s %-15s %-12s %-12s %-12s %-12s %-10.2f %-10d\n",
        i+1,
        cars[i].id,
        cars[i].pickup,
        cars[i].dropoff,
        cars[i].travelTime,
        cars[i].dropTime,
        cars[i].model,
        cars[i].price,
        cars[i].seatAvailable);
    }
    // printf("  Car %03d:\n", i + 1);
        // printf("  ID: %d\n", cars[i].id);
        // printf("  Pickup: %s\n", cars[i].pickup);
        // printf("  Dropoff: %s\n", cars[i].dropoff);
        // printf("  Travel Time: %s\n", cars[i].travelTime);
        // printf("  Pickup Time: %s\n", cars[i].pickupTime);
        // printf("  Drop Time: %s\n", cars[i].dropTime);
        // printf("  Model: %s\n", cars[i].model);
        // printf("  Price: %.2f\n", cars[i].price);
        // printf("  Seats Available: %d\n", cars[i].seatAvailable);
        // printf("--------------------------------\n");
}

#endif