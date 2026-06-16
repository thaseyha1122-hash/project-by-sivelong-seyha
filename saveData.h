#include "userLogin.h"
#include "struct.h"
// #define MAX_USERS 100

// User users[MAX_USERS];

// int userCount = 0;
void saveUsersCSV()
{

FILE *fp;

fp = fopen("users.csv","w");


fprintf(fp,
"ID,Name,Gender,Phone,Role,Balance,Rating,Rides\n");



for(int i=0;i<userCount;i++){

    char *roleName;


    if(users[i].role == PASSENGER)
        roleName = "PASSENGER";

    else if(users[i].role == DRIVER)
        roleName = "DRIVER";

    else
        roleName = "ADMIN";



    fprintf(fp,
    "%d,%s,%s,%s,%s,%.2f,%.2f,%d\n",

    users[i].id,
    users[i].name,
    users[i].gender,
    users[i].phone,
    roleName,
    users[i].balance,
    users[i].rating,
    users[i].totalRides

);
}


fclose(fp);

}