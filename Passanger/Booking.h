#ifndef BOOKING_H
#define BOOKING_H

#include "../struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void create_booking() {
    Booking *b = (Booking *)malloc(sizeof(Booking));
    printf("\n========== New Booking ==========\n");
    printf("Pickup Location: ");
    scanf(" %99[^\n]", b->pickupLocation);
    getchar();
    printf("Dropoff Location: ");
    scanf(" %99[^\n]", b->dropoffLocation);
    getchar();
    printf("Estimated Fare: ");
    scanf("%f", &b->fare);
    getchar();
    printf("Booking created successfully!\n");
    printf("===================================\n");
    free(b);
}

#endif
