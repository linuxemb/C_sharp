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
uint16_t bufferArray[newChemCols];

FILE *fpsoc;
// Check if the current temperature belong to lucky test points

bool inTemperatureArray( int8_t temperature , int8_t array[])
{
    for ( uint8_t i=0 ; i< newChemCols; i++)
    {
        if (temperature == array[i])
        {
            return true;
        }
    }
    
    return false;
    
}

int8_t *  SortTemperature(int8_t arrayT[])
{
    int8_t a[newChemCols];
    // assign array 
    for (uint8_t idx =0; idx <newChemCols; idx++)
    {
        a[idx] = arrayT[idx];
    }
   
   
    uint8_t n = newChemCols;    
    for (int i = 0; i < n; i++)                     //Loop for ascending ordering
	{
		for (int j = 0; j < n; j++)             //Loop for comparing other values
		{
			if (a[j] > a[i])                //Comparing other array elements
			{
				int tmp = a[i];         //Using temporary variable for storing last value
				a[i] = a[j];            //replacing value
				a[j] = tmp;             //storing last value
			}  
		}
	}
	printf("\n\nAscending : ");                     //Printing message
	for (int i = 0; i < n; i++)                     //Loop for printing array data after sorting
	{
		printf(" %d ", a[i]);
	}
    return a;
}

uint16_t  getMinForAllCellV(uint16_t array[])
{  
    int16_t minCellV ;
    uint16_t size, c, location=1;
        
  // Sort bufferArray 
    minCellV = array[0];
    
   for (c = 0; c < newChemCols; c++)
  {
    if (array[c] < minCellV)
    {
       minCellV  = array[c];
       location = c+1;
    }
  }
  
   printf("Min element is present at location %d and it's value is %d.\n", location, minCellV);
   //minCellVForAll = minCellV;
  return array[location -1 ];
}




uint16_t  getMaxForAllCellV(uint16_t array[])

{   
    int16_t maxCellV ;
    uint16_t size, c, location=1;
     
   
  // Sort bufferArray 
    maxCellV = array[0];
    
   for (c = 1; c < newChemCols; c++)
  {
    if (array[c] > maxCellV)
    {
       maxCellV  = array[c];
       location = c+1;
    }
  }
     
   printf("Max element is present at location %d and it's value is %d.\n", location, maxCellV);
  return array[location -1];
}


