#pragma once
#include"Node.h"
#include<iostream>

template <typename T>
class LinkedList
{
private:
	Node<T> *head, *tail;
public:
	LinkedList(Node<T>* H = nullptr);
	void PushFront(Node<T>*);
	Node<T>* TopFront();
	void PopFront();
	void PushBack(Node<T>* N);
	Node<T>* TopBack();
	void PopBack();
	Node<T>* Search(T) const;
	void Erase(Node<T>*);
	void AddAfter(Node<T>* N, T key);
	void AddBefore(Node<T>* N, T key);
	void dispaly() const;
	~LinkedList();
};

template <typename T>
inline LinkedList<T>::LinkedList(Node<T>* H)
{
	this->head = H;
	this->tail = NULL;
}

template <typename T>
inline void LinkedList<T>::PushFront(Node<T>* N)
{
	if (head == nullptr) head = tail = N;
	else {
		head->prev = N;
		N->next = head;
		head = N;
		if (head->next == nullptr) tail = head;
	}
}

template <typename T>
inline Node<T>* LinkedList<T>::TopFront()
{
	return head;
}

template <typename T>
inline void LinkedList<T>::PopFront()
{
	if (head == nullptr)
		return;
	else {
		Node<T>* t = head;
		head = head->next;
		delete t;
		head->prev = nullptr;
	}
}

template <typename T>
inline void LinkedList<T>::PushBack(Node<T>* N)
{
	if (head == nullptr)
		head = tail = N;
	else {
		N->prev = tail;
		tail->next = N;
		tail = N;
	}
}

template <typename T>
inline Node<T>* LinkedList<T>::TopBack()
{
	return tail;
}

template <typename T>
inline void LinkedList<T>::PopBack()
{
	if (tail == nullptr) return;
	else if (head == tail) {
		delete head;
		head = tail = nullptr;
	}
	else {
		Node<T>* t = tail;
		tail = tail->prev;
		delete t;
		tail->next = nullptr;
	}
}

template <typename T>
inline Node<T> * LinkedList<T>::Search(T key) const
{
	Node<T>* ptr = head;
	while (ptr->next != nullptr && ptr->getKey() != key)
		ptr = ptr->next;

	return ptr;
}

template <typename T>
inline void LinkedList<T>::Erase(Node<T>* N)
{
	N->prev->next = N->next;
	N->next->prev = N->prev;
	delete N;
}

template <typename T>
inline void LinkedList<T>::AddAfter(Node<T> * N, T key)
{
	Node* newN = new Node<T>(key);
	if (N == tail) {
		PushBack(newN);
		return;
	}
	newN->next = N->next;
	N->next->prev = newN;
	newN->prev = N;
	N->next = newN;
}

template <typename T>
inline void LinkedList<T>::AddBefore(Node<T> * N, T key)
{
	if (N == head) PushFront(new Node<T>(key));
	else AddAfter(N->prev, key);
}

template <typename T>
inline void LinkedList<T>::dispaly() const
{
	if (head == nullptr) {
		std::cout << "Empty List\n";
	}
	else {
		Node<T>* ptr = head;
		//Printing Forward
		while (ptr != nullptr) {
			std::cout << ptr->getKey();
			ptr = ptr->next;
			if (ptr != nullptr) std::cout << "<->";
			else break;
		}
		std::cout << "\n\n";
		//Prining Backward
		ptr = tail;
		while (ptr != nullptr) {
			std::cout << ptr->getKey();
			ptr = ptr->prev;
			if (ptr != nullptr) std::cout << "<->";
			else return;
		}
		std::cout << "\n\n";
	}
}

template<typename T>
inline LinkedList<T>::~LinkedList()
{
	delete head; delete tail;
}




