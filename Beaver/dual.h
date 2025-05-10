#pragma once
#include <iostream>
struct dual 
{
	float value, partial;
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
		return { value*other.value,	value*other.partial+other.value*partial};
	}
};


dual log(dual x) 
{
	return dual{ log(x.value),(1 /x.value) };
}

dual sin(dual x)
{
	return dual{ sin(x.value),cos(x.value) };
}

dual cos(dual x)
{
	return dual{ cos(x.value),-sin(x.value) };
}

dual exp(dual x)
{
	return dual{exp(x.value),exp(x.value)};
}










