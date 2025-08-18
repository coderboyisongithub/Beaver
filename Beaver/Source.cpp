// Beaver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <functional>
#include <chrono>
#include "partial.h"

#define timeIt(X) X.now()


bool ifvector_eq(std::vector<nodeptr> vec1, std::vector<float> vec2)
{
    if (vec1.size() != vec2.size())
        return false;
    for (size_t i = 0; i < vec1.size(); i++)
    {
        if (vec1[i]->number.value != vec2[i])
        {
            return false;
        }
    }

    return true;
}


#define __REF(X) printf("\n reference:%x ",&X)

int main()
{


   
    //NEXT::DFS and gradient computation.

    std::vector<std::vector<nodeptr>> pathlist;
    std::chrono::high_resolution_clock clock;
   
  
    std::chrono::time_point start = timeIt(clock);
    variable x1(2.00), x2(5.0),x3(3.35);
  
    variable res = (x1 * x2) + (x2 * x2);

   pathlist= res.toposort(x2);

  std::chrono::time_point stop = timeIt(clock);

  for (auto path : pathlist)
  {
      printf("\n");
      for (auto node : path)
      {
          printf("-->%f", node->number.value);
      }
  }


  std::vector<std::vector<nodeptr>> validPath = res.toposort(x1);
  std::vector<std::vector<float>> expected_paths = {
   {35,25, 5},      // path 1
   {35,25, 5},          // path 2  
   {35,10,2},  // path 3
   // Add more expected paths as needed
  };



  ///problem here is to check one set exist in set of set of other ..


  try {
      for (auto subset1 : expected_paths)
      {

          for (auto subset2 : validPath)
          {
              if (ifvector_eq(subset2, subset1))
              {
                  throw true;
                  break;
              }

          }

      }
  }
  catch (bool found)
  {
      std::cout << found;
  }







    std::cout<<"\n Runtime(Microsec): "<<(std::chrono::duration_cast<std::chrono::microseconds>(stop - start)).count();
    return 0;
}


