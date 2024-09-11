/**
 * @file common.h
 * @brief Common header file for the project.
 * @author Mohit Paddhariya
 */

#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MESSAGE_LEN 1000
#define MAX_PERSON_NAME_LEN 1000

// Structure for message
typedef struct message
{
    char message[MAX_MESSAGE_LEN];
    struct message *next;
} MESSAGE;

// Structure for chat
typedef struct chat
{
    char person_name[MAX_PERSON_NAME_LEN];
    int isPin;
    MESSAGE *chats;
    struct chat *next;
} CHAT;

extern MESSAGE *MESSAGE_HEAD;
extern CHAT *CHAT_HEAD, *CURRENT_CHAT;

#endif // COMMON_H