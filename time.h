/*
 * time.h
 *
 *  Created on: 6 αιεπι 2017
 *      Author: advos
 */

#ifndef TIME_H_
#define TIME_H_
#include <assert.h>
typedef struct time_t* Time;

typedef enum {
TIME_SUCCESS,TIME_OUT_OF_MEMORY, TIME_INVALID_INPUT
} TimeResult;

/**
* Allocates a new Time.
*
* Creates a new Time. This function receives two integers, one for state day
* and the second for hour.
* @param int day- day need to be positive or zero.
* @param int hour- hour need to be in range of (00-23)
* @return:
* 	NULL - if allocations failed.
* 	A new Time in case of success.
*/
Time createTime(int day, int hour,TimeResult* result);

Time copyTime(Time time,TimeResult* result);

void destroyTime(Time time);

int getDays(Time time);

TimeResult addDays(Time time,int days);
TimeResult addHour(Time time, int hour);

int getHour(Time time);

bool checkIfDaysZero(Time time);

int compareTimes(Time time,Time time_to_compare);

bool timeIsValid(Time time);

bool IsTimeEquals(Time time1, Time time2);

int DayDifference(Time time1, Time time2);

#endif /* TIME_H_ */
