#ifndef BOOKING_H
#define BOOKING_H

#include "../struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int bookingID;
    int userID;
    char pickupLocation[100];
    char dropoffLocation[100];
    char pickupTime[20];
    float fare;
    int status; // 0: Pending, 1: Confirmed, 2: Completed, 3: Cancelled
} Booking;

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
