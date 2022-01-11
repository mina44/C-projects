/*
 * engine_temp.h
 *
 *  Created on: Jan 8, 2022
 *      Author: Mina
 */

#ifndef SENSOR_MENU_OPTIONS_ENGINE_TEMP_H_
#define SENSOR_MENU_OPTIONS_ENGINE_TEMP_H_

#include"../includes/option.h"

typedef struct ENGINE_TEMP_STRUCT{
	optionType base;
}engineTempType;

engineTempType* ENGINE_temp(void);
void ENGINE_tempSetClbk(void (*a_engine_temp_clbk)(void));

#endif /* SENSOR_MENU_OPTIONS_ENGINE_TEMP_H_ */
