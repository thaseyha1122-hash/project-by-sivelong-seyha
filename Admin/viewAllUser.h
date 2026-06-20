#ifndef VIEWALLUSER_H
#define VIEWALLUSER_H
#include <stdio.h>
#include "../Data.h"

extern int userCount;
extern User users[100];
void viewAllUser()
{
    LoadUserCount();
    LoadData();
    if (userCount == 0)
    {
        printf("No users found!\n");
        return;
    }

    printf("\n========== USER LIST ==========\n");

    for (int i = 0; i < userCount; i++)
    {
        User *u = &users[i];
        printf("ID          : %d\n", u->id);
        printf("Name        : %s\n", u->name);
        printf("Gender      : %s\n", u->gender);
        printf("Phone       : %s\n", u->phone);
        printf("Password    : %s\n", u->password);
        printf("Role        : %d\n", u->role);
        printf("Balance     : %.2f\n", u->balance);
        printf("Rating      : %.2f\n", u->rating);
        printf("Total Rides : %d\n", u->totalRides);
        printf("-------------------------------\n");
    }
}


#endif