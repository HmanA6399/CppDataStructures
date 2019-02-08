#pragma once
#include"LinkedList.h"
template <typename T>
class LLStack
{
	LinkedList<T>* list;
public:
	LLStack();
	bool isEmpty() const;
	void Push(T);
	void Pop();
	T Top() const;
	void Display() const;
	~LLStack();
};

template <typename T>
inline LLStack<T>::LLStack()
{
	this->list = new LinkedList<T>;
}

template <typename T>
inline bool LLStack<T>::isEmpty() const
{
	return list->TopFront() == nullptr;
}

template <typename T>
inline void LLStack<T>::Push(T k)
{
	list->PushFront(new Node<T>(k));
}

template <typename T>
inline void LLStack<T>::Pop()
{
	list->PopFront();
}

template <typename T>
inline T LLStack<T>::Top() const
{
	return list->TopFront()->getKey();
}

template <typename T>
inline void LLStack<T>::Display() const
{
	list->dispaly();
}

template <typename T>
inline LLStack<T>::~LLStack()
{
	delete list;
}
