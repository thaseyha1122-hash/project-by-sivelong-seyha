#ifndef BOOKING_H
#define BOOKING_H

#include "../struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
extern int carCount;
extern Car cars[10];

void booking() {
    int id;
    printf("Enter car's ID( 0 : back ) : "); scanf("%d", id);
    if (id == 0) {
        return;
    }
    for(int i=0; i<carCount; i++) {
        if(id == cars[i].id) {
            // cars[i].seatAvailable--;
            
        }
    }
}


    // for(int i = 0; i < c.totalSeat; i++)
    // {

    //     if(i == 0)
    //     {
    //         printf("[ D ]      ");
    //         continue;
    //     }


    //     if(c.seatStatus[i] == 0)
    //     {
    //         printf("[ %d: O ]  ", i+1);
    //     }
    //     else
    //     {
    //         printf("[ %d: X ]  ", i+1);
    //     }



    //     if((i+1) % 2 == 0)
    //     {
    //         printf("\n\n");
    //     }
    // }

#endif
