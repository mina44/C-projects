/*
 * main_menue.c
 *
 *  Created on: Jan 7, 2022
 *      Author: Mina
 */
#include<stdio.h>

#include"includes/options_menu.h"

#include "main_menu_options/engine_off.h"
#include "main_menu_options/engine_on.h"
#include "main_menu_options/quit.h"

#include "sensor_menu.h"

static void ENGINE_offFn(void);
static void ENGINE_onFn(void);
static void QUIT_fn(void);

static optionType* 		g_head = NULL;
static optionType* 		g_tail=NULL;
static unsigned char	g_flag=1;

void MAIN_menuInit(void)
{
	ENGINE_onSetClbk(ENGINE_onFn);
	ENGINE_offSetClbk(ENGINE_offFn);
	QUIT_setClbk(QUIT_fn);

	MENU_add((optionType*)ENGINE_on(),&g_head,&g_tail);
	MENU_add((optionType*)ENGINE_off(),&g_head,&g_tail);
	MENU_add((optionType*)QUIT(),&g_head,&g_tail);

}


void MAIN_menuSelect(void)
{

	g_flag= 1;
	do{
		MENU_execute(MENU_select(g_head),g_head);
	}while(1==g_flag);

}

static void ENGINE_offFn(void)
{
	printf("ENGINE OFF\n");
}

static void ENGINE_onFn(void)
{
	printf("ENGINE ON\n");
	printf("************* SENSOR MENU *************\n");

	fflush(stdout);
	SENSOR_menuSelect();
}

static void QUIT_fn(void)
{
	g_flag=0;
}
