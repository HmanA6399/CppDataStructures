#pragma once

class Node
{
private:
	int key;
public:
	Node* next;
	Node* prev;
	Node(int key)
	{
		this->key = key;
		this->next = nullptr;
		this->prev = nullptr;
	};
	int getKey() const {
		return this->key;
	};
	~Node() {
		delete next;
		delete prev;
	};
};