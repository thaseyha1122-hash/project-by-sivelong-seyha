#ifndef UPDATEUSER_H
#define UPDATEUSER_H    
#include "../struct.h"
#include "../Data.h"
#include <stdio.h>

extern User users[100];
extern int userCount;

void updateUser(){

    int id;
    printf("Enter ID For Update : ");
    scanf("%d",&id);
    int index = -1;
    for(int i =0;i<userCount;i++){
        if(users[i].id == id){
            index = i;
        }
    }
    if (index != -1){
        int choice;
        do {
            printf("\n======= UPDATE USER =======\n");
            printf("1. Update Name\n");
            printf("2. Update Phone Number\n");
            printf("3. Update Password\n");
            printf("4. Update Balance\n");
            printf("5. Update Rating\n");
            printf("6. Update Total Ride\n");
            printf("0. Back\n");

            printf("Choose: ");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                printf("New Name : ");
                scanf("%s", users[index].name);
                break;
            case 2:
                printf("New Phone Number : ");
                scanf("%s", users[index].phone);
                break;
            case 3:
                printf("New Password : ");
                scanf("%s", users[index].password);
                break;
            case 4:
                printf("New Balance : ");
                scanf("%f", &users[index].balance);
                break;
            case 5:
                printf("New Rating : ");
                scanf("%f", &users[index].rating);
                break;
            case 6:
                printf("New Total Ride : ");
                scanf("%d",&users[index].totalRides);
            case 0:
                break;
            default:
                printf("invalid!!!!!!\n");
                break;
            }
            UpdateData();
            printf("Update successful! \n");
        } while (choice!=0);
    }
    else{
        printf("User not Found !\n");
    }
    
    
}

#endif