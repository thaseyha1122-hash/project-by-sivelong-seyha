#ifndef STRUCT_H
#define STRUCT_H

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

#endif