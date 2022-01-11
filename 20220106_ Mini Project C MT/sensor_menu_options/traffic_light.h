/*
 * trafic_light.h
 *
 *  Created on: Jan 8, 2022
 *      Author: Mina
 */

#ifndef SENSOR_MENU_OPTIONS_TRAFFIC_LIGHT_H_
#define SENSOR_MENU_OPTIONS_TRAFFIC_LIGHT_H_

#include"../includes/option.h"
typedef struct TRAFFIC_STRUCT{
	optionType base;
}trafficType;


trafficType* TRAFFIC_light(void);
void TRAFFIC_lightSetClbk(void (*a_traffic_clbk)(void));
#endif /* SENSOR_MENU_OPTIONS_TRAFFIC_LIGHT_H_ */
