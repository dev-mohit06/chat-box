/**
 * @file main.c
 * @brief Main file for the project.
 * @author Mohit Paddhariya
 * @date 2021-07-15
 */

// Include header files
#include "common.h"
#include "chats.h"
#include "messages.h"

// Global variables
MESSAGE *MESSAGE_HEAD = NULL;
CHAT *CHAT_HEAD = NULL, *CURRENT_CHAT = NULL;

/**
 * @brief Main function.
 *
 * @return int
 */
int main()
{
    // Local variables
    int choise;
    char message[MAX_MESSAGE_LEN], personName[MAX_PERSON_NAME_LEN];

    // Main loop
    do
    {

        // Home screen
    HOME:
        printf("\n========== HOME ==========\n");
        printf("PRESS 1 : ADD CONTACT\n");
        printf("PRESS 2 : START CHATING\n");
        printf("PRESS 3 : PIN CHAT\n");
        printf("PRESS 4 : UNPIN CHAT\n");
        printf("Enter your choise : ");
        scanf("%d", &choise);

        switch (choise)
        {
        case 1:
            printf("Enter the person name : ");
            scanf(" %[^\n]", personName);
            addToContact(personName);
            break;
        case 2:
            displayContacts();
            printf("Enter the person name : ");
            scanf(" %[^\n]", personName);
            int isPass = selectContact(personName);
            if (isPass)
            {

                // Chat screen
            CHAT:
                printf("\n========== CHATS ==========\n");
                printf("PRESS 1 : SEND MESSAGE\n");
                printf("PRESS 2 : DISPLAY MESSAGE\n");
                printf("PRESS 3 : EXIT\n");
                printf("PRESS 4 : GOTO HOME\n");
                printf("Enter your choise : ");
                scanf("%d", &choise);

                switch (choise)
                {
                case 1:
                    printf("Enter the message : ");
                    scanf(" %[^\n]", message);
                    send(message);
                    break;
                case 2:
                    display();
                    break;
                case 3:
                    exit(0);
                    break;
                case 4:
                    goto HOME;
                default:
                    printf("\n========== INVALID CHOISE ==========\n");
                    break;
                }

                printf("\nDO YOU WANT TO CONTINUE [1/0] : ");
                scanf("%d", &choise);

                if (choise == 0)
                {
                    exit(0);
                }
                else
                {
                    goto CHAT;
                }
            }
            break;
        case 3:
            display();
            printf("Enter the person name : ");
            scanf(" %[^\n]", personName);
            pin(personName);
            break;
        case 4:
            display();
            printf("Enter the person name : ");
            scanf(" %[^\n]", personName);
            unpin(personName);
            break;
        default:
            printf("\n========== INVALID CHOISE ==========\n");
            break;
        }

        printf("\nDO YOU WANT TO CONTINUE [1/0] : ");
        scanf("%d", &choise);

        if (choise == 0)
        {
            exit(0);
        }
        else
        {
            system("clear");
        }

    } while (1);

    return 0;
}