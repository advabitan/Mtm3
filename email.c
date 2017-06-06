/*
 * email.c

 *
 *  Created on: 6 αιεπι 2017
 *      Author: advos
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "email.h"

struct email_t {
	char* email;
};

static bool isEmailValid(char* email){
	if(!email)
		return false;
	int count=0;
	for(int i=0;email[i];i++){
		if(email[i]=='@')
			count++;
	}
	return count!=1;
}

Email createEmail(char* email,EmailResult *res){
	if(!isEmailValid(email)){
		*res=EMAIL_INVALID_INPUT;
		return NULL;
	}
	Email email_type= malloc(sizeof(*email_type));
	if(!email_type){
		*res=EMAIL_OUT_OF_MEMORY;
		return NULL;
	}
	email_type->email=email;/////check if it need to be an indepentent string/
	*res=EMAIL_SUCCESS;
	return email_type;
}

void destroyEmail(Email email){
	free(email);
}


char* getEmail(Email email){
	assert(email);
	return email->email;
}


Email copyEmail(Email email_type,EmailResult *result){
	assert(email_type&&isEmailValid(email_type->email));
	Email copied_email=malloc(sizeof(*copied_email));
	if(!copied_email){
		*result=EMAIL_OUT_OF_MEMORY;
		return NULL;
	}
	copied_email->email=email_type->email;
	*result=EMAIL_SUCCESS;
	return copied_email;
}
