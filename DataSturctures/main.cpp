#include<iostream>
#include "pch.h"
#include "LLQueue.h"

int main()
{
	LLQueue<int>* qu = new LLQueue<int>;
	for (int i = 0; i < 10; ++i) qu->Enqueue(i + 1);
	qu->display();
}