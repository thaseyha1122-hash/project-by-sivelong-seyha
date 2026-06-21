#include <stdio.h>
#include "../struct.h"
#include "../Data.h"

extern int carCount;
extern Car cars[10];

void deleteCar() {
    int id;
    printf("\nEnter Car ID to delete: ");   scanf("%d", &id);
    for (int i=0; i<carCount; i++) {
        if(cars[i].id == id) {
            for(int j=i; j<carCount-1; j++) {
                Car *c = &cars[j];
                int cid = c->id;
                *c = cars[j+1];
                c->id = cid;
            }
            carCount--;
            UpdateCarData();
            printf("Car deleted.\n");
            return;
        }
    }
    printf("Car not found! \n");
}