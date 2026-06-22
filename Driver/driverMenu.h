#include<stdio.h>


void driverMenu(){
    printf("\n ======================= Driver Menu ========================= \n");
    int choice;
    do {
        printf("1. View My Car\n");
        printf("2. Start Trip\n");
        printf("3. Complete Trip\n");
        printf("4. View History\n");
        printf("5. View Earnings\n");
        printf("0. Logout\n");
        printf("Enter Your Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            viewMyCar(driver.carID);
            break;
        default:
            break;
        }
    } while (choice !=0);


    

}