#ifndef DATA_H
#define DATA_H

#include "struct.h"
#include <stdio.h>


void SaveData(User *u) {
    FILE *fptr = fopen("data.txt", "a");
    if (!fptr) { printf("Warning: could not save data.\n"); return; }

    fprintf(fptr, "%d %s %s %s %s %d %.2f %.2f %d\n",
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
}

#endif
