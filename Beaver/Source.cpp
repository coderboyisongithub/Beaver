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
	int count = 0;

	
	std::chrono::time_point start = timeIt(clock);
	// Example: obtain partial derivative for log(x1)+x1*x2-sin(x2);


		variable x1(2.34), x2(-5.0), x3(3.50f), x4(-3.213);

		variable xz = x3 + x2;

		variable expression = log(x1)+x1*x2-sin(x2);
		variable dx1 = expression.differentiate(x1);
		variable dx2 = expression.differentiate(x2);
		variable dx3 = expression.differentiate(x3);
		variable dx4 = expression.differentiate(x4);
		variable gradient = dx1 + dx3 + dx2 + dx4;
		std::chrono::time_point stop = timeIt(clock);

	printf("\n sum of partial:%.10f And actual sum of gradients: %.10f and result of operation :%f", gradient.value(), expression.partial(), expression.value());
		std::cout << "\n Runtime(mIcroSec): " << (std::chrono::duration_cast<std::chrono::microseconds>(stop - start)).count();
	
	return 0;
}


