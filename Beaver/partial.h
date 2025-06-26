#pragma once
#include <vector>
#include <memory>
#include<typeinfo>
#include "dual.h"



struct node
{
	dual number;
	std::vector<std::shared_ptr<node>> parents;
	node(dual initial) :number(initial) {}
	node() {};


};


struct mul_node:public node
{
	mul_node(std::shared_ptr<node> first, std::shared_ptr<node> second)
	{
		number = first->number * second->number;
		// add parents;
		parents.resize(2);
		parents[0] = first;
		parents[1] = second;
	   
	}
	

};


struct add_node :public node
{

	add_node(std::shared_ptr<node> first, std::shared_ptr<node> second)
	{
		number = first->number + second->number;
		// add parents;
		parents.resize(2);
		parents[0] = first;
		parents[1] = second;


	}
	
};





class variable
{
	
	std::shared_ptr<node> op_node;

	variable(std::shared_ptr<node> op_node_other)
	{
		op_node = std::make_shared<node>(*op_node_other.get());
		op_node->number = op_node_other->number;
		op_node->parents = op_node_other->parents;

	}

	void traverse(std::shared_ptr<node> n,int i, std::vector<std::shared_ptr<node>> &cache)
	{
		if (std::find(cache.begin(), cache.end(), n) != cache.end()) //found
			return;
		
		cache.push_back(n);
		printf("\nlevel:%d Node:%f,%f",i, n->number.value, n->number.partial);
		printf("\n  parents..");
		
		cache.push_back(n);
		for (std::shared_ptr<node> parent : n->parents)
		{
			printf("\n  (%f,%f)", parent->number.value, parent->number.partial);
			
		}
		for (std::shared_ptr<node> parent : n->parents)
		{
			traverse(parent, i + 1,cache);

		}

		

	}

public:
	variable(float value)
	{
		op_node = std::make_shared<node>(value);

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


	void about()
	{
		int count = 0;
		std::vector<std::shared_ptr<node>> visited;
		
		traverse(this->op_node, count,visited);
	}
	
	float grad() 
	{
		return op_node->number.partial;
	}

};