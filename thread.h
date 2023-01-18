// -----------------------------------------------------------------
// NAME : Caleb Melnychenko                  User ID: chmelnyc
// DUE DATE : 03/18/2020
// PROGRAM ASSIGNMENT 3
// FILE NAME : thread.h
// PROGRAM PURPOSE : 
//       Holds the framework for the Thread class.
// ----------------------------------------------------------------

#ifndef _THREAD_H
#define _THREAD_H

#include "ThreadClass.h"
#include <iostream>
#include <stdio.h>
#include <string.h>

class OddEven : public Thread {
   public:
      OddEven(int EVEN, int NUM, int* FLAG, int* ARRAY); //constructor

   private:
      int even; //identifier for even run
      int num; //thread number
      int* flag; //flag reference
      int* array; //Array that is being used/referenced
      void ThreadFunc(); //Thread function

};

#endif
