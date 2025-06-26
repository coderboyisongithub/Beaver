#pragma once
#include <vector>
#include <memory>
#include<typeinfo>
#include "dual.h"



struct node
{
	dual number;
	std::vector<node> parents;
	node(dual initial) :number(initial) {}
	node() {};

};


struct mul_node:public node
{
	mul_node(node first, node second)
	{
		number = first.number * second.number;
		// add parents;
		parents.resize(2);
		parents[0] = first;
		parents[1] = second;


		//printf("\n%f,%f", number.value, number.partial);


	}
	

};


struct add_node :public node
{

	add_node(node first, node second)
	{
		number = first.number + second.number;
		// add parents;
		parents.resize(2);
		parents[0] = first;
		parents[1] = second;


		//printf("\n%f,%f", number.value, number.partial);


	}
	
};





class variable
{
	
	node op_node;

	variable(std::shared_ptr<node> op_node_other)
	{
		op_node.number = op_node_other->number;
		op_node.parents = op_node_other->parents;

	}

	void parent_(node n,int i)
	{

		if (n.parents.empty())
			return;
		else
			for (node parent : n.parents)
			{
				printf("\n%d parent::(%f , %f) --> %s ",i, parent.number.value,parent.number.partial, typeid(parent).name());
			
				parent_(parent,++i);

			}

	}

public:
	variable(float value)
	{
		op_node.number = dual(value);
	};
	
	variable operator+(variable second)
	{

		std::shared_ptr<node> op = std::make_shared<add_node>(this->op_node, second.op_node);
		return std::move(variable(op));

	}
	variable operator*(variable second)
	{
		
		std::shared_ptr<node>op = std::make_shared<mul_node>(this->op_node, second.op_node);
		return std::move(variable(op));


	}


	void get()
	{
		int i = 1;
		printf("\n%d root::(%f %f)",i, op_node.number.value, op_node.number.partial);
		parent_(this->op_node,++i);
	

	}
	
	float grad()
	{
		return op_node.number.partial;
	}

};