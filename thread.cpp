// -----------------------------------------------------------------
// NAME : Caleb Melnychenko                  User ID: chmelnyc
// DUE DATE : 03/18/2020
// PROGRAM ASSIGNMENT 3
// FILE NAME : thread.cpp
// PROGRAM PURPOSE : 
//          This is the class that has the implementation
//          for the threads.
// ----------------------------------------------------------------

#include "thread.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <cmath>

// ----------------------------------------------------------------
// FUNCTION : OddEven
//       Constructor for the threads
// PARAMETER USAGE :
//       EVEN - originally was used to determine if it was even
//                or odd pass
//       NUM - The Index number given to it that determines the indexes
//                it will compare with.
//       *FLAG - A pointer that is set to 1 if a swap is made
//       *ARRAY - The array that is to be used/sorted
// FUNCTION CALLED :
//       NONE
// ---------------------------------------------------------------
OddEven::OddEven(int EVEN, int NUM, int* FLAG, int* ARRAY)
   :even(EVEN), num(NUM),flag(FLAG), array(ARRAY)
{
   //empty body
}

// ----------------------------------------------------------------
// FUNCTION : ThreadFunc
//       Function that runs the logic for the thread.
// PARAMETER USAGE :
//       NONE
// FUNCTION CALLED :
//       Thread::ThreadFunc() - creates a thread
//       sprintf() - used for printing
//       write() - used for printing
//       Exit() - used to exit the thread
// ---------------------------------------------------------------
void OddEven::ThreadFunc() {
   Thread::ThreadFunc();

   char buff[256]; //buffer for printing
   sprintf(buff,"        Thread %d Created\n", num);
   write(1,buff,strlen(buff));

   sprintf(buff,"        Thread %d compares x[%d] and x[%d]\n",
         num,num-1,num);
   write(1,buff,strlen(buff));

   if ( array[num-1] > array[num] ) {
      //swap
      int temp = array[num-1];
      array[num-1] = array[num];
      array[num] = temp;
      *flag = 1; //sets the flag to true

      sprintf(buff,"       Thread %d swaps x[%d] and x[%d]\n",
            num,num-1,num);
      write(1,buff,strlen(buff));
      
   }


   //exits
   sprintf(buff,"        Thread %d Exits\n", num);
   write(1,buff,strlen(buff));

   Exit();
}
