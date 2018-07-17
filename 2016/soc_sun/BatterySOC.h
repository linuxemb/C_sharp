#pragma once

#ifndef __INCLUDE_types_
#define __INCLUDE_types_
#endif

#include <math.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "BatteryUser.h"

#define DIM(a)                        sizeof (a) / sizeof (*(a))
#define cellVColWork (uint8_t)2


typedef struct
{
	
	uint8_t percent;                      // Approximate fullness indicator
	uint16_t voltage[cellVColWork];                   // Cell voltage

} cellCapacity;

 
typedef struct
{
	uint8_t persent;
	uint16_t  voltage[newChemCols];
} cellCapacityNewChem;

extern uint8_t temperatureArray[];
extern cellCapacityNewChem  table_vtSOCNewChem[];
extern cellCapacity    table_vtSOC[];
extern cellCapacity table_vSOC[];
extern uint8_t  tableSizeSOC ; 


uint8_t getSOC(uint16_t cellV,  int8_t ambT, uint8_t soc); 




