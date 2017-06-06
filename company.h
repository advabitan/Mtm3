/*
 * company.h
 *
 *  Created on: 6 αιεπι 2017
 *      Author: advos
 */

#ifndef COMPANY_H_
#define COMPANY_H_
#include <assert.h>
#include "mtm_ex3.h"
#include "set.h"
#include "email.h"
#include <string.h>


typedef struct company_t* Company;
typedef enum {
COMPANY_SUCCESS,COMPANY_OUT_OF_MEMORY, COMPANY_INVALID_INPUT
} CompanyResult;

Company createCompany(char* email,TechnionFaculty faculy,CompanyResult* result);

void destroyCompany(Company company);

TechnionFaculty getFacultyOfCompany(Company company);

char* getStringEmailOfCompany(Company company);

int getNumOfRoomsInCompany(Company company);

Set getSetOfRoomsInCompany(Company company);

Company CompanyCopy(Company company, CompanyResult* result);

int compareCompanies(Company company1, Company company2);

#endif /* COMPANY_H_ */
