#pragma once
/*******************************************************************************
*
* Copyright (c) 2016 Revision Military Incorporated. All Rights Reserved.
*
* This software is protected by copyright law and international treaties.
* The use, copying, modification, and distribution of this software and
* its documentation, in any form, is strictly prohibited, except with the
* express written permission or licence of Revision Military Incorporated.
* Failure to abide by the terms of this Notice may result in severe
* criminal and civil liabilities.
*
* THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED
* WARRANTY. IN PARTICULAR, REVISION MILITARY INCORPORATED MAKES NO
* REPRESENTATION OR WARRANTY OF ANY KIND CONCERNING THE MERCHANTABILITY
* OF THIS SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR PURPOSE.
*
******************************************************************************/


/*******************************************************************************
*
*  FILENAME:     BatterySOC.h
*
*  DESCRIPTION:  The target-specific data sizes
*
*
*  $Rev$
*  $Date$
*  $Author$
*  $HeadURL$
*
*
******************************************************************************/
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




