/**
 * @file messages.c
 * @brief Function definitions for messages.h.
 * @author Mohit Paddhariya
 */

#include "common.h"

/**
 * @brief Get a new message.
 * 
 * @param message The message to be stored.
 * @return MESSAGE* The new message.
 */
MESSAGE *getMessage(const char *message)
{
    MESSAGE *newMessage = (MESSAGE *)malloc(sizeof(MESSAGE));
    strncpy(newMessage->message, message, sizeof(newMessage->message) - 1);
    newMessage->message[sizeof(newMessage->message) - 1] = '\0';
    newMessage->next = NULL;
    return newMessage;
}

/**
 * @brief Send a message.
 * 
 * @param message The message to be sent.
 */
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

/**
 * @brief Display the conversation history.
 */
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