


/*******************************************************************************
*
*  FILENAME:     main.c
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
#include "BatterySOC.h"
#include <stdio.h>

#define stepV    (uint16_t)50
#define stepT    (uint8_t)1


	  uint8_t soc = 0;
	 // Create test cases for temperature between Min to Max at range of Cell voltage
     // between VcellMax and VcellMin 
     int8_t temperature = Tmin ; 
      
	  uint16_t cellV = cellVmin; 
	  uint8_t ret; // 
      
      
      uint8_t rowV = 200;
      uint8_t rowT = 200;
      uint8_t countV = 0;
      uint8_t countT = 0;
    int main(int argc, char **argv)
    { 
            printf(" %d \n" ,temperature);
           FILE *fp;          
             fp = fopen("soc.csv", "w+c");
                        
             if(fp == NULL)
            {
             printf ("\n fail to open file");
             return 1;
                
            }
      // prepare the row 1 for all temerature ranges
      
    ret = getSOC(2600, 24,0);
    printf("soc ======== %d \n", ret);

//       return soc;
 //   }
   


      fprintf(fp, "%d,", 9999);  // for place holder
       
      for( uint8_t idx =  0;  idx < 200 ; idx ++)
         {
             uint16_t rowOne = idx * stepV + cellVmin;
               if  (( rowOne  >= (uint16_t)cellVmin)  && (rowOne  <= (uint16_t)cellVmax))
               {                  
                    countV++;
                    fprintf(fp, "%d,", rowOne);
               }
         }
          
        
        for ( uint8_t j = 0; j < rowT ; j++)      
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
                temperature = temperature + stepT;
                // do once at least for start temperature point
                                            
                   for (uint8_t i = 0 ; i < rowV; i ++)
               {
          //      if  ((cellV < (uint16_t)cellVmin)  || (cellV > (uint16_t)cellVmax))
           //             {
            //            break;
              //          }  
                    ret = getSOC(cellV,temperature, soc);
               
               // Add debug information for invalid soc calculation
               
         //      if ((ret < 10 ) || (ret > 90 ))
           //    {
             //   fprintf(fp, " Invalid soc calculation !! \n" );
           //      break;  
            //   }                         
             
         // control output noisy data
         
         
                  fprintf(fp,"%03d, ", ret); 
                
               cellV = cellV + stepV ;
                }                                                            
            }   
                          
            fclose(fp);
             return 0;   
    } 
            
          
        
