#ifndef STRUCT_H
#define STRUCT_H

#include <time.h>

typedef enum {PASSENGER = 1, DRIVER, ADMIN} userRole;

typedef struct
{
    int id;
    char name[100];
    char gender[10];
    char phone[20];
    char password[20];
    userRole role;
    float balance;
    float rating;
    int totalRides;
    char modelCar[20];

} User;


typedef struct {
    int bookingID;
    int userID;
    char pickupLocation[100];
    char dropoffLocation[100];
    char pickupTime[20];
    float fare;
    int status; // 0: Pending, 1: Confirmed, 2: Completed, 3: Cancelled
} Booking;
 

typedef struct{
    int id;
    char pickup[50];
    char dropoff[50];
    char pickupTime[20];       // start time
    char dropTime[20];         // expected finish time
    char model[50];
    int seatAvailable;
    float price;
    char travelTime[20];
    int TotalSeat;
    char **seatStatus;   //pointer 2D array
} Car;


typedef struct{
    int id;
    char pickup[50];
    char dropoff[50];
    char pickupTime[20]; // start time
    char dropTime[20];   // expected finish time
    char model[50];
    float price;
    char travelTime[20];
    int seatStatus;
    char date[50];
} History;

#endif