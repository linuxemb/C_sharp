#include <stdint.h>
#include "BatterySOC.h"

#include <stdbool.h>
#include <stdio.h> // suppor fprintf


extern int16_t TableSOC[rowsSocTable][colsSocTable];


#define rowsSocTable 21
uint16_t TableSocVirtual[rowsSocTable];
int16_t TrangeTbl[colsRangeTable] = { -40, -18, 25, 55 };

soc_t getSOC( Vcell_t Vcell, temperature_t Tn, soc_t curSoc)
{
	index_t idxT, idxV;
	index_t soc = curSoc;
	
	
	int tep = TrangeTbl[0];

	idxT = getIndex(Tn, TrangeTbl, colsRangeTable );
	if (idxT) {

		uint16_t test = TableSOC[0][0];
		uint16_t test1 = TableSOC[0][1];

		buildVirtualTable(Tn, TrangeTbl, idxT, &TableSocVirtual[0], rowsSocTable);
		//idxV = getIndex(Vcell, &TableSocVirtual[0], rowsSocTable);
		idxV = getIndex(Vcell, TableSocVirtual, rowsSocTable);
	 	
		if (idxV) {
			soc = interpolate(Vcell, TableSocVirtual[idxV - 1], TableSocVirtual[idxV], TableSOC[idxV - 1][0], TableSOC[idxV][0]);
		}
	}
	return(soc);
}


void  buildVirtualTable(temperature_t Tamb, temperature_t rangeTbl[], index_t indexT, Vcell_t virtualSocTbl[], index_t lenVirtualTbl)
{
	temperature_t tLow, tHigh;
	Vcell_t   vLow, vHigh;
	index_t i;
	for (i = 0; i<lenVirtualTbl; i++) {
		vLow = rangeTbl[indexT - 1];  // temperatrue
		vHigh = rangeTbl[indexT];      
		tLow = TableSOC[i][indexT ];  //
		tHigh = TableSOC[i][indexT+1];
		virtualSocTbl[i] = interpolate(Tamb, vLow, vHigh, tLow, tHigh);
	}
}

int16_t interpolate(int16_t key, int16_t y1, int16_t y2, int16_t x1, int16_t x2)
{
	float m, y_num, y_denom, x_delta, val;
	int16_t retval;
	y_num = (key - y1);
	y_denom = (y2 - y1);
	m = y_num / y_denom;
	x_delta = x2 - x1;
	val = m * x_delta;
	retval = (int16_t)val + x1;

	return(retval);
}



index_t getIndex(int16_t key, int16_t tbl[], index_t lenTbl)
{
	uint16_t retval = 0;
	index_t i;
	int tep = tbl[0];

	if ((key >= tbl[0]) && (key <= tbl[lenTbl - 1])) {
		for ( i = 1; i<lenTbl; i++) {
			if (key <= tbl[i]) {
				retval = i;
				break;
			}
		}
	}
	return(retval);
}




