
#include "../main_menu_options/engine_on.h"

#include<stdlib.h>
#include<stdio.h>

static void ENGINE_onFn(void);
static void (*g_engine_on_clbk)(void)= ENGINE_onFn; //Default functionality for this option

engine_onType* ENGINE_on(void)
{

	engine_onType* engine_on = calloc(1,sizeof(engine_onType));

	engine_on= (engine_onType*) optionConstructor(	(optionType*)engine_on,
													(char*)"Turn on the vehicle engine",
													g_engine_on_clbk);

	return engine_on;
}

static void ENGINE_onFn(void)
{
	printf("ENGINE ON\n");
	fflush(stdout);
}

void ENGINE_onSetClbk(void (*a_engine_on_clbk)(void))
{
	g_engine_on_clbk = a_engine_on_clbk;
}
