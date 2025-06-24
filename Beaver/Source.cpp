// Beaver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <functional>

#include "partial.h"



//construct computational graph in forward pass.
//use association matrix.



dual derivative(dual x,unsigned int order)
{
    if (order == 1)
        return x.partial;
    else if (order == 0)
       return x.value;
    else derivative(x.partial,order-1);
}



/*
 for(int loop=0;loop<10;loop++)
    g.push_back({[]
        {
           std::vector<bv::node> nodes;
           for (int i = 0; i < 10; i++)
               nodes.push_back(bv::node(100.0));
           return nodes;

        }()});


    for (int i = 0; i < g.size(); i++)
    {
        for (int j = 0; j < g[i].size(); j++)
        {
            printf(" ,%.2f", g[i][j].dual_.value);
        }
}


  bv::DAG g2 = std::move(g);
    g.clear();

    std::cout << g2[0][0].dual_.value;


*/


dual objective(dual x1, dual x2)
{
    return x1 * x2 + x2 * x2;
}


std::function<void()> foo()
{
    auto lambda = []()
        {
           
            printf("hola");

        };
    
    return (lambda);

}

int main()
{
    
    dual v1(2.0), v2(5.0);

    node x1, x2;
    {
        x1.number = v1;
        x2.number = v2;

    }

   // mul_node(x1, x2); //X1 x X2
   // add_node(x1, x2);/// x1 + x2
  //  add_node(mul_node(x1, x2), add_node(x1, x2));   //(X1 x X2) +  (x1 + x2)
    // then how to do so that this expression builds the nodes automatically, the answer is operator overloading on a class;

    
   variable y1(2.0), y2(5.0);


    variable res=y1 + y2;
    res.get();
    // what res will hold here is the root node to the graph that is moved using moved operator during + operation.
    



  
  
  

    return 0;
}


