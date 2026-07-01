#ifndef ADDCAR_H
#define ADDCAR_H
#include "../struct.h"
#include "../Data.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern Car cars[10];
extern int carCount;

void addCar(){
    Car *u = &cars[carCount];
    
    printf("\n ============ ADD CAR ==============\n");
    printf("Pickup location : "); scanf(" %[^\n]",u->pickup); getchar();
    printf("Dropoff location : "); scanf(" %[^\n]",u->dropoff); getchar();
    printf("Travel Time Period : ");   scanf(" %[^\n]", u->travelTime); getchar();
    printf("Pickup Time (HH-MM-SS) : ");    scanf(" %[^\n]",u->pickupTime); getchar();
    printf("Drop Time (HH-MM-SS) : "); scanf(" %[^\n]",u->dropTime); getchar();
    printf("Model : "); scanf(" %[^\n]", u->model); getchar();
    printf("Price : "); scanf("%f", &u->price); getchar();
    printf("Total Seat Available : ");  scanf(" %d", &u->seatAvailable); getchar();
    printf("Enter driver's ID : "); scanf("%d", &u->idDriver);getchar();

    u->id = 001 + carCount;
    u->TotalSeat = u->seatAvailable;
    u->seatStatus = malloc(u->TotalSeat * sizeof(char *));
    if (!u->seatStatus)
    {
        printf("Memory error.\n");
        return;
    }

    for (int i = 0; i < u->TotalSeat; i++)
    {
        u->seatStatus[i] = malloc(2 * sizeof(char));
        if (!u->seatStatus[i])
        {
            printf("Memory error.\n");
            return;
        }
        strcpy(u->seatStatus[i], "0");
    }
    // free(u->seatStatus);
    // u->seatStatus = 0;
    CarSave(u);
    printf("Car added successfully!\n");
    
}

#endif