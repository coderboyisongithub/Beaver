#include "pch.h"
#include "../Beaver/partial.h"


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

TEST(findValidPath1_test, DAG_test)
{
    variable x1(2.00), x2(5.0), x3(3.35);

    variable res = (x1 * x2) + (x2 * x2);

    bool foundx1, foundx2;
    std::vector<std::vector<nodeptr>> validPath=res.toposort(x2);
    std::vector<std::vector<float>> expected_paths = {
     {35,25, 5},      // path 1
     {35,25, 5},          // path 2  
     {35,10,2},  // path 3
        // Add more expected paths as needed
    };

   
   

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
        EXPECT_TRUE(found);
    }
 
}

TEST(findValidPath2_test, DAG_test)
{
    variable x1(2.00), x2(5.0), x3(3.35);

    variable res = (x1 * x2) + (x2 * x2);

    bool foundx1, foundx2;
    std::vector<std::vector<nodeptr>> validPath = res.toposort(x1);
    std::vector<std::vector<float>> expected_paths = {
     {35,25, 5},      // path 1
     {35,25, 5},          // path 2  
     {35,10,2},  // path 3
     // Add more expected paths as needed
    };

   


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
        EXPECT_TRUE(found);
    }

}