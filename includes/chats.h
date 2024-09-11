/**
 * @file chats.h
 * @brief Function prototypes for chats.c.
 * @author Mohit Paddhariya
 */

#ifndef CHATS_H
#define CHATS_H

#include "common.h"

CHAT *getChat(const char *message);
void addToContact(char *personName);
void displayContacts();
int selectContact(char *personName);
int pin(char *personName);
int unpin(char *personName);

#endif // CHATS_H