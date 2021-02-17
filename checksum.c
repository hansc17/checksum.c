/********************************/
/* Program Name: checksum.c     */
/* Author: Hans Cabatu          */
/* Date: 02/16/21               */
/********************************/
/* Description:                 */
/* Validation Checks:           */
/* Enhancements:                */
/********************************/

#include "stdio.h"
#include "stdlib.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

#define max_int (255)
#define byte unsigned char

int main (int argc, char * argv[], char ** envp) {

  int count = 10;
  int sum = 0;   
  byte checksum; 
  byte complement;
  int quotient;
  int remainder;
  byte buffer[10];

 read(STDIN_FILENO, &buffer, 10); 
 
         for(int c = 1; c < count; c++) {
               printf("%d ", buffer[c]);
               printf("\n");
         }
   
         for(int c = 1; c < count; c++) {
               if (c == 6) {
                  checksum = buffer[c];
                  buffer[c] = 0;
               }
            sum += buffer[c];
       }
       
   quotient = sum / (max_int + 1);
    remainder = sum%(max_int + 1);
    
    sum = quotient + remainder;
    
    complement = max_int - sum;
  
  fprintf(stdout, "Stored Checksum: %d, Computed Checksum: %d\n", checksum, complement);
  if (checksum != complement ) {
    fprintf(stderr, "Error Detected!\n"); 
    return 1;
  }
  return 0;
}