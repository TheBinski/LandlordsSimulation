// -----------------------------------------------------------------
// NAME : Caleb Melnychenko                 
// FILE NAME : thread-main.cpp
// PROGRAM PURPOSE : 
//       This program will take in an array of integers
//       from a file and sort them using the OddEven sorting
//       algorithm, and will also utilize threads to do so.
// ----------------------------------------------------------------

#include <iostream>
#include "thread.h"
#include <string.h>
#include <stdio.h>
#include <cmath>
using namespace std;

int main(void) {
   
   //reads in the first number which is the number of elements
   int n;
   cin >> n;
   cout << "Concurrent Even-Odd Sort" << endl << endl;
   cout << "Number of input data = " << n << endl;
   
   //takes in and outputs the data for the array
   int x[n];
   cout << "Input array:" << endl;
   for( int i = 0; i < n; i++ ) {
      cin >> x[i];
      if ( i % 20 == 0 && i != 0 ) {
         cout << endl;
      }
      cout << "   " << x[i];
   }
   cout << endl << endl << endl;

   int flag; //0 no swaps taken place, 1 swaps have happened
   flag = 1;
   OddEven* threads[n]; //threads

   int k = 0; //keeps track current itteration
   while (flag) {
      flag = 0;
      k++;

      cout << endl << "Iteration " << k << ":" << endl;

      cout << "    Even Pass:" << endl;
      //Even Pass
      int id = 1;
      for ( int i = 1; i < n; i+=2 ) {
         threads[i] = new OddEven(1, i, &flag, x);
         threads[i]->Begin();
         id+=2;
      }

      //Even Joins
      for ( int i = 1; i < n; i+=2 ) {
         threads[i]->Join();
      }

      id = 2;
      cout << "    Odd Pass:" << endl;
      //Odd Pass
      for ( int i = 2; i < n; i+=2 ) {
         threads[i] = new OddEven(1, i, &flag, x);
         threads[i]->Begin();
         id+=2;
      }

      //Odd Joins
      for ( int i = 2; i < n; i+=2 ) {
         threads[i]->Join();
      }

         cout.precision(4);

      cout << endl << "Result after iteration " << k << ":" << endl;
      for ( int i = 0; i < n; i++ ) {
         if ( i % 20 == 0 && i != 0 ) {
            cout << endl;
         }
         cout << "   " << x[i];
      }
      cout << endl;

   }

   cout << endl << "Final result after iteration " << k << ":" << endl;
   for ( int i = 0; i < n; i++ ) {
      if ( i % 20 == 0 && i != 0 ) {
         cout << endl;
      }
      cout << "   " << x[i];
   }
   cout << endl;

   Exit();
   return 0;
}
