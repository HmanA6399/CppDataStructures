#pragma once
#include<iostream>

template <typename T>
class DynArray
{
	T* arr_ptr;
	int size, max;
public:
	DynArray<T>(int, T* = nullptr);
	int Size() const;
	T Get(int) const;
	void Set(int, T);
	void PushBack(T);
	T PopBack();
	void Remove(int);
	void Display() const;
	~DynArray<T>();
};

template<typename T>
inline DynArray<T>::DynArray(int max, T* initArr)
{
	this->max = max; 
	if (initArr == nullptr) {
		this->arr_ptr = new T[max];
		this->size = 0;
	}
	else {
		this->arr_ptr = initArr;
		this->size = max;
	}
}

template<typename T>
inline DynArray<T>::~DynArray()
{
	delete[] arr_ptr;
}

template<typename T>
inline int DynArray<T>::Size() const
{
	return size;
}

template<typename T>
inline T DynArray<T>::Get(int i) const
{
	if (i < 0 || i >= size) throw (std::string)"Out Of Range";
	return arr_ptr[i];
}

template<typename T>
inline void DynArray<T>::Set(int i, T val)
{
	if (i < 0 || i >= size) throw (std::string)"Out Of Range";
	this->arr_ptr[i] = val;
}

template<typename T>
inline void DynArray<T>::PushBack(T val)
{
	if (this->size == this->max) {
		T* newArr = new T[max*2];
		for (int i = 0; i < size; ++i) newArr[i] = this->arr_ptr[i];
		delete[] this->arr_ptr;
		arr_ptr = newArr;
	}
	this->arr_ptr[size++] = val;
}

template<typename T>
inline T DynArray<T>::PopBack()
{
	if (size == 0) throw (std::string)"Empty Array";
	return arr_ptr[--size];
}

template<typename T>
inline void DynArray<T>::Remove(int i)
{
	if (i < 0 || i >= size)
		throw (std::string) "Out Of Range";
	else {
		for (int j = i; j < size - 1; ++j) arr_ptr[j] = arr_ptr[j + 1];
		--size;
	}
}

template<typename T>
inline void DynArray<T>::Display() const
{
	std::cout << '\n';
	for (int i = 0; i < size; ++i) std::cout << arr_ptr[i] << ' ';
	std::cout << '\n';
}
