#include <stdint.h>
#include "BatterySOC.h"

#include <stdbool.h>
#include <stdio.h> // suppor fprintf


extern int16_t TableSOC[rowsSocTable][colsSocTable];


#define rowsSocTable 21
uint16_t TableSocVirtual[rowsSocTable];



int16_t TrangeTbl[colsRangeTable] = { -40, -18, 25, 55 };





socType getSOC( VcellType Vcell, temperatureType Tn, socType curSoc)
{
	uint8_t idxT, idxV;
	uint8_t soc = curSoc;
	
	
	int tep = TrangeTbl[0];

	idxT = getIndex(Tn, TrangeTbl, colsRangeTable );
	if (idxT) {

		uint16_t test = TableSOC[0][0];
		uint16_t test1 = TableSOC[0][1];

		buildVirtualTable(Tn, TrangeTbl, idxT, &TableSocVirtual[0], rowsSocTable);
		idxV = getIndex(Vcell, &TableSocVirtual[0], rowsSocTable);
	 	
		if (idxV) {
			soc = interpolate(Vcell, TableSocVirtual[idxV - 1], TableSocVirtual[idxV], TableSOC[idxV - 1][0], TableSOC[idxV][0]);
		}
	}
	return(soc);
}

void  buildVirtualTable(int16_t Tn, int16_t range_tbl[], uint8_t I_T2, uint16_t *Tn_Tbl, uint8_t l_tbl)
{
	int y1, y2, x1, x2, i;

	for (i = 0; i<l_tbl; i++) {
		y1 = range_tbl[I_T2 - 1];
		y2 = range_tbl[I_T2];
		x1 = TableSOC[i][I_T2 ];
		x2 = TableSOC[i][I_T2+1];
		Tn_Tbl[i] = interpolate(Tn, y1, y2, x1, x2);
	}
}

int16_t interpolate(int16_t p_new, int16_t y1, int16_t y2, int16_t x1, int16_t x2)
{
	float m, y_num, y_denom, x_delta, val;
	int16_t retval;
	y_num = (p_new - y1);
	y_denom = (y2 - y1);
	m = y_num / y_denom;
	x_delta = x2 - x1;
	val = m * x_delta;
	retval = (int16_t)val + x1;

	return(retval);
}



uint16_t getIndex(int16_t p1, int16_t tbl[], uint16_t l_tbl)
{
	uint16_t retval = 0;
	uint8_t i;
	int tep = tbl[0];

	if ((p1 >= tbl[0]) && (p1 <= tbl[l_tbl - 1])) {
		for ( i = 1; i<l_tbl; i++) {
			if (p1 <= tbl[i]) {
				retval = i;
				break;
			}
		}
	}
	return(retval);
}
//============================================================



