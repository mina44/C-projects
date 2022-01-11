/*
 * quit.h
 *
 *  Created on: Jan 7, 2022
 *      Author: Mina
 */

#ifndef MAIN_MENU_OPTIONS_QUIT_H_
#define MAIN_MENU_OPTIONS_QUIT_H_

#include"../includes/option.h"

typedef struct QUIT_STRUCT
{
	optionType base;
}quitType;


quitType* QUIT(void);
void QUIT_setClbk(void(*a_quit_clbk)(void));


#endif /* MAIN_MENU_OPTIONS_QUIT_H_ */
