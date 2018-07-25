// BatteryUser.h
#pragma once

#ifndef __INCLUDE_types_
#define __INCLUDE_types_
#endif


#define Tmin (int8_t)(-40) 
#define Tmax (int8_t)55



#define SOChigh (index_t)(90)
#define SOClow   (index_t)(10)
#define cellVmin (uint16_t)2200
#define cellVmax (uint16_t)4300


#define cellVTblMax (uint16_t)1000
#define cellVTblMin  (uint16_t)4000

#define newChemCols (index_t)4

#define stepSOC  (index_t)20
#define newChemRows (index_t)6






