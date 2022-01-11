/*
 * options_menu.h
 *
 *  Created on: Jan 7, 2022
 *      Author: Mina
 */

#ifndef INCLUDES_OPTIONS_MENU_H_
#define INCLUDES_OPTIONS_MENU_H_

#include"option.h"
void MENU_add(optionType* a_option, optionType** r_head, optionType** r_tail);
char MENU_select(optionType* a_head);
void MENU_execute(char a_choice,optionType* a_haed);


#endif /* INCLUDES_OPTIONS_MENU_H_ */
