#include<stdio.h>
#include "userLogin.h"

int  main(){

    int choices;
    printf("\n===================Manu choices====================\n");
    printf(" 1. Login \n");
    printf(" 2. Register \n");
    printf("Enter your choice : "); scanf("%d", &choices);
    switch(choices) {
        case 1:
            login();
            break;
        case 2:
            register();
            break;
        default:
            printf("Invalid choice.\n");
    }

    login();
    return 0;
}