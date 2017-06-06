/*
 * time.c
 *
 *  Created on: 6 αιεπι 2017
 *      Author: advos
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "time.h"

struct time_t {
	int day;
	int hour;
};


int compareTimes(Time time,Time time_to_compare) {
	 assert(timeIsValid(time) && timeIsValid(time_to_compare));
	 if(time->day>=time_to_compare->day)
		return 1;
	 if(time->day==time_to_compare->day)
		 return (time->hour-time_to_compare->hour);
	return -1;
}

static bool isHourValid(int hour){
	return hour>=0&&hour<=23;
}

static bool isDayValid(int day){
	return day>=0;
}

Time createTime(int day,  int hour,TimeResult* result){

	if(!isHourValid(hour)||!isDayValid(day)){//checking if hour and day valid
		*result=TIME_INVALID_INPUT;
		return NULL;
	}
	Time time= malloc(sizeof(*time));
	if(!time){//if allocation failed
		*result=TIME_OUT_OF_MEMORY;
		return NULL;
	}
	time->day=day;
	time->hour=hour;
	*result=TIME_SUCCESS;

	return time;

}

void destroyTime(Time time){
	assert(time != NULL);
	free(time);
}

int getDays(Time time){
	assert(time != NULL);
	return time->day;
}

TimeResult addDays(Time time,int day){
	assert(time != NULL);
	if(isDayValid(day))
	 return TIME_INVALID_INPUT;
	time->day+=day;
	return TIME_SUCCESS;
}
TimeResult addHour(Time time, int hour){
	assert(time != NULL);
	if(!isHourValid(hour+time->hour))
		return TIME_INVALID_INPUT;
	time->hour+=hour;
	return TIME_SUCCESS;

}
int getHour(Time time){
	assert(time != NULL);
	return time->hour;
}


bool checkIfDaysZero(Time time){
	assert(time != NULL);
	return time->day==0;
}

bool timeIsValid(Time time) {
	assert(time != NULL);
	return isDayValid(time->day) &&
	isHourValid(time->hour);
}
bool IsTimeEquals(Time time1, Time time2) {
assert(timeIsValid(time1) && timeIsValid(time2));
return time1->day == time2->day && time1->hour==time2->hour;
}
int DayDifference(Time time1, Time time2) {
assert(timeIsValid(time1) && timeIsValid(time2));
if(compareTimes(time1,time2)>0)//time1 is bigger
	return time1->day-(time2->day);
return time2->day-time1->day;
}
Time copyTime(Time time,TimeResult* result){
	assert(timeIsValid(time));
	TimeResult res;
	Time time_result=createTime(time->day,time->hour,&res);
	if(time_result!=NULL&&res==TIME_SUCCESS){
		*result=TIME_SUCCESS;
		return time_result;
	}
	*result=res;
	return NULL;
}


int main(){
	return 0;
}


