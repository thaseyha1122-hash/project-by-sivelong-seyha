#define viewAllCar_H
#ifndef viewAllCar_H

#include "../Data.h"
extern int carCount;
extern Car cars[10];

void boarder() {
    printf("+");
}

void viewAllcar() {

    Car* c = &cars[carCount];
    printtf("");

    for (int i=0; i<carCount; i++) {
        printf("");
    }


}


#endif