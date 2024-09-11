/**
 *  @file : messages.h
 *  @brief : Function prototypes for messages.c.
 *  @author : Mohit Paddhariya
 */

#ifndef MESSAGES_H
#define MESSAGES_H

MESSAGE *getMessage(const char *message);
void send(char *message);
void display();

#endif // MESSAGES_H