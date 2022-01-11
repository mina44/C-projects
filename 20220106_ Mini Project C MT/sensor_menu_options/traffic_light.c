/*
 * traffic_light.c
 *
 *  Created on: Jan 8, 2022
 *      Author: Mina
 */

#include<stdio.h>
#include<stdlib.h>
#include"traffic_light.h"

static void TRAFFIC_lightFn(void);



static void (*g_traffic_clbk)(void)=TRAFFIC_lightFn;

trafficType* TRAFFIC_light(void)
{
	trafficType* traffic_light= calloc( 1, sizeof(trafficType) );

	traffic_light= (trafficType*) optionConstructor((optionType*)traffic_light,
													(char*)"Set the traffic light color",
													g_traffic_clbk );

	return traffic_light;
}

void TRAFFIC_lightSetClbk(void (*a_traffic_clbk)(void))
{
	g_traffic_clbk= a_traffic_clbk;
}


static void TRAFFIC_lightFn(void)
{
	printf("TRAFFIC LIGHT");
}
