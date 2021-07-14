
/* Demetra Drizis
   Project 2
   10/09/19
*/

#include <iostream>
#include <string>
#include <chrono>
#include <stdlib.h>
#include <time.h>
#include "List.h"

using namespace std;
using namespace cop4530;

#define REPEATS 5

int main(int argc, char ** argv) {

   List<int> nums[REPEATS];

   int cnt = 100;
   int range = cnt / 3;
   
   for (int j = 0; j < REPEATS; j++) {
      /* initialize a random seed;
       * generate a random number between 1 and range.  */
      srand (time(NULL));
      for (int i = 0; i < cnt; i++) {
         int item = rand() % range + 1;
         nums[j].push_back(item);
      }
   }

   auto r_start = chrono::steady_clock::now();
   for (int i = 0; i < REPEATS; i++) {
      nums[i].reverse();
   }
   auto r_end = chrono::steady_clock::now();

   int usec = chrono::duration_cast<chrono::microseconds>(r_end - r_start).count();
   cout << endl << "reverse " <<cnt<<"-item list: " << usec/REPEATS<<" usec"<<endl;

////////////////////////////////////////////////////////////////////////////////////////

   int cnt_2 = 100;
   int range_2 = cnt_2 / 3;


   for (int j = 0; j < REPEATS; j++) {
      /* initialize a random seed;
       * generate a random number between 1 and range.  */
      srand (time(NULL));
      for (int i = 0; i < cnt_2; i++) {
         int item_2 = rand() % range_2 + 1;
         nums[j].push_back(item_2);
      }
   }

   auto r_start_2 = chrono::steady_clock::now();
   for (int i = 0; i < REPEATS; i++) {
      nums[i].reverse();
   }
   auto r_end_2 = chrono::steady_clock::now();

   int usec_2 = chrono::duration_cast<chrono::microseconds>(r_end_2 - r_start_2).count();
   cout << "reverse " <<cnt_2<<"-item list: " << usec_2/REPEATS<<" usec"<<endl;

////////////////////////////////////////////////////////////////////////////////////////

   int cnt_3 = 100;
   int range_3 = cnt_3 / 3;


   for (int j = 0; j < REPEATS; j++) {
      /* initialize a random seed;
       * generate a random number between 1 and range.  */
      srand (time(NULL));
      for (int i = 0; i < cnt_3; i++) {
         int item_3 = rand() % range_3 + 1;
         nums[j].push_back(item_3);
      }
   }

   auto r_start_3 = chrono::steady_clock::now();
   for (int i = 0; i < REPEATS; i++) {
      nums[i].reverse();
   }
   auto r_end_3 = chrono::steady_clock::now();

   int usec_3 = chrono::duration_cast<chrono::microseconds>(r_end_3 - r_start_3).count();
   cout << "reverse " <<cnt_3<<"-item list: " << usec_3/REPEATS<<" usec"<<endl;

   cout << endl; 
   cout << "Average execution time for 100 item list: " << ((usec/REPEATS) + (usec_2/REPEATS) + (usec_3/REPEATS))/3.0 << " usec" << endl << endl;


/////* Reverse with 1000 *//////

   int cnt2 = 1000;
   int range2 = cnt2 / 3;

   for (int j = 0; j < REPEATS; j++) {
      /* initialize a random seed;
       * generate a random number between 1 and range.  */
      srand (time(NULL));
      for (int i = 0; i < cnt2; i++) {
         int item2 = rand() % range2 + 1;
         nums[j].push_back(item2);
      }
   }

   auto r_start2 = chrono::steady_clock::now();
   for (int i = 0; i < REPEATS; i++) {
      nums[i].reverse();
   }
   auto r_end2 = chrono::steady_clock::now();

   int usec2 = chrono::duration_cast<chrono::microseconds>(r_end2 - r_start2).count();
   cout << "reverse " <<cnt2<<"-item list: " << usec2/REPEATS<<" usec"<<endl;

/////////////////////////////////////////////////////////////////////////////////////////////

   int cnt2_3 = 1000;
   int range2_3 = cnt2_3 / 3;

   for (int j = 0; j < REPEATS; j++) {
      /* initialize a random seed;
       * generate a random number between 1 and range.  */
      srand (time(NULL));
      for (int i = 0; i < cnt2_3; i++) {
         int item2_3 = rand() % range2_3 + 1;
         nums[j].push_back(item2_3);
      }
   }

   auto r_start2_3 = chrono::steady_clock::now();
   for (int i = 0; i < REPEATS; i++) {
      nums[i].reverse();
   }
   auto r_end2_3 = chrono::steady_clock::now();

   int usec2_3 = chrono::duration_cast<chrono::microseconds>(r_end2_3 - r_start2_3).count();
   cout << "reverse " <<cnt2_3<<"-item list: " << usec2_3/REPEATS<<" usec"<<endl;

/////////////////////////////////////////////////////////////////////////////////////////////

   int cnt2_4 = 1000;
   int range2_4 = cnt2_4 / 3;

   for (int j = 0; j < REPEATS; j++) {
      /* initialize a random seed;
       * generate a random number between 1 and range.  */
      srand (time(NULL));
      for (int i = 0; i < cnt2_4; i++) {
         int item2_4 = rand() % range2_4 + 1;
         nums[j].push_back(item2_4);
      }
   }

   auto r_start2_4 = chrono::steady_clock::now();
   for (int i = 0; i < REPEATS; i++) {
      nums[i].reverse();
   }
   auto r_end2_4 = chrono::steady_clock::now();

   int usec2_4 = chrono::duration_cast<chrono::microseconds>(r_end2_4 - r_start2_4).count();
   cout << "reverse " <<cnt2_4<<"-item list: " << usec2_4/REPEATS<<" usec"<<endl;

   cout << endl;
   cout << "Average execution time for 1,000 item list: " << ((usec2/REPEATS) + (usec2_3/REPEATS) + (usec2_4/REPEATS))/3.0 << " usec" << endl << endl;


/////* Reverse with 10,000 *//////

   int cnt3 = 10000;
   int range3 = cnt3 / 3;

   for (int j = 0; j < REPEATS; j++) {
      /* initialize a random seed;
       * generate a random number between 1 and range.  */
      srand (time(NULL));
      for (int i = 0; i < cnt3; i++) {
         int item3 = rand() % range3 + 1;
         nums[j].push_back(item3);
      }
   }

   auto r_start3 = chrono::steady_clock::now();
   for (int i = 0; i < REPEATS; i++) {
      nums[i].reverse();
   }
   auto r_end3 = chrono::steady_clock::now();

   int usec3 = chrono::duration_cast<chrono::microseconds>(r_end3 - r_start3).count();
   cout << "reverse " <<cnt3<<"-item list: " << usec3/REPEATS<<" usec"<<endl;

//////////////////////////////////////////////////////////////////////////////////////////

   int cnt3_1 = 10000;
   int range3_1 = cnt3_1 / 3;

   for (int j = 0; j < REPEATS; j++) {
      /* initialize a random seed;
       * generate a random number between 1 and range.  */
      srand (time(NULL));
      for (int i = 0; i < cnt3_1; i++) {
         int item3_1 = rand() % range3_1 + 1;
         nums[j].push_back(item3_1);
      }
   }

   auto r_start3_1 = chrono::steady_clock::now();
   for (int i = 0; i < REPEATS; i++) {
      nums[i].reverse();
   }
   auto r_end3_1 = chrono::steady_clock::now();

   int usec3_1 = chrono::duration_cast<chrono::microseconds>(r_end3_1 - r_start3_1).count();
   cout << "reverse " <<cnt3_1<<"-item list: " << usec3_1/REPEATS<<" usec"<<endl;

//////////////////////////////////////////////////////////////////////////////////////////

   int cnt3_2 = 10000;
   int range3_2 = cnt3_2 / 3;

   for (int j = 0; j < REPEATS; j++) {
      /* initialize a random seed;
       * generate a random number between 1 and range.  */
      srand (time(NULL));
      for (int i = 0; i < cnt3_2; i++) {
         int item3_2 = rand() % range3_2 + 1;
         nums[j].push_back(item3_2);
      }
   }

   auto r_start3_2 = chrono::steady_clock::now();
   for (int i = 0; i < REPEATS; i++) {
      nums[i].reverse();
   }
   auto r_end3_2 = chrono::steady_clock::now();

   int usec3_2 = chrono::duration_cast<chrono::microseconds>(r_end3_2 - r_start3_2).count();
   cout << "reverse " <<cnt3_2<<"-item list: " << usec3_2/REPEATS<<" usec"<<endl;

   cout << endl;
   cout << "Average execution time for 10,000 item list: " << ((usec3/REPEATS) + (usec3_1/REPEATS) + (usec3_2/REPEATS))/3.0 << " usec" << endl;
   cout << "----------------------------------------------------------" << endl;

/////* Deduplicate with 100 *//////

   int cnt4 = 100;
   int range4 = cnt4/3;

   for (int j = 0; j < REPEATS; j++) {
      /* initialize a random seed;
       * generate a random number between 1 and range.  */
      srand (time(NULL));
      for (int i = 0; i < cnt4; i++) {
         int item4 = rand() % range4 + 1;
         nums[j].push_back(item4);
      }
   }

   auto r_start4 = chrono::steady_clock::now();
   for (int i = 0; i < REPEATS; i++) {
      nums[i].deduplicate();
   }
   auto r_end4 = chrono::steady_clock::now();

   int usec4 = chrono::duration_cast<chrono::microseconds>(r_end4 - r_start4).count();
   cout << "deduplicate " <<cnt4<<"-item list: " << usec4/REPEATS<<" usec"<<endl;


//////////////////////////////////////////////////////////////////////////////////////////

   int cnt4_1 = 100;
   int range4_1 = cnt4_1/3;

   for (int j = 0; j < REPEATS; j++) {
      /* initialize a random seed;
       * generate a random number between 1 and range.  */
      srand (time(NULL));
      for (int i = 0; i < cnt4_1; i++) {
         int item4_1 = rand() % range4_1 + 1;
         nums[j].push_back(item4_1);
      }
   }

   auto r_start4_1 = chrono::steady_clock::now();
   for (int i = 0; i < REPEATS; i++) {
      nums[i].deduplicate();
   }
   auto r_end4_1 = chrono::steady_clock::now();

   int usec4_1 = chrono::duration_cast<chrono::microseconds>(r_end4_1 - r_start4_1).count();
   cout << "deduplicate " <<cnt4_1<<"-item list: " << usec4_1/REPEATS<<" usec"<<endl;

//////////////////////////////////////////////////////////////////////////////////////////

   int cnt4_2 = 100;
   int range4_2 = cnt4_2/3;

   for (int j = 0; j < REPEATS; j++) {
      /* initialize a random seed;
       * generate a random number between 1 and range.  */
      srand (time(NULL));
      for (int i = 0; i < cnt4_2; i++) {
         int item4_2 = rand() % range4_2 + 1;
         nums[j].push_back(item4_2);
      }
   }

   auto r_start4_2 = chrono::steady_clock::now();
   for (int i = 0; i < REPEATS; i++) {
      nums[i].deduplicate();
   }
   auto r_end4_2 = chrono::steady_clock::now();

   int usec4_2 = chrono::duration_cast<chrono::microseconds>(r_end4_2 - r_start4_2).count();
   cout << "deduplicate " <<cnt4_2<<"-item list: " << usec4_2/REPEATS<<" usec"<<endl;

   cout << endl;
   cout << "Average execution time for 100 item list: " << ((usec4/REPEATS) + (usec4_1/REPEATS) + (usec4_2/REPEATS))/3.0 << " usec" << endl << endl;

/////* Deduplicate with 1000 *//////

   int cnt5 = 1000;
   int range5 = cnt5/3;

   for (int j = 0; j < REPEATS; j++) {
      /* initialize a random seed;
       * generate a random number between 1 and range.  */
      srand (time(NULL));
      for (int i = 0; i < cnt5; i++) {
         int item5 = rand() % range5 + 1;
         nums[j].push_back(item5);
      }
   }

   auto r_start5 = chrono::steady_clock::now();
   for (int i = 0; i < REPEATS; i++) {
      nums[i].deduplicate();
   }
   auto r_end5 = chrono::steady_clock::now();

   int usec5 = chrono::duration_cast<chrono::microseconds>(r_end5 - r_start5).count();
   cout << "deduplicate " <<cnt5<<"-item list: " << usec5/REPEATS<<" usec"<<endl;

//////////////////////////////////////////////////////////////////////////////////////////

   int cnt5_1 = 1000;
   int range5_1 = cnt5_1/3;

   for (int j = 0; j < REPEATS; j++) {
      /* initialize a random seed;
       * generate a random number between 1 and range.  */
      srand (time(NULL));
      for (int i = 0; i < cnt5_1; i++) {
         int item5_1 = rand() % range5_1 + 1;
         nums[j].push_back(item5_1);
      }
   }

   auto r_start5_1 = chrono::steady_clock::now();
   for (int i = 0; i < REPEATS; i++) {
      nums[i].deduplicate();
   }
   auto r_end5_1 = chrono::steady_clock::now();

   int usec5_1 = chrono::duration_cast<chrono::microseconds>(r_end5_1 - r_start5_1).count();
   cout << "deduplicate " <<cnt5_1<<"-item list: " << usec5_1/REPEATS<<" usec"<<endl;

//////////////////////////////////////////////////////////////////////////////////////////

   int cnt5_2 = 1000;
   int range5_2 = cnt5_2/3;

   for (int j = 0; j < REPEATS; j++) {
      /* initialize a random seed;
       * generate a random number between 1 and range.  */
      srand (time(NULL));
      for (int i = 0; i < cnt5_2; i++) {
         int item5_2 = rand() % range5_2 + 1;
         nums[j].push_back(item5_2);
      }
   }

   auto r_start5_2 = chrono::steady_clock::now();
   for (int i = 0; i < REPEATS; i++) {
      nums[i].deduplicate();
   }
   auto r_end5_2 = chrono::steady_clock::now();

   int usec5_2 = chrono::duration_cast<chrono::microseconds>(r_end5_2 - r_start5_2).count();
   cout << "deduplicate " <<cnt5_2<<"-item list: " << usec5_2/REPEATS<<" usec"<<endl;

   cout << endl;
   cout << "Average execution time for 1,000 item list: " << ((usec5/REPEATS) + (usec5_1/REPEATS) + (usec5_2/REPEATS))/3.0 << " usec" << endl << endl;

/////* Deduplicate with 10,000 *//////

   int cnt6 = 10000;
   int range6 = cnt6/3;

   for (int j = 0; j < REPEATS; j++) {
      /* initialize a random seed;
       * generate a random number between 1 and range.  */
      srand (time(NULL));
      for (int i = 0; i < cnt6; i++) {
         int item6 = rand() % range6 + 1;
         nums[j].push_back(item6);
      }
   }

   auto r_start6 = chrono::steady_clock::now();
   for (int i = 0; i < REPEATS; i++) {
      nums[i].deduplicate();
   }
   auto r_end6 = chrono::steady_clock::now();

   int usec6 = chrono::duration_cast<chrono::microseconds>(r_end6 - r_start6).count();
   cout << "deduplicate " <<cnt6<<"-item list: " << usec6/REPEATS<<" usec"<<endl;

//////////////////////////////////////////////////////////////////////////////////////////

   int cnt6_1 = 10000;
   int range6_1 = cnt6_1/3;

   for (int j = 0; j < REPEATS; j++) {
      /* initialize a random seed;
       * generate a random number between 1 and range.  */
      srand (time(NULL));
      for (int i = 0; i < cnt6_1; i++) {
         int item6_1 = rand() % range6_1 + 1;
         nums[j].push_back(item6_1);
      }
   }

   auto r_start6_1 = chrono::steady_clock::now();
   for (int i = 0; i < REPEATS; i++) {
      nums[i].deduplicate();
   }
   auto r_end6_1 = chrono::steady_clock::now();

   int usec6_1 = chrono::duration_cast<chrono::microseconds>(r_end6_1 - r_start6_1).count();
   cout << "deduplicate " <<cnt6_1<<"-item list: " << usec6_1/REPEATS<<" usec"<<endl;

//////////////////////////////////////////////////////////////////////////////////////////

   int cnt6_2 = 10000;
   int range6_2 = cnt6_2/3;

   for (int j = 0; j < REPEATS; j++) {
      /* initialize a random seed;
       * generate a random number between 1 and range.  */
      srand (time(NULL));
      for (int i = 0; i < cnt6_2; i++) {
         int item6_2 = rand() % range6_2 + 1;
         nums[j].push_back(item6_2);
      }
   }

   auto r_start6_2 = chrono::steady_clock::now();
   for (int i = 0; i < REPEATS; i++) {
      nums[i].deduplicate();
   }
   auto r_end6_2 = chrono::steady_clock::now();

   int usec6_2 = chrono::duration_cast<chrono::microseconds>(r_end6_2 - r_start6_2).count();
   cout << "deduplicate " <<cnt6_2<<"-item list: " << usec6_2/REPEATS<<" usec"<<endl;

   cout << endl;
   cout << "Average execution time for 10,000 item list: " << ((usec6/REPEATS) + (usec6_1/REPEATS) + (usec6_2/REPEATS))/3.0 << " usec" << endl << endl;

   return 0;
}

