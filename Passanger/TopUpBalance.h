#include "../struct.h"
#include <stdio.h>
#include "../Data.h"

extern User users[100];
extern int loggedInuser;

void TopUp() {
    float balance;
    printf("\n==============================\n");
    printf("Please enter the amount : ");   scanf("%f", &balance);
    printf("\n==============================\n");
    
    users[loggedInuser].balance += balance;

    User *u = &users[loggedInuser];
    UpdateData(u);
    printf("Balance updated successfully!\n");
}