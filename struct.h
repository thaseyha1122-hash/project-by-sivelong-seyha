typedef enum {PASSENGER = 1, DRIVER, ADMIN} userRole;

typedef struct
{
    int id;
    char name[100];
    char phone[20];
    char password[20];
    userRole role;
    float balance;
    float rating;
    int totalRides;
} user;

