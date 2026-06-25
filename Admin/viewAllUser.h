#ifndef VIEWALLUSER_H
#define VIEWALLUSER_H


#include <stdio.h>
#include "../Data.h"

extern int userCount;
extern User users[100];

void boarder() {
    printf("------------------------------------------------------------------------------------------------------------------------\n");
}
void viewAllUser()
{
    LoadUserCount();
    LoadData();
    if (userCount == 0)
    {
        printf("No users found!\n");
        return;
    }
    system("cls");  // clear the console on terminal
    printf("\n=============================================== USER LIST =============================================================\n\n");
    printf("%-5s %-8s %-15s %-10s %-15s %-10s %-12s %-10s %-10s %-10s\n",
           "No", "ID", "Name", "Gender", "Phone",
           "Role", "Balance", "Rating", "Rides", "Model");
    printf("\n========================================================================================================================\n\n");
    for (int i = 0; i < userCount; i++)
    {
        User *u = &users[i];
        printf("%-5d %-8d %-15s %-10s %-15s %-10d %-12.2f %-10.2f %-10d %-10s\n",
               i + 1,
               u->id,
               u->name,
               u->gender,
               u->phone,
               u->role,
               u->balance,
               u->rating,
               u->totalRides,
               u->modelCar);
        boarder();
    }
}


#endif