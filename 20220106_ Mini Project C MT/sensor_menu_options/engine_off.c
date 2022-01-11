/*
 * engine_off.c
 *
 *  Created on: Jan 7, 2022
 *      Author: Mina
 */

#include "engine_off.h"

#include<stdlib.h>
#include<stdio.h>

static void S_ENGINE_offFn(void); // Default functionality for this option

static void (*g_engine_off_clbk)(void)=S_ENGINE_offFn;


s_engine_offType* S_ENGINE_off()
{
	s_engine_offType* engine_off = calloc(1,sizeof(s_engine_offType));

	engine_off= (s_engine_offType*) optionConstructor(	(optionType*)engine_off,
														(char*)"Turn off the vehicle engine",
														g_engine_off_clbk);

	return engine_off;
}

static void S_ENGINE_offFn(void){
	printf("ENGINE OFF\n");
	fflush(stdout);
}


void S_ENGINE_offSetClbk(void(*a_engine_off_clbk)(void))
{
	g_engine_off_clbk = a_engine_off_clbk;
}
