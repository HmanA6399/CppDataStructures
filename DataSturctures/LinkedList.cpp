#include"pch.h"
#include"LinkedList.h"
#include<iostream>

LinkedList::LinkedList(Node* H)
{
	this->head = H;
	this->tail = NULL;
}

void LinkedList::PushFront(Node* N)
{
	if (head == nullptr) head = tail = N;
	else {
		head->prev = N;
		N->next = head;
		head = N;
		if (head->next == nullptr) tail = head;
	}
}

Node* LinkedList::TopFront()
{
	return head;
}

void LinkedList::PopFront()
{
	if (head == nullptr)
		return;
	else {
		Node* t = head;
		head = head->next;
		delete t;
		head->prev = nullptr;
	}
}

void LinkedList::PushBack(Node* N)
{
	if (head == nullptr)
		head = tail = N;
	else {
		N->prev = tail;
		tail->next = N;
		tail = N;
	}
}

Node* LinkedList::TopBack()
{
	return tail;
}

void LinkedList::PopBack()
{
	if (tail == nullptr) return;
	else if (head == tail) {
		delete head;
		head = tail = nullptr;
	}
	else {
		Node* t = tail;
		tail = tail->prev;
		delete t;
		tail->next = nullptr;
	}
}

Node * LinkedList::Search(int key) const
{
	Node* ptr = head;
	while (ptr->next != nullptr && ptr->getKey() != key)
		ptr = ptr->next;
	return ptr;
}

void LinkedList::Erase(Node* N)
{
	N->prev->next = N->next;
	N->next->prev = N->prev;
	delete N;
}

void LinkedList::AddAfter(Node * N, int key)
{
	Node* newN = new Node(key);
	if (N == tail) {
		PushBack(newN);
		return;
	}
	newN->next = N->next;
	N->next->prev = newN;
	newN->prev = N;
	N->next = newN;
}

void LinkedList::AddBefore(Node * N, int key)
{
	if (N == head) PushFront(new Node(key));
	else AddAfter(N->prev, key);
}

void LinkedList::dispaly() const
{
	if (head == nullptr) {
		std::cout << "Empty List\n";
	}
	else {
		Node* ptr = head;
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

LinkedList::~LinkedList() {}