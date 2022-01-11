
/*
 * sensor_set_menu.h
 *
 *  Created on: Jan 8, 2022
 *      Author: Mina
 */

#ifndef SENSOR_MENU_H_
#define SENSOR_MENU_H_

typedef enum{
	OFF=0,ON=1
}stateType;


void SENSOR_menuInit(void);
void SENSOR_menuSelect(void);


#endif /* SENSOR_MENU_H_ */
