#ifndef PROFILE_H
#define PROFILE_H

#include "../struct.h"
#include <stdio.h>

extern User users[100];
extern int loggedInuser;

void profile_display() {
    if(loggedInuser < 0) {
        printf("No user logged in!\n");
        return;
    }
    
    User *u = &users[loggedInuser];
    printf("\n========== Your Profile ==========\n");
    printf("ID: %d\n", u->id);
    printf("Name: %s\n", u->name);
    printf("Gender: %s\n", u->gender);
    printf("Phone: %s\n", u->phone);
    printf("Balance: %.2f\n", u->balance);
    printf("Rating: %.2f\n", u->rating);
    printf("Total Rides: %d\n", u->totalRides);
    printf("===================================\n");
}

#endif
