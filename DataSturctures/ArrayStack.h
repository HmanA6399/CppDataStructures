#pragma once
template <typename T>
class ArrayStack
{
	T* arr, max, num = 0;
public:
	ArrayStack(int n);
	bool isEmpty() const;
	bool isFull() const;
	void Push(T);
	void Pop();
	T Top() const;
	void Display() const;
	~ArrayStack();
};

template <typename T>
inline ArrayStack<T>::ArrayStack(int n)
{
	this->max = n;
	this->arr = new T[n];
}

template <typename T>
inline bool ArrayStack<T>::isEmpty() const
{
	return num == 0;
}

template <typename T>
inline bool ArrayStack<T>::isFull() const
{
	return num == max;
}

template <typename T>
inline void ArrayStack<T>::Push(T el)
{
	if (isFull()) return;
	arr[num++] = el;
}

template <typename T>
inline void ArrayStack<T>::Pop()
{
	if (isEmpty()) return;
	num--;
}

template <typename T>
inline T ArrayStack<T>::Top() const
{
	if (num != 0) return arr[num - 1];
	else {
		return 0;
	}
}

template <typename T>
inline void ArrayStack<T>::Display() const
{
	std::cout << '\n';
	for (size_t i = 0; i < max; i++)
	{
		if (i < num) std::cout << ' ' << arr[i] << ' ';
		else std::cout << " [] ";
	}
	std::cout << '\n';
}

template <typename T>
inline ArrayStack<T>::~ArrayStack()
{
	delete[] arr;
}