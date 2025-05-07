// Beaver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Header.h"

int main()
{
    
    // Example: Finding the partials of z = x * (x + y) + y * y at (x, y) = (2, 3)
    // f(x)=x*x+x;
    
    float x1=2, x2=10;
    dual a(x1), b(x2);
    dual res = a * a * a + a*a;
    std::cout << "value:" << res.value << " partial:" << res.partial;
    

    return 0;
}


