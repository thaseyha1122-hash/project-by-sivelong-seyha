#ifndef ADDCAR_H
#define ADDCAR_H
#include "../struct.h"
#include "../Data.h"
void adminMenu();
#include <stdio.h>

extern Car cars[10];
extern int carCount;

void addCar(){
    Car *u = &cars[carCount];
    
    printf("\n ============ ADD CAR ==============\n");
    printf("Pickup location : "); scanf(" %[^\n]",u->pickup); getchar();
    printf("Dropoff location : "); scanf(" %[^\n]",u->dropoff); getchar();
    printf("Travel Time Period : ");   scanf(" %[^\n]", u->travelTime); getchar();
    printf("Pickup Time (HH-MM-SS) : ");    scanf(" %[^\n]",u->pickupTime); getchar();
    printf("Drop Time (HH-MM-SS) : "); scanf("%[^\n]",u->dropTime); getchar();
    printf("Model : "); scanf(" %[^\n]", u->model); getchar();
    printf("Price : "); scanf("%f", &u->price); getchar();
    printf("Seat Avaible : ");  scanf(" %d", &u->seatAvailable); getchar();

    u->id = 001 + carCount;
    CarSave(u);
    printf("Car added successfully!\n");
    
}

#endif