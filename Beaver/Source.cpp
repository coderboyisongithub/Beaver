// Beaver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <functional>
#include <chrono>
#include "partial.h"

#define timeIt(X) X.now()
#define __REF(X) printf("\n reference:%x ",&X)

int main()
{



	std::chrono::high_resolution_clock clock;

	std::chrono::time_point start = timeIt(clock);

	// Example: obtain partial derivative for (x1*x2)+(x2*x3)
	variable x1(2.00), x2(5.0), x3(3.50f), x4(3.213);

	variable expression = sin(x1) + cos(x2);

	variable dx1 = expression.differentiate(x1);
	variable dx2 = expression.differentiate(x2);

	variable gradient = dx1 + dx2;


	std::chrono::time_point stop = timeIt(clock);


	printf("\n sum of partial:%f And actual sum of gradients: %f", gradient.value(), expression.partial());
	std::cout << "\n Runtime(mIcroSec): " << (std::chrono::duration_cast<std::chrono::microseconds>(stop - start)).count();

	return 0;
}


