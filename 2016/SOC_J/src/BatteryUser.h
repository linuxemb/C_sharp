// BatteryUser.h
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
*  FILENAME:     BatteryUser.h
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


//#define Tmin (int8_t)(-40) 
//#define Tmax (int8_t)55
#define Tmin (int8_t)(25) 
#define Tmax (int8_t)55
//#define Tmin (int8_t)(-50) 
//#define Tmax (int8_t)90


//#define cellVmin (uint16_t)2200
//#define cellVmax (uint16_t)5000

#define SOChigh (uint8_t)(90)
#define SOClow   (uint8_t)(10)
#define cellVmin (uint16_t)2200
#define cellVmax (uint16_t)4300
//#define cellVmin (uint16_t)1000
//#define cellVmax (uint16_t)4000

#define cellVTblMax (uint16_t)1000
#define cellVTblMin  (uint16_t)4000

#define newChemCols (uint8_t)4
//#define stepSOC  (uint8_t)5
#define stepSOC  (uint8_t)20
//#define deltaIdxSOC (uint8_t)2  // Where 90%, 10% located in i+2 or sizeof(Array) -2
//#define newChemRows (uint8_t)21
#define newChemRows (uint8_t)6






