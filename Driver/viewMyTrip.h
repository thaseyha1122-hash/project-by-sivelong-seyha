#define VIEWMYTRIP_H
#ifndef VIEWMYTRIP_H

#include "../Data.h"
#include "../struct.h"



extern int historyCount;
extern History history[100];
extern int loggedInuser;
    // driver =5;
    void viewMyTrip()
{
    LoadHistoryCount();

    printf("======= Today Trip =======\n");
    
    for(int i =0;i<historyCount;i++){
        if( cars[i].idDriver = users[loggedInuser].id){
            printf("\n %-5s %-5s %-15s %-15s %-15s %-10s","No","Booking ID","Pickup","Dropoff","Total Booking","status");

        }
    }
}

printf("\nStatus     : ");

if(bookings[i].status == 0){
    printf("Booked");
}
else if(bookings[i].status == 1){
    printf("On Going");
}
else if(bookings[i].status == 2){
    printf("Completed");
}
else if(bookings[i].status == 3){
    printf("Cancelled");
}
#endif