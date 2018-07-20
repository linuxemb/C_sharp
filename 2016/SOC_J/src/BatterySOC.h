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
#define colsSocTable	5
#define colsRangeTable  4
#define stepV    (uint16_t)100
#define stepT    (index_t)1

typedef uint16_t  Vcell_t;
typedef int8_t   temperature_t;
typedef uint8_t  soc_t;
typedef uint8_t  index_t;


extern uint16_t TableSocVirtual[];
extern int16_t TrangeTbl[]; 

int16_t interpolate(int16_t key, int16_t horizenLow, int16_t y2, int16_t x1, int16_t x2);
void  buildVirtualTable(temperature_t temperature, int16_t rangeTbl[], index_t idxT, uint16_t Tn_Tbl[], index_t lenVirtualTbl);
index_t getIndex(int16_t key, int16_t tbl[], index_t lenTbl);
soc_t getSOC(Vcell_t Vcell, temperature_t Tamb, soc_t curSoc);