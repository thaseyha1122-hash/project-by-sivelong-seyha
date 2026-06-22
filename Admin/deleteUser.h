#ifndef DELETEUSER_H
#define DELETEUSER_H

#include <stdio.h>
#include "../struct.h"
#include "../Data.h"


extern int userCount;
extern User users[100];

void deleteUser() {
    int id;
    printf("\nEnter User ID to delete: "); scanf("%d", &id);
    for (int i=0; i<userCount; i++) {
        if(users[i].id == id) {
            if(users[i].role==ADMIN) {printf("Cannot delete admin.\n"); return;}
            for (int j=i; j<userCount-1; j++) {
                User *u = &users[j];
                int uid = u->id;
                *u = users[j+1];
                u->id = uid;
            }
            userCount--;
            UpdateData();
            printf("User deleted.\n");
            return;
        }
    }
    printf("User not found! \n");
}

#endif