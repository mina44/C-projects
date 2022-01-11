/*
 * options_menu.c
 *
 *  Created on: Jan 7, 2022
 *      Author: Mina
 */

#include<stdio.h>
#include<stdlib.h>

#include"options_menu.h"


/*Add to the end*/

void MENU_add(optionType* a_option, optionType** r_head, optionType** r_tail)
{
	if( NULL == *r_head ){
		*r_head = a_option;
		*r_tail = a_option;
	}

	else{
		(*r_tail)->next= a_option;
		*r_tail= a_option;
	}

}

char MENU_select(optionType* a_head)
{
	char	choice= 0,
			count =	0,
			flag  = 0;

	do{


		printf("\nPlease select one of the following:\n");

		while(a_head != NULL){

			printf("%c. ",(char)97+count); // 97 is the dec value for 'a'

			a_head->optionBrief(a_head);

			a_head=a_head->next;
			count++;
		}

		fflush(stdout); // for eclipse to print

		scanf(" %c",&choice);

		if(!((choice-97)>=0 && (choice-97)<=count)){
			flag= 1;
		}
		else{
			flag= 0;
		}

	}while(1==flag);

	return (choice - 97);
}

void MENU_execute(char a_choice,optionType* a_head)
{
	optionType* a_ptr=a_head;

	char count=0;

	for(;count<a_choice;count++){
		a_ptr= a_ptr->next;
	}

	a_ptr->function();
}
