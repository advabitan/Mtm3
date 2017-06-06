/*
 * email.h
 *
 *  Created on: 6 αιεπι 2017
 *      Author: advos
 */

#ifndef EMAIL_H_
#define EMAIL_H_
#include <assert.h>
typedef struct email_t* Email;

typedef enum {
EMAIL_SUCCESS,EMAIL_OUT_OF_MEMORY, EMAIL_INVALID_INPUT
} EmailResult;

Email createEmail(char* email,EmailResult *res);

void destroyEmail(Email email);

char* getEmail(Email email);

Email copyEmail(Email email_type,EmailResult *result);


#endif /* EMAIL_H_ */
