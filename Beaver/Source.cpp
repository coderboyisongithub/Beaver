// Beaver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "dual.h"




int main()
{
    
    // Example: derivative of sin(x)+cos(x)
    dual x1(0.3f), x2(10.0f);
    dual res =sin(x1) + cos(x1);
    std::cout << "value:" << res.value << " partial:" << res.partial;
    

    return 0;
}


