#include "pch.h"
#include<iostream>
#include "ArrayStack.h"


ArrayStack::ArrayStack(int n)
{
	this->max = n;
	this->arr = new int[n];
}

bool ArrayStack::isEmpty() const
{
	return num == 0;
}

bool ArrayStack::isFull() const
{
	return num == max;
}

void ArrayStack::Push(int el)
{
	if (isFull()) return;
	arr[num++] = el;
}

void ArrayStack::Pop()
{
	if (isEmpty()) return;
	num--;
}

int ArrayStack::Top() const
{
	if (num != 0) return arr[num - 1];
	else {
		return 0;
	}
}

void ArrayStack::Display() const
{
	std::cout << '\n';
	for (size_t i = 0; i < max; i++)
	{
		if (i < num) std::cout << ' ' << arr[i] << ' ';
		else std::cout << " [] ";
	}
	std::cout << '\n';
}

ArrayStack::~ArrayStack()
{
	delete[] arr;
}