#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define ENTER 13

void clearScreen()
{
    system("cls"); // Windows
}

int main()
{
    char *menu[] = {
        "View Bookings",
        "Approve Cancellation",
        "Reject Cancellation",
        "Exit"};

    int total = 4;
    int choice = 0;
    int key;

    while (1)
    {
        clearScreen();

        printf("=====================================\n");
        printf("      ADMIN CANCELLATION MENU\n");
        printf("=====================================\n\n");
        printf("Use UP/DOWN arrow keys and press ENTER.\n\n");

        for (int i = 0; i < total; i++)
        {
            if (i == choice)
                printf(" > %s\n", menu[i]);
            else
                printf("   %s\n", menu[i]);
        }

        key = _getch();

        if (key == 224)
        { // Arrow key prefix
            key = _getch();

            if (key == KEY_UP)
            {
                if (choice > 0)
                    choice--;
                else
                    choice = total - 1;
            }
            else if (key == KEY_DOWN)
            {
                if (choice < total - 1)
                    choice++;
                else
                    choice = 0;
            }
        }
        else if (key == ENTER)
        {
            clearScreen();

            switch (choice)
            {
            case 0:
                printf("Viewing bookings...\n");
                break;

            case 1:
                printf("Approving cancellation...\n");
                break;

            case 2:
                printf("Rejecting cancellation...\n");
                break;

            case 3:
                printf("Goodbye!\n");
                return 0;
            }

            printf("\nPress any key to return...");
            _getch();
        }
    }

    return 0;
}