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


#define rowsSocTable    21
#define colsSocTable	    5
#define colsRangeTable   4
#define stepV    (uint16_t)100
#define stepT    (uint8_t)1

typedef uint16_t VcellType;
typedef int8_t   temperatureType;
typedef uint8_t  socType;


extern uint16_t TableSocVirtual[];
extern int16_t TrangeTbl[]; 

int16_t interpolate(int16_t key, int16_t y1, int16_t y2, int16_t x1, int16_t x2);
void  buildVirtualTable(temperatureType temperature, int16_t rangeTbl[], uint8_t idxT, uint16_t *virtualTbl, uint8_t lenVirtualTbl);

uint16_t getIndex(int16_t key, int16_t *tbl, uint16_t lenTbl);
socType getSOC(VcellType Vcell, temperatureType Tamb, socType curSoc);