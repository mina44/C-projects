#include "option.h"
#include <stdio.h>


optionType* optionConstructor(optionType* a_option, char* a_brief, void (*a_function)(void))
{
	a_option->brief			= a_brief;
	a_option->optionBrief	= optionBrief;
	a_option->function		= a_function;
	a_option->next			= NULL;

	return a_option;
}


void optionBrief(optionType* a_option)
{
	printf("%s\n", a_option->brief);
}
