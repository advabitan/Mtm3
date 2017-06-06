/*
 * room.h
 *
 *  Created on: 6 αιεπι 2017
 *      Author: advos
 */

#ifndef ROOM_H_
#define ROOM_H_
#include <assert.h>
#include "mtm_ex3.h"
#include "email.h"
#include "set.h"
#include "time.h"


typedef struct room_t* Room;
typedef enum {
ROOM_SUCCESS,ROOM_OUT_OF_MEMORY, ROOM_INVALID_INPUT
} RoomResult;

Room createRoom(char* email,int room_id,int price_for_one_player,
int recommended_amount_of_players,int start_hour,int end_hour,
int difficulty,TechnionFaculty faculty,RoomResult *result);


Room copyRoom(Room room,RoomResult *result);


int cmpRooms(Room room1,Room room2);


void destroyRoom(Room room);


char* getEmailStringOfCompanyOfRoom(Room room);


int getRoomId(Room room);


int getPriceForOnePlayerInRoom(Room room);


int getRecommendedAmountOfPlayersInRoom(Room room);


int getStartWorkHourOfRoom(Room room);


int getEndWorkHourOfRoom(Room room);


int getDifficultyOfRoom(Room room);


int getNumOfReservationsForRoom(Room room);


Set getSetOfReservationsInRoom(Room room);


TechnionFaculty getFacultyId(Room room);


bool CheckIfRoomAvailableAtTime(Room room,Time time);




#endif /* ROOM_H_ */


