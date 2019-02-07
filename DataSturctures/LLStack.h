#pragma once
#include"LinkedList.h"
class LLStack
{
	LinkedList* list;
public:
	LLStack();
	bool isEmpty() const;
	void Push(int);
	void Pop();
	int Top() const;
	void Display() const;
	~LLStack();
};