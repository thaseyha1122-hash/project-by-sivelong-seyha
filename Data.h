#ifndef DATA_H
#define DATA_H

#include "struct.h"
#include <stdio.h>
#include <string.h>

extern int userCount;
extern User users[100];

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

void LoadData() {
    FILE *fptr = fopen("data.txt", "r");
    if (!fptr) return;
    int i = 0;
    
    // Clear previous data
    memset(users, 0, sizeof(users));

    while (fscanf(fptr, "%d|%99[^|]|%9[^|]|%19[^|]|%19[^|]|%d|%f|%f|%d",
                  &users[i].id,
                  users[i].name,
                  users[i].gender,
                  users[i].phone,
                  users[i].password,
                  &users[i].role,
                  &users[i].balance,
                  &users[i].rating,
                  &users[i].totalRides) == 9)
    {
        i++;
    }

    userCount = i;
    fclose(fptr);
}

void UpdateData() {
    FILE *fptr = fopen("data.txt", "w");
    if (!fptr) { printf("Error: could not save data.\n"); return; }
    
    for (int i = 0; i < userCount; i++) {
        fprintf(fptr, "%d|%s|%s|%s|%s|%d|%.2f|%.2f|%d\n",
                users[i].id,
                users[i].name,
                users[i].gender,
                users[i].phone,
                users[i].password,
                users[i].role,
                users[i].balance,
                users[i].rating,
                users[i].totalRides);
    }
    
    fclose(fptr);
}

void SaveData(User *u) {
    FILE *fptr = fopen("data.txt", "a");
    if (!fptr) { printf("Warning: could not save data.\n"); return; }

    fprintf(fptr, "%d|%s|%s|%s|%s|%d|%.2f|%.2f|%d\n",
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
