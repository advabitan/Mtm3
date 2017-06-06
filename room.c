/*
 * room.c
 *
 *  Created on: 6 αιεπι 2017
 *      Author: advos
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "room.h"


struct room_t {
	Email company_email;
	TechnionFaculty faculty_enum;
	int room_id;
	int price_for_one_player;
	int recommended_amount_of_players;
	int start_work_hour;
	int end_work_hour;
	int difficulty;
	Set reservations;
	int num_of_reservations;

};

static bool isPositive(int input){
	return input>0;
}


static bool isPriceForOnePlayerValid(int price){
	return ( price>0 && price%4 == 0 );
}


static bool isDifficultIsValid(int level){
	return ( level>=1 && level<=10 );
}


static bool isValidHour(int hour){
	return ( hour>=0 && hour<=24 );
}


static bool checkHoursOfStartAndEndOfWorkValid(int start_hour,int end_hour){
   return ( isValidHour(start_hour) &&
		    isValidHour(end_hour) &&
			end_hour>start_hour );
}


static bool CheckIfIntInputForCreateRoomValid(int room_id,
int price_for_one_player,int recommended_amount_of_players,
int start_hour,int end_hour,int difficulty){

	return ( isPositive(room_id) &&
			 isPositive(recommended_amount_of_players) &&
			 isPriceForOnePlayerValid(price_for_one_player) &&
			 checkHoursOfStartAndEndOfWorkValid(start_hour,end_hour) &&
			 isDifficultIsValid(difficulty) );
}


Room createRoom(char* email,int room_id,int price_for_one_player,
int recommended_amount_of_players,int start_hour,int end_hour,
int difficulty,TechnionFaculty faculty,RoomResult *result){

	if(!CheckIfIntInputForCreateRoomValid(room_id,price_for_one_player,
	recommended_amount_of_players,start_hour,end_hour,difficulty)) {
		*result = ROOM_INVALID_INPUT;
		return NULL;
	}

	Room room = malloc(sizeof(*room));
	if(!room){
		*result = ROOM_OUT_OF_MEMORY;
		return NULL;
	}
	EmailResult email_result;
	room->company_email=createEmail(email,&email_result);
	if(email_result!=EMAIL_SUCCESS){
		switch(email_result){
			case EMAIL_OUT_OF_MEMORY: *result=ROOM_OUT_OF_MEMORY;
			return NULL;
			case EMAIL_INVALID_INPUT: *result=ROOM_INVALID_INPUT;
			return NULL;
			default:break;
		}
	}
	room->room_id=room_id;
	room->faculty_enum=faculty;
	room->price_for_one_player=price_for_one_player;
	room->recommended_amount_of_players=recommended_amount_of_players;
	room->start_work_hour=start_hour;
    room->end_work_hour=end_hour;;
	room->difficulty=difficulty;
	room->num_of_reservations=0;

	//room->reservations=setCreate(copyReservation,destroyReservation,cmpReservationTime);
	if(!room->reservations){
		*result=ROOM_OUT_OF_MEMORY;
		return NULL;
	}

	*result=ROOM_SUCCESS;
	return room;

}


Room copyRoom(Room room,RoomResult *result){
	assert(room);
	Room copied_room=malloc(sizeof(*room));
	if(!copied_room){
		*result=ROOM_OUT_OF_MEMORY;
		return NULL;
	}
	EmailResult email_result;
	copied_room->company_email=copyEmail(room->company_email,&email_result);
	if(email_result!=EMAIL_SUCCESS){
		switch(email_result){
			case EMAIL_OUT_OF_MEMORY: *result=ROOM_OUT_OF_MEMORY;
			return NULL;
			case EMAIL_INVALID_INPUT: *result=ROOM_INVALID_INPUT;
			return NULL;
			default:break;
		}
	}
	copied_room->room_id=room->room_id;
	copied_room->faculty_enum=room->faculty_enum;
	copied_room->price_for_one_player=room->price_for_one_player;
	copied_room->recommended_amount_of_players=room->recommended_amount_of_players;
	copied_room->start_work_hour=room->start_work_hour;
	copied_room->end_work_hour=room->end_work_hour;
	copied_room->difficulty=room->difficulty;
	copied_room->num_of_reservations=room->num_of_reservations;

	//room->reservations=setCopy(room->reservations);
	if(!room->reservations){
		*result=ROOM_OUT_OF_MEMORY;
		return NULL;
	}
	*result=ROOM_SUCCESS;
	return room;

}


int cmpRooms(Room room1,Room room2){
	assert(room1&&room2);
	return room1->room_id-room2->room_id;
}


void destroyRoom(Room room){
	assert(room);
	//setDestroy(room->reservations);
	destroyEmail(room->company_email);
	free(room);

}


char* getEmailStringOfCompanyOfRoom(Room room){
	assert(room);
	return getEmail(room->company_email);
}


int getRoomId(Room room){
	assert(room);
	return room->room_id;
}


int getPriceForOnePlayerInRoom(Room room){
	assert(room);
	return room->price_for_one_player;
}


int getRecommendedAmountOfPlayersInRoom(Room room){
	assert(room);
	return room->recommended_amount_of_players;
}


int getStartWorkHourOfRoom(Room room){
	assert(room);
	return room->start_work_hour;
}


int getEndWorkHourOfRoom(Room room){
	assert(room);
	return room->end_work_hour;
}


int getDifficultyOfRoom(Room room){
	assert(room);
	return room->difficulty;
}


int getNumOfReservationsForRoom(Room room){
	assert(room);
	return room->num_of_reservations;
}


Set getSetOfReservationsInRoom(Room room){
	assert(room);
	return room->reservations;
}


TechnionFaculty getFacultyId(Room room){
	assert(room);
	return room->faculty_enum;
}


/*bool CheckIfRoomAvailableAtTime(Room room,Time time){
	assert(room&&time);
	SET_FOREACH(Reservation,iterator,room->reservations){
		if(compareTimes(getReservationTime(iterator),time)==0)
			return false;
	}
	return true;
}*/
