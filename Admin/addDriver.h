

#include "../struct.h"
#include <stdio.h>
#include "../Data.h"

extern User users[100];
extern int userCount;

void addDriver()
{
    if (userCount >= 100)
    {
        printf("\nError: User limit reached! Cannot register more users.\n");
        return;
    }

    User *u = &users[userCount];

    printf("\n =============== Register Form ============= \n");
    printf("Enter Your Name : ");
    scanf("%99[^\n]", u->name);
    getchar();
    printf("Enter Your Gender : ");
    scanf("%9s", u->gender);
    getchar();
    printf("Enter Phone Number : ");
    scanf("%19s", u->phone);
    getchar();
    printf("Enter car model : ");
    scanf("%19s", u->modelCar);
    getchar();
    for (int i = 0; i < userCount; i++)
    {
        if (strcmp(users[i].phone, u->phone) == 0)
        {
            printf("\nPhone already registered.\n");
            return;
        }
    }
    printf("Enter password : ");
    scanf("%19s", u->password);
    getchar();

    u->id = 2000 + userCount;
    u->role = DRIVER;
    u->balance = 0;
    u->rating = 0;
    u->totalRides = 0;

    SaveData(u);
    printf("\nRegistration successful! \n");
}