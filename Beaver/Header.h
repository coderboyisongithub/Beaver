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




