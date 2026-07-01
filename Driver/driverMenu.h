#include<stdio.h>


void driverMenu(){
    printf("\n ======================= Driver Menu ========================= \n");
    int choice;
    do {
        printf("1. View Profile\n");
        printf("2. View My Trip\n");
        printf("3. Start Trip\n");
        printf("4. Complete Trip\n");
        printf("5. View History\n");
        printf("6. View Earnings\n");
        printf("0. Logout\n");
        printf("Enter Your Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        break;  
            // viewMyCar();
            // break;
        // case 2:
        //     viewMyTrip();
        //     break;
        // case 3:
        //     startTrip();
        //     break;
        // case 4:
        //     completeTrip();
        //     break;
        // case 5:
            
        default:
            break;
        }
    } while (choice !=0);


    

}