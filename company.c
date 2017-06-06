/*
 * company.c
 *
 *  Created on: 6 αιεπι 2017
 *      Author: advos
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "company.h"


struct company_t {
	Email email;
	TechnionFaculty faculty_enum;
	Set rooms;
	int num_of_rooms;
};

TechnionFaculty getFacultyOfCompany(Company company){
	assert(!company);
	return company->faculty_enum;
}


char* getStringEmailOfCompany(Company company){
	assert(!company);
	return getEmail(company->email);
}


Company createCompany(char* email,TechnionFaculty faculty,CompanyResult* result){

	Company company = malloc(sizeof(*company));
	if(!company) {
		*result = COMPANY_OUT_OF_MEMORY;
		return NULL;
	}

	//company->rooms = setCreate(copyRoom,destroyRoom,compareRoomId);

	EmailResult email_result;
	company->email = createEmail(email, &email_result);
	switch(email_result){
		case EMAIL_OUT_OF_MEMORY:
			*result = COMPANY_OUT_OF_MEMORY;
			return NULL;
		case EMAIL_INVALID_INPUT:
			*result = COMPANY_INVALID_INPUT;
			return NULL;
		case EMAIL_SUCCESS: break;
	}

	company->faculty_enum = faculty;
	company->num_of_rooms = 0;

	*result = COMPANY_SUCCESS;
	return company;
}


void destroyCompany(Company company){

	setDestroy(company->rooms);
	destroyEmail(company->email);
	free(company);
}


int getNumOfRoomsInCompany(Company company){
	assert(company!=NULL);
	return company->num_of_rooms;
}


Set getSetRoomsInCompany(Company company){
	assert(company!=NULL);
	return company->rooms;

}


Company CompanyCopy(Company company, CompanyResult* result){
	assert(company);
	Company copied_company= malloc(sizeof(*company));
	if(!copied_company){
		*result=COMPANY_OUT_OF_MEMORY;
		return NULL;
	}
	copied_company->rooms = setCopy(company->rooms);

	EmailResult email_result;
	copied_company->email = copyEmail(company->email, &email_result);
	switch(email_result){
		case EMAIL_OUT_OF_MEMORY:
			*result = COMPANY_OUT_OF_MEMORY;
			return NULL;
		case EMAIL_INVALID_INPUT:
			*result = COMPANY_INVALID_INPUT;
			return NULL;
		case EMAIL_SUCCESS: break;
	}

	copied_company->faculty_enum = company->faculty_enum;
	copied_company->num_of_rooms = company->faculty_enum ;

	*result = COMPANY_SUCCESS;
	return copied_company;

}

int compareCompanies(Company company1, Company company2){
	return strcmp(getStringEmailOfCompany(company1),
			getStringEmailOfCompany(company2))==0;

}

