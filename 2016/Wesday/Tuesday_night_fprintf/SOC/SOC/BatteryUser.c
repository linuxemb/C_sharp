#pragma once



/*******************************************************************************
*
*  FILENAME:     batteryUser.c*
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

#include <stdint.h>
#include <stdbool.h>
#include "BatteryUser.h"

//const int8_t temperatureArray[newChemCols] =  { 55, 25, -18, -40 };
const int8_t temperatureArray[newChemCols] = { 55, 45, 35, 25 };
//#define DIM(a)                        sizeof (a) / sizeof (*(a))

typedef struct
{
	float percent;                      // Approximate fullness indicator
	uint16_t voltage[2];             // Cell voltage

} cellCapacity;


typedef struct
{	
	uint8_t percent;
	uint16_t voltage[newChemCols];
} cellCapacityNewChem;

//
//extern const cellCapacityNewChem table_vtSOCNewChem[] = 
//// SOC 	 55C  	25C  - 18C   - 40C
//{
//{ 0,    2500,	 3300,   3380,	3456 },
//{ 5,	2557,	3357,	3407,	3457 },
//{ 10,	3267,	3412,	3446,	3458 },
//{ 15,	3405,	3438,	3479,	3460 },
//{ 20,	3431,	3481,	3509,	3462 },
//{ 25,	3473,	3518,	3533,	3462 },
//{ 30,	3512,	3547,	3554,	3462 },
//{ 35,	3542,	3574,	3572,	3477 },
//{ 40,	3571,	3593,	3588,	3502 },
//{ 45,	3602,	3608,	3604,	3523 },
//{ 50,	3618,	3622,	3619,	3545 },
//{ 55,	3633,	3639,	3637,	3566 },
//{ 60,	3651,	3658,	3661,	3588 },
//{ 65,	3675,	3684,	3691,	3614 },
//{ 70,	3705,	3719,	3728,	3644 },
//{ 75,	3753,	3777,	3772,	3679 },
//{ 80,	3812,	3825,	3821,	3720 },
//{ 85,	3859,	3868,	3869,	3767 },
//{ 90,	3906,	3913,	3912,	3818 },
//{ 95,	3952,	3960,	3956,	3871 },
//{ 100,	3999,	4020,	3904,	3933 },
//};



extern const cellCapacityNewChem table_vtSOCNewChem[] =
// SOC 	 55C  	45C   35C    25C
{
{ 0,    1000,	 1100,  1200,	1300 },
{ 20,	1500,	 1600,	1700,	1800 },
{ 40,	2000 ,	 2100,	2200,	2300 },
{ 60,	2500,	 2600,	2700,	2800 },
{ 80,	3000,	 3100,	3200,	3300 },
{ 100,	3500,	3600,	3700,	3800 },
};

// table_vSOC is the working data to retrieve the SOC value from the Open circuit Voltage,
// and it is generated from User data table_vtSOCNewChem

 cellCapacity table_vSOC[newChemRows] ;

  cellCapacity table_vtSOC[newChemRows];

uint8_t tableSizeSOC = newChemRows;
// Used to retrieve the best temperature segments for interpolation 
uint8_t getIndexT(int8_t temperature);
// Helper function to decide which is the convergence poit, from left or right point of segment
bool  smartStartGetter(uint8_t indexT,   int8_t temperature);

uint16_t bufferArray[newChemCols];
