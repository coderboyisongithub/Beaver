#pragma once
#include <vector>
#include <memory>
#include<typeinfo>
#include "dual.h"


//seed node will have no parents and no partials..



struct node
{
	dual number;
	std::vector<std::shared_ptr<node>> parents;
	std::vector<float>dwrtx; //derivative w.r.t seed
	node(dual initial) :number(initial) {}
	node() {};


};
typedef  std::shared_ptr<node> nodeptr;

struct mul_node:public node
{
	mul_node(std::shared_ptr<node> first, std::shared_ptr<node> second)
	{
		number = first->number * second->number;
		dwrtx.resize(2);
		dwrtx[0] = first->number.partial * second->number.value;
		dwrtx[1] = second->number.partial * first->number.value;
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
		dwrtx.resize(2);
		dwrtx[0] = first->number.partial;
		dwrtx[1] = second->number.partial;
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
		//BFS l 
		if (std::find(cache.begin(), cache.end(), n) != cache.end()) //found
			return;
		
		cache.push_back(n);
		printf("\nlevel:%d Node:%f,%f  at  %x",i, n->number.value, n->number.partial,n.get());
		printf("\n  parents..");
		
		cache.push_back(n);
		for (std::shared_ptr<node> parent : n->parents)
		{
			printf("\n  (%f,%f) ----", parent->number.value, parent->number.partial);
			for (float derivatives : parent->dwrtx)
			{
				printf("\n    derivative w.r.t seed %f", derivatives);
			}
			
		}
		for (std::shared_ptr<node> parent : n->parents)
		{
			traverse(parent, i + 1,cache);

		}

		

	}

	//check if this node is visited
	bool visited(std::vector<std::shared_ptr<node>> cache, std::shared_ptr<node> thisnode)
	{
		for (std::shared_ptr<node> n : cache)
		{

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


	void visit(std::shared_ptr<node>root, std::shared_ptr<node>& key, std::vector<std::shared_ptr<node>>& path)
	{

	}
	
	// Depth first search for all valid path to seed variable 'key'
	void DFS_generatevalidPath(std::shared_ptr<node>&root,
		std::shared_ptr<node>& seedVariable, 
		std::vector<std::shared_ptr<node>>& path, 
		std::vector<std::vector<std::shared_ptr<node>>>&validPath)
	{
	
		
	
		path.push_back(root);
		if (root->parents.empty())
		{
			if (root.get() == seedVariable.get())
			{
				int s = validPath.size();
				validPath.resize(++s);
				validPath[s - 1] = path;
			}
			
			return;
		}
		else
		{
			for (auto parent : root->parents)
			{
				DFS_generatevalidPath(parent, seedVariable, path, validPath);
				path.pop_back();
		   }
		}


		
			
	}


	//Topological sorting based on Depth-first search.
	std::vector<std::vector<std::shared_ptr<node>>>   toposort(variable& var)
	{
	std::vector<std::shared_ptr<node>> pathlist;
	std::vector<std::vector<std::shared_ptr<node>>> validPath;
		DFS_generatevalidPath(op_node, var.op_node, pathlist, validPath);
	return (validPath);
		
	}

	variable differentiate(variable &seed) // compute derivative w.r.t seed node at once
	{
		abort();


			 // Find the path to given node.. using topological sorting...
			 // computing partial derivative w.r.t parent node in the path
			 // accumulating the partial derivative till end.
		
		//return std::move(grad);

	}

	void about()
	{
		int count = 0;
		std::vector<std::shared_ptr<node>> visited;
		
		traverse(this->op_node, count,visited);
		
	}

	float value()
	{
		return  op_node->number.value;
	}
	float partial()
	{
		return op_node->number.partial;
	}
	
	float grad() 
	{
		return op_node->number.partial;
	}

};