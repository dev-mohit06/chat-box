/**
 * @file chats.c
 * @brief Functions for chat operations.
 * @author Mohit Paddhariya
 */
#include "common.h"


/**
 * @brief Get chat object.
 * 
 * @param message 
 * @return CHAT* 
 */
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


/**
 * @brief Add contact to the chat list.
 * 
 * @param personName 
 */
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


/**
 * @brief Display contacts.
 * 
 */
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


/**
 * @brief Select contact.
 * 
 * @param personName 
 * @return int 
 */
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


/**
 * @brief Pin chat.
 * 
 * @param personName 
 * @return int 
 */
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


/**
 * @brief Unpin chat.
 * 
 * @param personName 
 * @return int 
 */
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