#pragma once
#include<iostream>
template <typename T>
class ArrayQueue
{
	T* arr;
	int max, num, en, de;
public:
	ArrayQueue(int);
	bool isEmpty() const;
	bool isFull() const;
	void Enqueue(T);
	T Dequeue();
	void display() const;
	~ArrayQueue();
};

template <typename T>
ArrayQueue<T>::ArrayQueue(int n)
{
	max = n;
	arr = new T[n];
	num = en = de = 0;
}

template<typename T>
inline bool ArrayQueue<T>::isEmpty() const
{
	return num == 0;
}

template<typename T>
inline bool ArrayQueue<T>::isFull() const
{
	return num == max;
}

template<typename T>
inline void ArrayQueue<T>::Enqueue(T val)
{
	if (isFull()) return;
	else {
		arr[en++] = val;
		if (en >= max) en = 0;
		num++;
	}
}

template<typename T>
inline T ArrayQueue<T>::Dequeue()
{
	if (isEmpty()) return T(NULL);
	else {
		T t = arr[de];
		de = (de + 1 == max) ? 0 : de+1;
		num--;
		return T(t);
	}
}

template<typename T>
inline void ArrayQueue<T>::display() const
{
	if (this->isEmpty()) std::cout << "\nEmpty Queue\n";
	else {
		std::cout << "\nde->";
		if (de < en) {
			for (int i = de; i < en; ++i) std::cout << ' ' << arr[i] << ' ';
		} else {
			for (int i = de; i < max; ++i) std::cout << ' ' << arr[i] << ' ';
			for (int i = 0; i < en; ++i) std::cout << ' ' << arr[i] << ' ';
		}
		std::cout << "<-en\n";
	}
}

template <typename T>
ArrayQueue<T>::~ArrayQueue()
{
	delete[] arr;
}
