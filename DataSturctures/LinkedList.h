#pragma once
#include"Node.h"

class LinkedList
{
private:
	Node *head, *tail;
public:
	LinkedList(Node* H = nullptr);
	void PushFront(Node*);
	Node* TopFront();
	void PopFront();
	void PushBack(Node* N);
	Node* TopBack();
	void PopBack();
	Node* Search(int) const;
	void Erase(Node*);
	void AddAfter(Node* N, int key);
	void AddBefore(Node* N, int key);
	void dispaly() const;
	~LinkedList();
};
