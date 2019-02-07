#include "pch.h"
#include "LLStack.h"


LLStack::LLStack()
{
	this->list = new LinkedList;
}

bool LLStack::isEmpty() const
{
	return list->TopFront() == nullptr;
}

void LLStack::Push(int k)
{
	list->PushFront(new Node(k));
}

void LLStack::Pop()
{
	list->PopFront();
}

int LLStack::Top() const
{
	return list->TopFront()->getKey();
}

void LLStack::Display() const
{
	list->dispaly();
}


LLStack::~LLStack()
{
	delete list;
}
