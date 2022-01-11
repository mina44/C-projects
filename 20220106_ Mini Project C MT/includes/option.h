#ifndef OPTION_H
#define OPTION_H

typedef struct OPTION_STRUCT
{
	char*	brief;
	void (*optionBrief)(struct OPTION_STRUCT*);
	void (*function)(void);
	struct OPTION_STRUCT* next;
}optionType;



optionType* optionConstructor(optionType* a_option, char* a_brief, void (*a_function)(void));

void optionBrief(optionType* a_option);

#endif
