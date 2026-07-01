#ifndef BOOKING_H
#define BOOKING_H

#include "../struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../data.h"

extern int carCount;
extern Car cars[10];
extern int loggedInuser;
extern User users[100];
extern int historyCount;
extern History history[100];

int car_index;

void display_car_seats() {
    LoadCarData();
    int id;
    printf("Enter car's ID( 0 : back ) : ");
    scanf("%d", &id);

    if (id == 0) return;

    int index = -1;
    for (int i=0; i<carCount; i++) {
        if(id == cars[i].id) {index = i; break;}
    }
    if (index == -1)
    {
        printf("Car not found.\n");
        return;
    }
    for(int i = 0; i <cars[index].TotalSeat ; i++){
        if(i ==0 ){
            printf("\n[ D ]\n\n");
        }
        if(strcmp(cars[index].seatStatus[i], "0") == 0){
            printf("[ %d ]\t", i+1);
        }
        else{
            printf("[ %s ]\t", cars[index].seatStatus[i]);
        }
        if((i+1) %  2 == 0){
            printf("\n\n");
        }
    }
    car_index = index;
}

void booking() {
    LoadHistoryCount();
    LoadHistory();
    LoadData();
    display_car_seats();

    printf("\n\n [D] = Driver\n [X] = Booked\n");

    int index;
    printf("Enter chair number to book : "); scanf("%d", &index);

    if(users[loggedInuser].balance < cars[car_index].price) {
        printf("Please top up your balance first.\n");
        return;
    }
    users[loggedInuser].balance -= cars[car_index].price;

    History *u = &history[historyCount];
    u->id = users[loggedInuser].id;
    strcpy(u->pickup, cars[car_index].pickup);
    strcpy(u->dropoff, cars[car_index].dropoff);
    strcpy(u->pickupTime, cars[car_index].pickupTime);
    strcpy(u->dropTime, cars[car_index].dropTime);
    strcpy(u->model, cars[car_index].model);
    u->price = cars[car_index].price;
    strcpy(u->travelTime, cars[car_index].travelTime);
    u->seatStatus = index;
    
    char c[2];
    c[0] = users[loggedInuser].gender[0]; c[1] = '\0';
    strcpy(cars[car_index].seatStatus[index - 1], c);

    historySave(u);
    UpdateCarData();

    
}

// void cancleBooking() {
//     LoadHistoryCount();
//     LoadHistory();
//     LoadData();
//     display_car_seats();

//     for (int i=0; i<historyCount; i++) {
//         if(history[i].id == users[loggedInuser].id) {
//             printff("");
//         }
//     }
    
//     UpdateCarData();
// }



#endif

