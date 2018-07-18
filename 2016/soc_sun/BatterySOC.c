#include <stdint.h>
#include "BatterySOC.h"

#include <stdbool.h>
#include <stdio.h> // suppor fprintf

extern uint8_t getIndexT(int8_t temperature);
extern bool  smartStartGetter(uint8_t indexT,   int8_t temperature);
// table_vSOC is the working data to retrieve the SOC valure from the Open circuit Voltage
extern cellCapacity table_vtSOC[];

extern cellCapacityNewChem table_vtSOCNew[];

extern uint16_t getMinCellV(uint16_t array[]);
extern uint16_t getMaxCellV(uint16_t array[]);

//uint16_t getMinCellV(cellCapacity    tbl_vtSOC[])
uint16_t getMaxCellV( uint16_t  array[])
{
     return array[tableSizeSOC -1];
}


uint16_t getMinCellV( uint16_t array[])
{
//      uint8_t c , location = 1;
     uint16_t  min;
//     min = array[0];
//     for (c = 1; c < tableSizeSOC; c++)
//     {
//         //if (tbl_vtSOC[c].voltage[c] < min)
//               if (array[c] < min)
//         {
//             min = array[c];
//             location = c+1;
//         }
//     }
    min = array[0];
    return  min;
}

uint8_t getIndexT(int8_t temperature)
{  
	int8_t T = temperature;
	int8_t i = 0;
	// Some input-range checking: 
	if (T > Tmax)
	{
		T = Tmax;
	}

	if (T < Tmin)
	{
		T = Tmin;
	}
	
	while ( (T  <  temperatureArray[i])  && (i < 3) ) 
	{
   	i++;
	}
    // boundery protection
  // printf("index T = %d", i-1);
	return (( i > 0 )  ? (i-1) :  0) ;
}

/*********************************************************************
* Function:        smartStartGetter
*
* PreCondition:    None
*
* Input:             - index of Temperatrue in temperatrue array table
*                    - Ambient temperture value
*
* Output:         True if set left side as converge point ,
*				  False if set right right as converge point. 
*
* Side Effects:  none
*
* Overview:        based on delta between Current T and start or end
                   point distance to set the start point 
*
* Note:            None
*
********************************************************************/


bool  smartStartGetter(uint8_t indexT,   int8_t temperature)
{
	int8_t deltaL, deltaR;
	deltaL = temperatureArray[indexT] - temperature;
	deltaR = temperatureArray[indexT + 1] - temperature;
	return ( abs(deltaL)  < abs(deltaR)  ? true : false);  
}



/*********************************************************************
* Function:        getSOC
*
* PreCondition:    None
*
* Input:             - cell-voltage
*                    - Ambient temperture
*					 - Current SOC			
*
* Output:          resynced SOC at current T and cell V if current SOC 
*				   is belong to range between 90%-10%
*
* Side Effects:
*
* Overview:        Calculates the reduced SOC based on current 
*                    cell V and amb T
*
* Note:            None
*
********************************************************************/

uint8_t getSOC(uint16_t cellV,  int8_t ambT, uint8_t soc)  
{ 
    
	// get current indexT 
		uint8_t indexT = getIndexT(ambT);
		int8_t T = ambT;
		uint8_t i;
		uint8_t ret;
        uint8_t idxSOC = 0;
      
        
   
  /*               // Some input-range checking:
 if ((T > Tmax) || (T < Tmin) || (cellV < cellVTblMin) || (cellV > cellVTblMax ))
//  if ((T > (int8_t)55) || (T < (int8_t)(-40)) || (cellV < (uint16_t)2200) || (cellV > (uint16_t)4120))
  {
   return  0;
  }
*/
 /* 
       if(cellV <  2500 || (cellV > 4020) || (T < -40) || (T > 55))
      
   //   if((cellV <  getMinCellV()) || (cellV > getMaxCellV) || (T < Tmin) || (T > Tmax))
         {
             
             return 0;
         }    
   */       
       
        /* 
	if ((soc > SOChigh) || (soc < SOClow) || (ambT > Tmax) || (ambT < Tmin))
	{
        printf("outof range \n");
		return soc;
	}
	*/
		// Generate the Virtual col for current T, using  2 most close temperature sampling point as reference
		for (uint8_t j = 0; j < tableSizeSOC; j++)
		{
			table_vtSOC[j].percent = table_vtSOCNewChem[j].persent;
			table_vtSOC[j].voltage[0] = table_vtSOCNewChem[j].voltage[indexT];
			table_vtSOC[j].voltage[1] = table_vtSOCNewChem[j].voltage[indexT + 1];
		}

		bool fromLeft = smartStartGetter(indexT, T);
		// First, dynamic generation of new table qualified by present temperature: (using simple linear interpolation methods)
		// If Temperature matchs the sample temperature value: table lucky val , 55, 25, -18,-40 directly copy Vcell to V_soc_table, no need to Calculate
		
         if (!((T == temperatureArray[0] || (T== temperatureArray[1])  || (T == temperatureArray[2]) || (T==temperatureArray[3]))))
		{
            
            // nomal temp range copy 2 cols
			for (i = 0; i < tableSizeSOC; i++)
			{
				table_vSOC[i].percent = table_vtSOC[i].percent;     // Use the same percentage numbers
				//Calculate the new voltages by interpolating: 

				if (fromLeft)
				{
					table_vSOC[i].voltage[0] = table_vtSOC[i].voltage[0] - (uint16_t)roundf((((float)(table_vtSOC[i].voltage[1] - table_vtSOC[i].voltage[0])
					* (temperatureArray[indexT] - T)) / (temperatureArray[indexT + 1] - temperatureArray[indexT])));
				}
				else
				{
					table_vSOC[i].voltage[0] = table_vtSOC[i].voltage[1] + (uint16_t)roundf((((float)(table_vtSOC[i].voltage[1] - table_vtSOC[i].voltage[0])
					* (T - temperatureArray[indexT + 1])) / (temperatureArray[indexT + 1] - temperatureArray[indexT])));
				}
			}    
            
        }// end of normao temp range copy 2 cols
        
   
		 // Lucky temperature test point, just copy indexed col to soc_table instead of copy 2 cols to table_vSOC
		
        for (i = 0; i < tableSizeSOC; i++)
			{
                table_vSOC[i].percent = table_vtSOC[i].percent;
                           
                
                table_vSOC[i].voltage[0] = table_vtSOC[i].voltage[0];
			}
		
		// Now we have the Soc Vtable ready for lookup., need do boundery check
        // If Vcell  < 5% soc mapping Vcell or Vcell > 90% SOC' mapping Vcell , 
        // wont do update SOC , just return SOC of Coulom counter's
      
             
             
      
      if(((cellV < table_vSOC[0].voltage[0]))  || ( cellV > table_vSOC[tableSizeSOC - 1].voltage[0]) )
      {
         
         return soc;    
      }        
      
    
		// Find table_vSOC position...in Validated Vcell range 10-90 %
	 while  (cellV >= table_vSOC[0].voltage[0] && ( idxSOC < tableSizeSOC - 1))
		{
            idxSOC++;
        }
	   // look up soc in table_V for Vcell
              
          
          
		ret = (uint8_t)table_vSOC[idxSOC - 1].percent + (uint8_t)(stepSOC * ((cellV - table_vSOC[idxSOC - 1].voltage[0])) / (table_vSOC[idxSOC].voltage[0] - table_vSOC[idxSOC - 1].voltage[0]));             
      printf("soc at %d, is %d \n", T, ret ) ;
        return ret; 
    
} 
	



