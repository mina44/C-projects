/*
 * engine_off.h
 *
 *  Created on: Jan 7, 2022
 *      Author: Mina
 */

#ifndef MAIN_MENU_OPTIONS_ENGINE_OFF_H_
#define MAIN_MENU_OPTIONS_ENGINE_OFF_H_

#include"../includes/option.h"

typedef struct ENGINE_OFF_STRUCT
{
	optionType base;
}engine_offType;


engine_offType* ENGINE_off();
void ENGINE_offSetClbk(void(*a_engine_off_clbk)(void));

#endif /* MAIN_MENU_OPTIONS_ENGINE_OFF_H_ */
