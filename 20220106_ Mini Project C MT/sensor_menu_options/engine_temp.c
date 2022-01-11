/*
 * engine_temp.c
 *
 *  Created on: Jan 8, 2022
 *      Author: Mina
 */
#include<stdio.h>
#include<stdlib.h>
#include"engine_temp.h"

static void ENGINE_tempFn();

static void (*g_engine_temp_clbk)(void)=ENGINE_tempFn;

engineTempType* ENGINE_temp(void)
{
	engineTempType* engine_temp= calloc(1, sizeof(engineTempType));

	engine_temp= (engineTempType*) optionConstructor(	(optionType*) engine_temp,
														(char*)"Set the engine temperature (Engine Temperature Sensor)",
														g_engine_temp_clbk);
	return engine_temp;
}

void ENGINE_tempSetClbk(void (*a_engine_temp_clbk)(void))
{
	g_engine_temp_clbk = a_engine_temp_clbk;
}
static void ENGINE_tempFn()
{
	printf("ENGINE TEMP\n");
	fflush(stdout);
}
