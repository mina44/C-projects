// Hello Again !

/*
Created Date: 06 - 01 - 2022
Created by	: Mina Atef
Brief		: Vehicle Control System
*/

#include<stdio.h>

#include "main_menu.h"
#include "sensor_menu.h"

int main()
{
	MAIN_menuInit();
	SENSOR_menuInit();

	MAIN_menuSelect();

	return 0;

}



