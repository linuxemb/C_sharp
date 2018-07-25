//main.c

#ifndef __INCLUDE_types_
#define __INCLUDE_types_
#endif
#include <stdint.h>
#include "BatterySOC.h"
#include <stdio.h>



index_t str[100];
//extern void prepare();
	  index_t soc = 0;
	 // Create test cases for temperature between Min to Max at range of Cell voltage
     // between VcellMax and VcellMin 
     int8_t temperature = Tmin ; 
      uint16_t cellV = cellVmin; 
	  index_t ret; // 
      
      
      index_t rowV = 200;
      index_t rowT = 200;
      index_t countV = 0;
      index_t countT = 0;

	  int main(int argc, char **argv)

{
		  index_t retsoc = getSOC(35, 3525, 0);
		  printf(" %d \n", retsoc);
		  
		  FILE *fp;
		  fp = fopen("soc.csv", "w+c");

		  if (fp == NULL)
		  {
			  printf("\n fail to open file");
			  return 1;
		  }

		  		     
 //  fprintf(fp, "retsoc=====%d,\n", retsoc);  // for place holder
 //  fclose(fp); // or for the paranoid: if (fclose (fout) == eof) rc = 0;
 //  int data;
 //  scanf("%d", &data);
 //     
 //  return ret;
 //}

    // 
   
      fprintf(fp, "%d,", 9999);  // for place holder
	
       
      for( index_t idx =  0;  idx < 200 ; idx ++)
         {
             uint16_t rowOne = idx * stepV + cellVmin;
               if  (( rowOne  >= (uint16_t)cellVmin)  && (rowOne  <= (uint16_t)cellVmax))
               {                  
				   countV++;
                    fprintf(fp, "%d,", rowOne);
               }
         }
          
        // GET SOC
        for ( index_t j = 0; j < rowT ; j++)      
            { 
            printf("in top level For \n");
            printf("temp = %d, \n", temperature);
            
          //  fprintf(fp," @Temperature of %d \n", temperature); 
            fprintf(fp,"\n %d, ", temperature);
            
            cellV = cellVmin;  // reset cellVmin for next iteration
            
              if ((temperature < (int8_t)(Tmin)) || (temperature > (int8_t)(Tmax) ))  // done  
           {
        printf ( "out of temperature range \n");
         return 0;
         }
			  temperature = j == 0 ? temperature :  temperature + stepT;
                // do once at least for start temperature point
                                            
                   for (index_t i = 0 ; i < rowV; i ++)
               {
                if  ((cellV < (uint16_t)cellVmin)  || (cellV > (uint16_t)cellVmax))
                       {
                      break;
                    }  
                    ret = getSOC(cellV,temperature, soc);              
                 
                  fprintf(fp,"%03d, ", ret);                 
                  cellV = cellV + stepV ;
                }                                                            
            }   
                          
            fclose(fp);
             return 0;   
    } 
            
           
        
		