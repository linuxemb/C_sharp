// BatteryUser.h
#pragma once

#ifndef __INCLUDE_types_
#define __INCLUDE_types_
#endif


#define Tmin (int8_t)(-40) 
#define Tmax (int8_t)55

//#define Tmin (int8_t)(-50) 
//#define Tmax (int8_t)90


//#define cellVmin (uint16_t)2200
//#define cellVmax (uint16_t)5000

#define SOChigh (uint8_t)(90)
#define SOClow   (uint8_t)(10)
#define cellVmin (uint16_t)2200
#define cellVmax (uint16_t)4300

#define cellVTblMax (uint16_t)4020
#define cellVTblMin  (uint16_t)2500

#define newChemCols (uint8_t)4
#define stepSOC  (uint8_t)5
#define deltaIdxSOC (uint8_t)2  // Where 90%, 10% located in i+2 or sizeof(Array) -2
#define newChemRows (uint8_t)20







