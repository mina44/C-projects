/*
 * engine_on.h
 *
 *  Created on: Jan 7, 2022
 *      Author: Mina
 */

#ifndef MAIN_MENU_OPTIONS_ENGINE_ON_H_
#define MAIN_MENU_OPTIONS_ENGINE_ON_H_

#include"../includes/option.h"


typedef struct ENGINE_ON_STRUCT{
	optionType base;
} engine_onType;


engine_onType* ENGINE_on(void);
void ENGINE_onSetClbk(void (*a_engine_on_clbk)(void));

#endif /* MAIN_MENU_OPTIONS_ENGINE_ON_H_ */
