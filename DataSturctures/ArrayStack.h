#pragma once
class ArrayStack
{
	int* arr, max, num = 0;
public:
	ArrayStack(int n);
	bool isEmpty() const;
	bool isFull() const;
	void Push(int);
	void Pop();
	int Top() const;
	void Display() const;
	~ArrayStack();
};