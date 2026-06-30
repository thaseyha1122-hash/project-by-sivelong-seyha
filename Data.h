#ifndef DATA_H
#define DATA_H

#include "struct.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern int userCount;
extern User users[100];
extern int carCount;
extern Car cars[10];
// extern int seatCount;

// Save data seat
// void SaveSeatCount(){
//     FILE *fseat = fopen("seatcount.csv", "w");
//     if(!fseat){
//         printf("Warning !\n");
//         return ;
//     }
//     fprintf(fseat, "%d",seatCount);
//     fclose(fseat);
// }
//load seat
// void loadSeatCount(){
//     FILE *fseat = fopen("seatcount.csv", "r");
//     if (!fseat) { userCount = 0; return; }
//     fscanf(fseat, "%d", &seatCount);
//     fclose(fseat);
// }

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
    if (!fptr) {
        userCount = 0;
        memset(users, 0, sizeof(users));
        return;
    }
    int i = 0;

    // Clear previous data
    memset(users, 0, sizeof(users));

    while (i<100 && fscanf(fptr, "%d|%99[^|]|%9[^|]|%19[^|]|%19[^|]|%d|%f|%f|%d|%99[^\n]",
                  &users[i].id,
                  users[i].name,
                  users[i].gender,
                  users[i].phone,
                  users[i].password,
                  &users[i].role,
                  &users[i].balance,
                  &users[i].rating,
                  &users[i].totalRides,
                  users[i].modelCar) == 10)
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
        fprintf(fptr, "%d|%s|%s|%s|%s|%d|%.2f|%.2f|%d|%s\n",
                users[i].id,
                users[i].name,
                users[i].gender,
                users[i].phone,
                users[i].password,
                users[i].role,
                users[i].balance,
                users[i].rating,
                users[i].totalRides,
                users[i].modelCar
            );
    }
    
    fclose(fptr);
    SaveUserCount();
}

void SaveData(User *u) {
    FILE *fptr = fopen("data.csv", "a");
    if (!fptr) { printf("Warning: could not save data.\n"); return; }

    fprintf(fptr, "%d|%s|%s|%s|%s|%d|%.2f|%.2f|%d|%s\n",
            u->id,
            u->name,
            u->gender,
            u->phone,
            u->password,
            u->role,
            u->balance,
            u->rating,
            u->totalRides,
            u->modelCar
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
    strcpy(u->modelCar, "N/A");

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
    if (!fptr) {
        carCount = 0;
        memset(cars, 0, sizeof(cars));
        return;
    }
    int i = 0;

    // Clear previous data
    memset(cars, 0, sizeof(cars));

    
    while (fscanf(fptr, "%d|%99[^|]|%99[^|]|%99[^|]|%99[^|]|%99[^|]|%99[^|]|%f|%d|%d|",
                  &cars[i].id,
                  cars[i].pickup,
                  cars[i].dropoff,
                  cars[i].travelTime,
                  cars[i].pickupTime,
                  cars[i].dropTime,
                  cars[i].model,
                  &cars[i].price,
                  &cars[i].seatAvailable,
                  &cars[i].TotalSeat) == 10)
    {
        cars[i].seatStatus = malloc(cars[i].TotalSeat * sizeof(char *));
        if (!cars[i].seatStatus)
        {
            printf("Memory error.\n");
            break;
        }

        for (int j = 0; j < cars[i].TotalSeat; j++)
        {
            cars[i].seatStatus[j] = malloc(2 * sizeof(char));
            if (!cars[i].seatStatus[j])
            {
                printf("Memory error.\n");
                break;
            }

            fscanf(fptr, "%1[^,\n]", cars[i].seatStatus[j]); // read "0" or "1"
            fscanf(fptr, "%*c");                             // consume ',' or '\n'
        }
        i++;
    }

    carCount = i;
    fclose(fptr);
}

void UpdateCarData()
{
    FILE *f = fopen("CarData.csv", "w");
    if (!f)
    {
        printf("Warning: could not save data.\n");
        return;
    }
    for (int i=0; i<carCount; i++) {
        fprintf(f, "%03d|%s|%s|%s|%s|%s|%s|%.2f|%d|%d|",
                cars[i].id,
                cars[i].pickup,
                cars[i].dropoff,
                cars[i].travelTime,
                cars[i].pickupTime,
                cars[i].dropTime,
                cars[i].model,
                cars[i].price,
                cars[i].seatAvailable,
                cars[i].TotalSeat);
        for (int j = 0; j < cars[i].TotalSeat; j++)
        {
            fprintf(f, "%s", cars[i].seatStatus[j]);
            if (j < cars[i].TotalSeat - 1)
            {
                fprintf(f, ",");
            }
        }
        fprintf(f, "\n");
    }
    

    fclose(f);
    SavecarCount();
}

void CarSave(Car *u){
    FILE *f = fopen("CarData.csv", "a");
    if (!f) {
        printf("Warning: could not save data.\n");
        return;
    }

    fprintf(f, "%03d|%s|%s|%s|%s|%s|%s|%.2f|%d|%d|",
            u->id,
            u->pickup,
            u->dropoff,
            u->travelTime,
            u->pickupTime,
            u->dropTime,
            u->model,
            u->price,
            u->seatAvailable,
            u->TotalSeat
    );
    for(int i=0; i<u->TotalSeat; i++) {
        fprintf(f, "%s", u->seatStatus[i]);
        if(i<u->TotalSeat-1) {
            fprintf(f, ",");
        }
    }
    fprintf(f, "\n");

    fclose(f);
    carCount++;
    SavecarCount();
}

// User booking history

void history(History *u) {
    FILE *f = fopen("Passenger/BokingHistory.csv", "a");
    if (!f)
    {
        printf("Warning: could not save data.\n");
        return;
    }

    fprintf("");
}


#endif
