/*
 * engine_off.c
 *
 *  Created on: Jan 7, 2022
 *      Author: Mina
 */

#include "engine_off.h"

#include<stdlib.h>
#include<stdio.h>

static void ENGINE_offFn(void); // Default functionality for this option

static void (*g_engine_off_clbk)(void)=ENGINE_offFn;


engine_offType* ENGINE_off()
{
	engine_offType* engine_off = calloc(1,sizeof(engine_offType));

	engine_off= (engine_offType*) optionConstructor((optionType*)engine_off,
													(char*)"Turn off the vehicle engine",
													g_engine_off_clbk);

	return engine_off;
}

static void ENGINE_offFn(void){
	printf("ENGINE OFF\n");
	fflush(stdout);
}


void ENGINE_offSetClbk(void(*a_engine_off_clbk)(void))
{
	g_engine_off_clbk = a_engine_off_clbk;
}
