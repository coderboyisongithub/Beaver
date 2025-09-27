#pragma once
#include <iostream>

namespace bv {}



struct dual
{
	float value, partial;


	dual()
	{
		value = 1.0;
		partial = 1.0;
	}
	dual(float value_, float partial_ = 1.0)
	{
		value = value_;
		partial = partial_;
	}


	dual operator+(dual other)
	{
		return { value + other.value,	partial + other.partial };
	}
	dual operator-(dual other)
	{
		return { value - other.value,	partial - other.partial };
	}
	dual operator*(dual other)
	{
		return { value * other.value,	value * other.partial + other.value * partial };
	}
};


dual log(dual x)
{
	return dual{ log(x.value),(x.partial / x.value) };
}

dual sin(dual x)
{
	return dual{ sin(x.value),x.partial*cos(x.value) };
}

dual cos(dual x)
{
	return dual{ cos(x.value),-x.partial*sin(x.value) };
}

dual exp(dual x)
{
	return dual{ exp(x.value),x.partial*exp(x.value) };
}








