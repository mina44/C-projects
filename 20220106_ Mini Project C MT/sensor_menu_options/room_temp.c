/*
 * room_temp.c
 *
 *  Created on: Jan 8, 2022
 *      Author: Mina
 */

#include<stdio.h>
#include<stdlib.h>

#include"room_temp.h"

static void ROOM_tempFn(void);

static void (*g_room_temp_clbk)(void)=ROOM_tempFn;

roomTempType* ROOM_temp(void)
{

	roomTempType* room_temp= calloc(1, sizeof(roomTempType));

	room_temp=(roomTempType*)optionConstructor(	(optionType*)room_temp,
												(char*)"Set the room temperature (Temperature Sensor)",
												g_room_temp_clbk);

	return room_temp;
}

void ROOM_tempSetClbk(void(*a_room_temp_clbk)(void))
{
	g_room_temp_clbk = a_room_temp_clbk;
}

static void ROOM_tempFn(void)
{
	printf("ROOM Temp\n");
	fflush(stdout);
}
