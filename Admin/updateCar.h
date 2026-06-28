#ifndef UPDATECAR_H
#define UPDATECAR_H  
#include "../struct.h"
#include "../Data.h"
#include <stdio.h>
extern Car cars[10];
extern int carCount;

void updateCar(){
    int id;
    printf("Enter Car ID : ");
    scanf("%d",&id);
    int index = -1;
    for(int i =0;i<carCount;i++){
        if(cars[i].id == id){
            index = i;
        }
    }
    if(index != -1){
        int choice;
        do{
            int choice;
            printf("1. Update Pickup location\n");
            printf("2. Update Dropoff location\n");
            printf("3. Update Travel Time\n");
            printf("4. Update PickupTime\n");
            printf("5. Update DropTime\n");
            printf("6. Update Model\n");
            printf("7. Update Price\n");
            printf("8. Update Seat Available\n");
            printf("0. Back\n");
            printf("Choose : ");
            scanf("%d",&choice);
            switch (choice){
            case 1:
                printf("New Pickup Location : ");
                scanf("%[^\n]", cars[index].pickup);
                break;
            case 2 :
                printf("New Dropoff location : ");
                scanf("%[^\n]", cars[index].dropoff);
                break;
            case 3:
                printf("New Travel Time : ");
                scanf("%s",cars[index].travelTime);
                break;
            case 4:
                printf("New Pickup Time : ");
                scanf("%s",cars[index].pickupTime);
                break;
            case 5:
                printf("New Dropoff Time : ");
                scanf("%s",cars[index].dropTime);
                break;
            case 6:
                printf("New Model Car : ");
                scanf("%[^\n]", cars[index].model);
                break;
            case 7:
                printf("New Price : ");
                scanf("%f",&cars[index].price);
                break;
            case 8:
                printf("New Total Seat Available : ");
                scanf("%d", &cars[index].seatAvailable);
                break;
            case 0:
                break;
            default :
                printf("Invalid!!!\n");
                break;
            }
            UpdateCarData();
            printf("Update successful !!!\n");
        }while(choice !=0);
    }else{
        printf("Car not Found!\n");
    }

}
#endif