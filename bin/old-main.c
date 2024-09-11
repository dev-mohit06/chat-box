#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_MESSAGE_LEN 1000
#define MAX_PERSON_NAME_LEN 1000

typedef struct message
{
    char message[MAX_MESSAGE_LEN];
    struct message *next;
} MESSAGE;

typedef struct chat
{
    char person_name[MAX_PERSON_NAME_LEN];
    int isPin;
    MESSAGE *chats;
    struct chat *next;
} CHAT;

MESSAGE *MESSAGE_HEAD = NULL;
CHAT *CHAT_HEAD = NULL, *CURRENT_CHAT = NULL;

// MESSAGES FUNCTIONS
MESSAGE *getMessage(const char *message)
{
    MESSAGE *newMessage = (MESSAGE *)malloc(sizeof(MESSAGE));
    strncpy(newMessage->message, message, sizeof(newMessage->message) - 1);
    newMessage->message[sizeof(newMessage->message) - 1] = '\0';
    newMessage->next = NULL;
    return newMessage;
}

void send(char *message)
{
    MESSAGE *msg = getMessage(message);

    if (CURRENT_CHAT->chats == NULL)
    {
        CURRENT_CHAT->chats = msg;
        return;
    }

    MESSAGE *current = CURRENT_CHAT->chats;
    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = msg;
}

void display()
{
    if (CURRENT_CHAT == NULL || CURRENT_CHAT->chats == NULL)
    {
        printf("\n-- No conversation history for the selected contact. --\n");
        return;
    }

    MESSAGE *current = CURRENT_CHAT->chats;
    printf("\n-- Conversation History with %s --\n", CURRENT_CHAT->person_name);
    while (current != NULL)
    {
        printf("%s\n", current->message);
        current = current->next;
    }
}

// CONTACT FUNCTIONS

CHAT *getChat(const char *message)
{
    CHAT *newChat = (CHAT *)malloc(sizeof(CHAT));
    strncpy(newChat->person_name, message, sizeof(newChat->person_name) - 1);
    newChat->person_name[sizeof(newChat->person_name) - 1] = '\0';

    newChat->isPin = 0;
    newChat->chats = NULL;
    newChat->next = NULL;
    return newChat;
}

void addToContact(char *personName)
{
    CHAT *newPerson = getChat(personName);
    if (CHAT_HEAD == NULL)
    {
        CHAT_HEAD = newPerson;
        return;
    }

    CHAT *current = CHAT_HEAD;
    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = newPerson;
}

void displayContacts()
{
    if (CHAT_HEAD == NULL)
    {
        printf("\n-- No one is in your contact list. Let's begin when you're ready! --\n");
        return;
    }

    CHAT *current = CHAT_HEAD;
    printf("\n-- Contacts (Pinned) --\n");

    while (current != NULL)
    {
        if (current->isPin == 1)
        {
            printf("%s\n", current->person_name);
        }
        current = current->next;
    }

    current = CHAT_HEAD;
    printf("\n-- Contacts (Others) --\n");

    while (current != NULL)
    {
        if (current->isPin == 0)
        {
            printf("%s\n", current->person_name);
        }
        current = current->next;
    }
}

int selectContact(char *personName)
{
    if (CHAT_HEAD == NULL)
    {
        printf("\n-- No contacts in your list --\n");
        return 0;
    }

    CHAT *current = CHAT_HEAD;

    while (current != NULL)
    {
        if (strcmp(current->person_name, personName) == 0)
        {
            CURRENT_CHAT = current;
            printf("\n-- Contact '%s' selected --\n", current->person_name);
            return 1;
        }
        current = current->next;
    }

    printf("\n-- Contact '%s' not found in your list --\n", personName);
    return 0;
}

int pin(char *personName)
{
    if (CHAT_HEAD == NULL)
    {
        printf("\n-- No contacts in your list --\n");
        return 0;
    }

    CHAT *current = CHAT_HEAD;

    while (current != NULL)
    {
        if (strcmp(current->person_name, personName) == 0)
        {
            current->isPin = 1;
            printf("\n-- Contact '%s' pined --\n", current->person_name);
            return 1;
        }
        current = current->next;
    }

    printf("\n-- Contact '%s' not found in your list --\n", personName);
    return 0;
}

int unpin(char *personName)
{
    if (CHAT_HEAD == NULL)
    {
        printf("\n-- No contacts in your list --\n");
        return 0;
    }

    CHAT *current = CHAT_HEAD;

    while (current != NULL)
    {
        if (strcmp(current->person_name, personName) == 0)
        {
            current->isPin = 0; // Corrected from 1 to 0
            printf("\n-- Contact '%s' unpinned --\n", current->person_name);
            return 1;
        }
        current = current->next;
    }

    printf("\n-- Contact '%s' not found in your list --\n", personName);
    return 0;
}

int main()
{

    int choise;
    char message[MAX_MESSAGE_LEN], personName[MAX_PERSON_NAME_LEN];
    // system("clear");
    do
    {
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