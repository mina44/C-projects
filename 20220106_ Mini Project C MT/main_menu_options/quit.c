/*
 * quit.c
 *
 *  Created on: Jan 7, 2022
 *      Author: Mina
 */

#include "../main_menu_options/quit.h"

#include<stdlib.h>
#include<stdio.h>

static void QUIT_fn(void);
static void (*g_quit_clbk)(void) = QUIT_fn; //Default functionality for this option


quitType* QUIT(void)
{
	quitType* quit= calloc(1,sizeof(quitType));

	quit = (quitType*)optionConstructor((optionType*)quit,(char*)"Quit the system",g_quit_clbk);

	return quit;
}

static void QUIT_fn(void)
{
	printf("QUIT SYSTEM\n");
	fflush(stdout);
}


void QUIT_setClbk(void(*a_quit_clbk)(void))
{
	g_quit_clbk = a_quit_clbk;
}
