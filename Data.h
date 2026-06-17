#ifndef DATA_H
#define DATA_H

#include "struct.h"
#include <stdio.h>

extern int userCount;

void SaveUserCount() {
    FILE *fptr = fopen("usercount.txt", "w");
    if (!fptr) { printf("Warning: could not save user count.\n"); return; }
    fprintf(fptr, "%d", userCount);
    fclose(fptr);
}

void LoadUserCount() {
    FILE *fptr = fopen("usercount.txt", "r");
    if (!fptr) { userCount = 0; return; }
    fscanf(fptr, "%d", &userCount);
    fclose(fptr);
}

void SaveData(User *u) {
    FILE *fptr = fopen("data.txt", "a");
    if (!fptr) { printf("Warning: could not save data.\n"); return; }


    fprintf(fptr, "%d %s %s %s %s %d %.2f %.2f %d\n",
            u->id,
            u->name,
            u->gender,
            u->phone,
            u->password,
            u->role,
            u->balance,
            u->rating,
            u->totalRides
        );

    fclose(fptr);
    userCount++;
    SaveUserCount();
}

#endif
