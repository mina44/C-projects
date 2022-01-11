/*
 * sensor_set_menu.c
 *
 *  Created on: Jan 8, 2022
 *      Author: Mina
 */

/*===================== Files Inclusion ====================*/
#include<stdio.h>

#include"includes/options_menu.h"
#include"main_menu.h"

/************************ Options **************************/
#include"sensor_menu_options/engine_off.h"
#include"sensor_menu_options/traffic_light.h"
#include"sensor_menu_options/room_temp.h"
#include"sensor_menu_options/engine_temp.h"
/***********************************************************/

#include"sensor_menu.h"
/*==========================================================*/

#if	1
#define WITH_ENGINE_TEMP_CONTROLLER
#endif


typedef struct STATE_MENU{
	stateType ENGINE_STATE;
#ifdef WITH_ENGINE_TEMP_CONTROLLER
	stateType ENGINE_TEMP_CTRL;
#endif
	stateType AC;

	unsigned char VEHICLE_SPEED;
	short ROOM_TEMP;
	short ENGINE_TEMP;
}stateMenuType;


/*=================== Private Prototypes ===================*/

/*********************** Options APIs ***********************/
static void S_ENGINE_offFn(void);
static void TRAFFIC_lightFn(void);
static void ROOM_tempFn(void);
static void ENGINE_tempFn(void);
/************************* APP APIs *************************/
static void SENSOR_STATE(void);
static void SENSOR_MENU_exit(void);

/*==========================================================*/



/********************* Private Objects *********************/
static optionType* 		g_head = NULL;
static optionType* 		g_tail=NULL;
static unsigned char 	g_flag=1;
/***********************************************************/

stateMenuType g_state_menu = {	OFF,				// ENGINE_STATE
#ifdef WITH_ENGINE_TEMP_CONTROLLER
								OFF,				// ENGINE_TEMP_CTRL
#endif
								OFF,				// AC
								(unsigned char)0,	// VEHICLE_SPEED
								(short)25,			// ROOM_TEMP
								(short)28};			// ENGINE_TEMP
/********************* Sensor Menu APIs *********************/
void SENSOR_menuInit(void)
{
	S_ENGINE_offSetClbk(S_ENGINE_offFn);
	TRAFFIC_lightSetClbk(TRAFFIC_lightFn);
	ROOM_tempSetClbk(ROOM_tempFn);
	ENGINE_tempSetClbk(ENGINE_tempFn);


	MENU_add((optionType*)S_ENGINE_off(),&g_head,&g_tail);
	MENU_add((optionType*)TRAFFIC_light(),&g_head,&g_tail);
	MENU_add((optionType*)ROOM_temp(),&g_head,&g_tail);
	MENU_add((optionType*)ENGINE_temp(),&g_head,&g_tail);
}

void SENSOR_menuSelect(void)
{
	g_flag = 1;

	do{
		MENU_execute(MENU_select(g_head),g_head);

		if(30 == g_state_menu.VEHICLE_SPEED){
			g_state_menu.AC = (stateType) ON;
			g_state_menu.ROOM_TEMP = (short) ((float)g_state_menu.ROOM_TEMP * (5.0/4.0) + 1);
#ifdef WITH_ENGINE_TEMP_CONTROLLER
			g_state_menu.ENGINE_TEMP_CTRL = (stateType) ON;
#endif
			g_state_menu.ENGINE_TEMP = (short) ((float)g_state_menu.ENGINE_TEMP * (5.0/4.0) + 1);
		}

		SENSOR_STATE();
	}while(1==g_flag);
}

static void SENSOR_STATE(void)
{
	/*Engine State*/
	if(g_state_menu.ENGINE_STATE == (stateType)ON)
		printf("\ni.\tEngine state: ON\n");
	else
		printf("\ni.\tEngine state: OFF\n");

	/*AC state*/
	if(g_state_menu.AC == (stateType)ON)
			printf("ii.\tAC state: ON\n");
		else
			printf("ii.\tAC state: OFF\n");

	/*Vehicle Speed*/
	printf("iii.\tVehicle Speed: %d\n",g_state_menu.VEHICLE_SPEED);

	/*Room Temperature*/
	printf("iv.\tRoom Temperature: %d\n",g_state_menu.ROOM_TEMP);

#ifdef WITH_ENGINE_TEMP_CONTROLLER
	/*Engine Temperature Controller State*/
	if(g_state_menu.ENGINE_TEMP_CTRL == (stateType)ON)
				printf("v.\tEngine Temperature Controller State: ON\n");
			else
				printf("v.\tEngine Temperature Controller State: OFF\n");
#endif

	/*Engine Temperature*/
	printf("vi.\tEngine Temperature: %d\n",g_state_menu.ENGINE_TEMP);

}
/************************************************************/



/*********************** Options APIs ***********************/
static void S_ENGINE_offFn(void)
{
	printf("ENGINE OFF\n");
	fflush(stdout);

	SENSOR_MENU_exit(); // EXIT SENSOR MENU
}

static void TRAFFIC_lightFn(void)
{
	char 	light,
			flag=0;


	do{
		scanf(" %c",&light);

		if		('g'==light || 'G'==light){
			g_state_menu.VEHICLE_SPEED= 100;
			flag=0;
		}
		else if	('o'==light || 'O'==light){
			g_state_menu.VEHICLE_SPEED= 30;
			flag=0;
		}
		else if	('r'==light || 'R'==light) {
			g_state_menu.VEHICLE_SPEED= 0;
			flag=0;
		}
		else {
			flag=1;
		}
	}while(1==flag);

}

static void ROOM_tempFn(void)
{
	short 	temp=0;

	scanf("%hi",&temp);

	if(temp < 10 || temp > 30){
		g_state_menu.AC =(stateType)ON;
		g_state_menu.ROOM_TEMP=20;
	}
	else{
		g_state_menu.AC = (stateType)OFF;
	}

}

static void ENGINE_tempFn(void)
{
	short 	temp=0;

	scanf("%hi",&temp);

	if(temp < 100 || temp > 150){
#ifdef WITH_ENGINE_TEMP_CONTROLLER
		g_state_menu.ENGINE_TEMP_CTRL = (stateType) ON;
#endif
		g_state_menu.ENGINE_TEMP=125;
	}
	else{
#ifdef WITH_ENGINE_TEMP_CONTROLLER
		g_state_menu.ENGINE_TEMP_CTRL = (stateType)OFF;
#endif
	}
}

/************************* APP APIs *************************/
static void SENSOR_MENU_exit(void)
{
	g_flag= 0; // Exit sensor menu
}
/************************************************************/
