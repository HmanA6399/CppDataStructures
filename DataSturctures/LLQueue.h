#pragma once
#include<iostream>
#include"LinkedList.h"

template <typename T>
class LLQueue
{
	LinkedList<T>* list;
public:
	LLQueue();
	bool isEmpty() const;
	void Enqueue(T);
	T Dequeue();
	void display() const;
	~LLQueue();
};

template<typename T>
inline LLQueue<T>::LLQueue()
{
	list = new LinkedList<T>;
}

template<typename T>
inline bool LLQueue<T>::isEmpty() const
{
	return list->TopFront() == nullptr;
}

template<typename T>
inline void LLQueue<T>::Enqueue(T el)
{
	list->PushFront(new Node<T>(el));
}

template<typename T>
inline T LLQueue<T>::Dequeue()
{
	T t = list->TopBack()->getKey();
	list->PopBack();
	return T();
}

template<typename T>
inline void LLQueue<T>::display() const
{
	list->dispaly();
}

template<typename T>
inline LLQueue<T>::~LLQueue()
{
	delete list;
}