uint8_t getIndexT(int8_t temperature)
{  
	int8_t T = temperature;
	uint8_t i = 0;
	// Some input-range checking: 
	if (T > Tmax)
	{
		T = Tmax;
	}

	if (T < Tmin)
	{
		T = Tmin;
	}
	
	while ( (T  <   temperatureArray[i])  && (i < 3) ) 
	{
   	i++;
	}
    // boundery protection
   printf("index T = %d", i-1);
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
/*

extern void prepareSOC() 
{
       uint8_t total = newChemCols * newChemRows;
       
       uint16_t minCellV[newChemCols];   // total 4 items  contain Min Cell V for each col 
        uint16_t maxCellV[newChemCols];   // total 4 items  contain Min Cell V for each col 
    //  uint16_t buffer[80];
       uint16_t buffer[total];
       // uint16_t buffer[newChemCols*newChemRows];
    for (uint8_t j = 0; j < newChemCols; j++ )
       
   {
       for (uint8_t i =0 ;i <= newChemRows; i++)
        {
            buffer[i + j* newChemRows]  = table_vtSOCNewChem[i].voltage[j];
         }
                  
   }        
   
   
    for (int t=0; t< newChemRows; t++)
        {
          printf (" %d,", buffer[t]);          
        }
        printf ("\n");
        for (int t=newChemRows; t< 2* newChemRows; t++)
        {
          printf (" 2nd one %d,", buffer[t]);
          
        }
         printf ("\n");
         for (int t = 2*newChemRows; t< 3*newChemRows; t++)
        {
          printf (" 3nd one %d,", buffer[t]);          
        }
         printf ("\n");
           for (int t= 3* newChemRows; t< 4* newChemRows; t++)
        {
          printf (" 4th one %d,", buffer[t]);          
        }
         printf ("\n");
        
        printf ("buffer= dim %d\n", DIM(buffer));
     
      
      // Generate candidate arrary for min cellVoltage
      
      for ( uint8_t c = 0; c < newChemCols; c++)
          
      {
         // uint tmp = c *20;
          
          uint tmp = c *newChemRows;
          candidatesVmin[c] = buffer[tmp];
          printf ("buffer[tmp] = %d,candidateVmin = %d,\n",tmp , candidatesVmin[c]);
      }    
     
      
        minCellVForAll =  getMinForAllCellV(candidatesVmin);
        printf (" MIN= %d,\n", minCellVForAll );
            
      // Generate candidate arrary for max cellVoltage
       
     for ( uint8_t c = 0; c < newChemCols; c++)
          
      {
          uint tmp = c * newChemRows -1;
          candidatesVmax[c] = buffer[tmp+ newChemRows];
          printf ("buffer[tmp] = %d,candidateVmax,ax = %d,\n",c*newChemRows , candidatesVmax[c]);
      }    
       
     
      maxCellVForAll =  getMaxForAllCellV(candidatesVmax);
       printf (" Max= %d,\n", maxCellVForAll );
        printf( "maxCellval%d,=================", maxCellVForAll);  // for place holder
      printf( "maxCellval%d,=================", minCellVForAll);  // for place holder
    // Get maxT and minTemp
    //====================================
       
    // assign array 
    for (uint8_t idx =0; idx <newChemCols; idx++)
    {
        a[idx] = temperatureArray[idx];
    }
     
    uint8_t n = newChemCols;    
    for (int i = 0; i < n; i++)                     //Loop for ascending ordering
	{
		for (int j = 0; j < n; j++)             //Loop for comparing other values
		{
			if (a[j] > a[i])                //Comparing other array elements
			{
				int tmp = a[i];         //Using temporary variable for storing last value
				a[i] = a[j];            //replacing value
				a[j] = tmp;             //storing last value
			}  
		}
	}
	printf("\n\nAscending : ");                     //Printing message
	for (int i = 0; i < n; i++)                     //Loop for printing array data after sorting
	{
        printf("/n");
		printf("a[]%d \n", a[i]);
         printf("/n");
	}   
       
}
*/
uint8_t getSOC(uint16_t cellV,  int8_t ambT, uint8_t soc)  
{ 
	extern uint8_t str[100];

	fpsoc = fopen("soc1.csv", "a+");

	if (fpsoc == NULL)
	{
		printf("\n fail to open file");
		return 1;

	}

	printf("amt T =%d \n", ambT);
	//fprintf(fpsoc, "%d,", 9999);  // for place holder


	//for (uint8_t idx = 0; idx < 200; idx++)
	//{
	//	uint16_t rowOne = idx * stepV + cellVmin;
	//	if ((rowOne >= (uint16_t)2500) && (rowOne <= (uint16_t)4300))
	//	{
	//		//strcat(rowOne, "\n");
	//		fprintf(fpsoc, "%d,", rowOne);
	//	}
	//}

	// get current indexT 
		uint8_t indexT = getIndexT(ambT);
		int8_t T = ambT;
		//uint8_t i;
		uint8_t ret;
        uint8_t idxSOC = 0;
        tableSizeSOC = newChemRows;                    
//       if((cellV <  minCellVForAll) || (cellV > maxCellVForAll)    //||  (T < -40) || (T > 55))     
//            
//            || (T < a[0]) || (T > a[newChemCols -1]))
//    
//          {
//              return 0;
//          }    
//           
//        
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
		
        
     // if (!inTemperatureArray(T,temperatureArray))
    //    if (!((T == temperatureArray[0] || (T== temperatureArray[1])  || (T == temperatureArray[2]) || (T==temperatureArray[3]))))
	//	{
		uint16_t delta = 0;
            // nomal temp range copy 2 cols
			for (uint8_t i = 0; i <= tableSizeSOC; i++)
			{
				table_vSOC[i].percent = table_vtSOC[i].percent;     // Use the same percentage numbers
				//Calculate the new voltages by interpolating: 

				if (fromLeft)  // left  + delta
			{

					uint16_t tempV = table_vtSOC[i].voltage[1] - table_vtSOC[i].voltage[0];
					uint16_t deltaT = temperatureArray[indexT] - T;
					// Handle divide by 0 case
					if (deltaT == 0)
					{
						printf(" LUCKy points \n");
						table_vSOC[i].voltage[0] = table_vtSOC[i].voltage[0];
					} 
					else
					{
						int8_t diffT = temperatureArray[indexT + 1] - temperatureArray[indexT];

						delta = (uint16_t)(tempV / deltaT) * abs(diffT);
						printf("tmpv %d,deltaT %d,diffT %d, delta %d\n", tempV, deltaT, diffT, delta);
					//	table_vSOC[i].voltage[0] = table_vtSOC[i].voltage[1] + delta;
						table_vSOC[i].voltage[0] = table_vtSOC[i].voltage[0] + delta;
						printf("delta=%d", delta);
						printf("vtable_vSOC=%d", table_vSOC[i].voltage[0]);
						//table_vSOC[i].voltage[0] = table_vtSOC[i].voltage[0]  + (uint16_t)roundf((((float)(table_vtSOC[i].voltage[1] - table_vtSOC[i].voltage[0])
						//* (temperatureArray[indexT] - T)) / (temperatureArray[indexT + 1] - temperatureArray[indexT])));
					}
			}
				else   // right  -delta
				    {
					
					uint16_t tempV = table_vtSOC[i].voltage[1] - table_vtSOC[i].voltage[0];
					
					uint16_t deltaT = temperatureArray[indexT] - T;
					int8_t diffT = temperatureArray[indexT + 1] - temperatureArray[indexT];
					// Handle divide by 0 case
					if (deltaT == 0)
					{
						printf(" LUCKy points \n");
						table_vSOC[i].voltage[0] = table_vtSOC[i].voltage[1];
					}
					else {
						delta = (uint16_t)(tempV / deltaT) * abs(diffT);
						printf("tmpv  = %d,deltaT= %d,diffT= %d, delta=%d \n", tempV, deltaT, diffT, delta);

						//delta = (uint16_t) (table_vtSOC[i].voltage[1] - table_vtSOC[i].voltage[0] ) * (T - temperatureArray[indexT + 1]) / (temperatureArray[indexT] - temperatureArray[indexT + 1]);
						//delta = (uint16_t)(table_vtSOC[i].voltage[1] - table_vtSOC[i].voltage[0]) * (T - temperatureArray[indexT + 1]) / (temperatureArray[indexT] - temperatureArray[indexT + 1]);
						table_vSOC[i].voltage[0] = table_vtSOC[i].voltage[1] - delta;
					}
					printf("vtable_vSOC=%d", table_vSOC[i].voltage[0]);
				}
			}    
            
       // }// end of normao temp range copy 2 cols
        
			printf("=========================start to look up table===\n");
			// Lucky temperature test point, just copy indexed col to soc_table instead of copy 2 cols to table_vSOC

		/*	for (uint8_t id = 0; id < tableSizeSOC; id++)
			{
				table_vSOC[id].percent = table_vtSOC[id].percent;

				table_vSOC[id].voltage[0] = table_vtSOC[id].voltage[0];
			}*/
		
		// Now we have the Soc Vtable ready for lookup., need do boundery check
        // If Vcell  < 5% soc mapping Vcell or Vcell > 90% SOC' mapping Vcell , 
        // wont do update SOC , just return SOC of Coulom counter's
      
             
             
      
   /*   if(((cellV < table_vSOC[0].voltage[0]))  || ( cellV > table_vSOC[tableSizeSOC -1 ].voltage[0]) )
       {
         
           return soc;    
       }     */   
      
    
		// Find table_vSOC position...in Validated Vcell range 10-90 %
		 while  (cellV >=  table_vSOC[idxSOC].voltage[0] && ( idxSOC < tableSizeSOC ))
		
		{
            idxSOC++;
        }
	   // look up soc in table_V for Vcell
		 printf("idxSOC===%d,\n",   idxSOC);
		 
		 uint8_t tmpidx = idxSOC == 0  ? 0 : (idxSOC - 1 );
		 //ret = (uint8_t)table_vSOC[tmpidx].percent + (uint8_t)(stepSOC * ((cellV - table_vSOC[idxSOC - 1].voltage[0])) / (table_vSOC[idxSOC].voltage[0] - table_vSOC[idxSOC - 1].voltage[0]));
		 //?????					??===================	 
		 
		 //  TO DO Need add smart side to decide from left or right to converge 
		 // ifFromLeft...
		 uint16_t tempVstep = stepSOC *abs((cellV - table_vSOC[idxSOC - 1].voltage[0]));
		 uint16_t deltaV =abs( table_vSOC[idxSOC].voltage[0] - table_vSOC[idxSOC - 1].voltage[0]);
		 float 	 deltasoc = (uint16_t)(tempVstep / deltaV);
		 printf("tmpVstep  = %d,deltaV = %d, delta=%d \n", tempVstep, deltaV,  deltasoc);

		 //if From Right
		 if (cellV < table_vSOC[0].voltage[0])
		 {
			 ret = 0;
		 }
		 else 
			
		 if (cellV  > table_vSOC[newChemRows -1].voltage[0])
		 {
			 ret = 100;
		 }
		 else
		 {
			 ret = (uint8_t)(table_vSOC[tmpidx].percent + deltasoc);
		 }
		
		printf("SOC= %d, @Vcell=%d,   @ T= %d \n", ret, cellV, T);
	//	sprintf(str, "%03d, ", ret);
		fprintf(fpsoc, "%03d, ", ret);
		


		//if (0 != fseek(fpsoc, 11, SEEK_CUR))
		//{
		//	printf("\n fseek() failed\n");
		//	return 1;
		//}

		//printf("\n fseek() successful\n");

		//// if (SIZE*NUMELEM != fwrite(str, SIZE, strlen(str), fp))
		//if (SIZE*NUMELEM != fwrite(str, SIZE, strlen(str), fpsoc))
		//{
		//	printf("\n fwrite() failed\n");
		//	return 1;
		//}
		printf("\n fwrite() successful, data written to text file\n");
		// Wr to file socsoc		// locate 
					
			fclose(fpsoc);
		/*	int a;
			scanf("%s", &a);*/


			return ret;
		
} 
	



