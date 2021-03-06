#include<iostream>
#include "pch.h"
#include "DynArray.h"
#include<string>

int main()
{
	try {
		int* arr = new int[10];
		for (int i = 0; i < 10; ++i) arr[i] = i + 1;
		DynArray<int> myArr(10, arr);
		myArr.Display();
		std::cout << myArr.PopBack() << '\n';
		myArr.Display();
		myArr.Remove(10);
	}
	catch (std::string e) {
		std::cout << e << '\n';
	}
}