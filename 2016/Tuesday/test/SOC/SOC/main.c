//main.c

#ifndef __INCLUDE_types_
#define __INCLUDE_types_
#endif
#include <stdint.h>
#include "BatterySOC.h"
#include <stdio.h>



uint8_t str[100];
//extern void prepare();
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

			/* for ( uint8_t k = 0; k < 10; k++)
			 {
				 fwrite(str,  1, sizeof(str), fp);
				 printf("Saving...\nSaved.");
			 }*/


    //   prepare the row 1 for all temerature ranges
    //        
    //prepare();  //soc1.csv prepare
    //  
 
			 cellV = cellVmin;
   
   int data , rc;
   for (uint8_t i = 0; i < 10; i++)
   {
	   str[i] = getSOC(cellV, 33, 0);
	  
	   cellV = cellV + 200;
	   printf("str[i]= %d, \n", str[i]);
	   /*if (fputs(str, fp) != EOF)
	   {
		   rc = 1;
	   }*/

   }

    

 //  fclose(fp); // or for the paranoid: if (fclose (fout) == eof) rc = 0;
	     
 /*  scanf("%d", &data);
      
   return ret;
       }*/

     
   
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
          
        // GET SOC
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
			  temperature = j == 0 ? temperature :  temperature + stepT;
                // do once at least for start temperature point
                                            
                   for (uint8_t i = 0 ; i < rowV; i ++)
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
            
           
        
		