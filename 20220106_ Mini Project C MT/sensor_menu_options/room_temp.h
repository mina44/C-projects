/*
 * room_temp.h
 *
 *  Created on: Jan 8, 2022
 *      Author: Mina
 */

#ifndef SENSOR_MENU_OPTIONS_ROOM_TEMP_H_
#define SENSOR_MENU_OPTIONS_ROOM_TEMP_H_

#include"../includes/option.h"

typedef struct ROOM_TEMP_STRUCT{
	optionType base;
}roomTempType;

roomTempType* ROOM_temp(void);
void ROOM_tempSetClbk(void(*a_room_temp_clbk)(void));

#endif /* SENSOR_MENU_OPTIONS_ROOM_TEMP_H_ */
