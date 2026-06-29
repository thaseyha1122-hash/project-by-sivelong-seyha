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

int car_index;

void display_car_seats() {
    LoadCarData();
    int id;
    printf("Enter car's ID( 0 : back ) : ");
    scanf("%d", &id);

    // if (id == 0) return;

    // int index = -1;
    // for (int i = 0; i < carCount; i++) {
    //     if (cars[i].id == id) {
    //         index = i;
    //         break;
    //     }
    // }

    // if (index == -1) {
    //     printf("Car not found.\n");
    //     return;
    // }

    int index;
    for (int i=0; i<carCount; i++) {
        if(id == cars[i].id) index = i;
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
    LoadData();
    display_car_seats();

    printf("\n\n [D] = Driver\n [X] = Booked\n");

    int index;
    printf("Enter chair number to book : "); scanf("%d", &index);
    //cars[car_index].seatStatus[index-1] = "1";
    char c[2];
    c[0] = users[loggedInuser].gender[0]; c[1] = '\0';
    strcpy(cars[car_index].seatStatus[index - 1], c);
    UpdateCarData();


    // Car *selectedCar = &cars[index];
    // for (int i = 0; i < selectedCar->TotalSeat; i++) {
    //     if (i == 0) {
    //         printf(" [ D ]\n");
    //     }
    //     if (selectedCar->seatStatus != NULL && selectedCar->seatStatus[i] == 0) {
    //         printf("[ %d: O ]  ", i + 1);
    //     } else {
    //         printf("[ %d: X ]  ", i + 1);
    //     }
    //     if ((i + 1) % 2 == 0) {
    //         printf("\n\n");
    //     }
    // }
    

}



#endif
