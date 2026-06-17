#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include "userLogin.h"

#include "Passanger/passagenerMenu.h"
#include "Data.h"


int userCount = 0;

int main(){
    LoadUserCount();

    int choices;
    printf("\n===================Manu choices====================\n");
    printf(" 1. Login \n");
    printf(" 2. Register \n");
    printf("Enter your choice : "); scanf("%d", &choices);
    getchar();
    switch(choices) {
        case 1:
            login();
            break;
        case 2:
            Register();
            //passagenerMenu();
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
    
}