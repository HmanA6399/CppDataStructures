#include<iostream>
#include "pch.h"
#include "Tree.h"

int main()
{
	Tree<int>* intTree = new Tree<int>(4,
			new Tree<int>(6, 
	new Tree<int>(7),	new Tree<int>(5)),		 new Tree<int>(2,
											new Tree<int>(3),	new Tree<int>(1))
		);

	intTree->PostOrderPrint();
}