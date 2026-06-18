#define ADDCAR_H
#ifndef ADDCAR_H
#include "../struct.h"
#include <stdio.h>

extern Car car[10];
extern int carCount;

void addCar(){
    Car *u = &car[carCount];
    
    printf("\n ============ ADD CAR ==============\n");
    printf("Pickup location : "); scanf("%s",u->pickup);
    printf("Dropoff location : "); scanf("%s",u->dropoff);
    printf("Travel Time Period : ");   scanf("%s", u->travalTime);
    printf("Pickup Time (HH-MM-SS) : ");    scanf("%s",u->pickupTime);
    printf("Drop Time (HH-MM-SS) : "); scanf("%s",u->dropTime);
    printf("Model : "); scanf("%s", u->model);
    printf("Price : "); scanf("%f", u->price);
    printf("Seat Avaible : ");  scanf("%d", u->seatAvailable);

    u->id = 001 + carCount;

    
    CarSave(u);
    printf("Car added successfully!\n");
}

#endif