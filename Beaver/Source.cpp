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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
