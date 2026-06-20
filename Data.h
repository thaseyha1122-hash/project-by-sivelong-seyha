#ifndef DATA_H
#define DATA_H

#include "struct.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

extern int userCount;
extern User users[100];
extern int carCount;
extern Car cars[10];

extern Car cars[10];
//ADMIN DATA
void seedAdmininIfne();

//USER COUNT

void SaveUserCount() {
    FILE *fptr = fopen("usercount.csv", "w");
    if (!fptr) { printf("Warning: could not save user count.\n"); return; }
    fprintf(fptr, "%d", userCount);
    fclose(fptr);
}

void LoadUserCount() {
    FILE *fptr = fopen("usercount.csv", "r");
    if (!fptr) { userCount = 0; return; }
    fscanf(fptr, "%d", &userCount);
    fclose(fptr);
}

//USER DATA

void LoadData()
{
    FILE *fptr = fopen("data.csv", "r");
    if (!fptr)
        return;
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
    FILE *fptr = fopen("data.csv", "w");
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
    LoadUserCount();
    fclose(fptr);
}

void SaveData(User *u) {
    FILE *fptr = fopen("data.csv", "a");
    if (!fptr) { printf("Warning: could not save data.\n"); return; }
    // Check if file is empty → write header once
    // fseek(fptr, 0, SEEK_END);
    // long size = ftell(fptr);

    // if (size == 0)
    // {
    //     fprintf(fptr,
    //     "ID|Name|Gender|Phone|Password|Role|Balance|Rating|TotalRides\n");
    // }

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

void createDefaultAdmin()
{
    for (int i = 0; i < userCount; i++)
    {
        if (users[i].role == ADMIN) {
            return; // already exists
        }  
    }

    User *u = &users[userCount++];
    u->id = 1000;

    strcpy(u->name, "Admin");
    strcpy(u->gender, "N/A");
    strcpy(u->phone, "0000");
    strcpy(u->password, "admin123");

    u->role = ADMIN;
    u->balance = 0;
    u->rating = 5;
    u->totalRides = 0;

    userCount--;
    SaveData(u);
    
}

//CAR DATA 

void SavecarCount()
{
    FILE *fptr = fopen("carCount.csv", "w");
    if (!fptr)
    {
        printf("Warning: could not save car count.\n");
        return;
    }
    fprintf(fptr, "%d", carCount);
    fclose(fptr);
}

void LoadcarCount()
{
    FILE *fptr = fopen("carCount.csv", "r");
    if (!fptr)
    {
        carCount = 0;
        return;
    }
    fscanf(fptr, "%d", &carCount);
    fclose(fptr);
}

void LoadCarData()
{
    FILE *fptr = fopen("CarData.csv", "r");
    if (!fptr)
        return;
    int i = 0;

    // Clear previous data
    memset(cars, 0, sizeof(cars));

    while (fscanf(fptr, "%d\t|%99[^|]\t|%99[^|]\t|%99[^|]\t|%99[^|]\t|%99[^|]\t|%99[^|]\t|%.2f\t|%d\n",
                  cars[i].id,
                  cars[i].pickup,
                  cars[i].dropoff,
                  cars[i].travelTime,
                  cars[i].pickupTime,
                  cars[i].dropTime,
                  cars[i].model,
                  cars[i].price,
                  cars[i].seatAvailable) == 9)
    {
        i++;
    }

    carCount = i;
    fclose(fptr);
}

void CarSave(Car *u){
    FILE *f = fopen("CarData.csv", "a");
    if (!f) {printf("Warning: could not save ddata.\n");}

    fprintf(f, "%d\t|%s\t|%s\t|%s\t|%s\t|%s\t|%s\t|%.2f\t|%d\n",
            u->id,
            u->pickup,
            u->dropoff,
            u->travelTime,
            u->pickupTime,
            u->dropTime,
            u->model,
            u->price,
            u->seatAvailable

    );

    fclose(f);
    carCount++;
    SavecarCount();
}


#endif
