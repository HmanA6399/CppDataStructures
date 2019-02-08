#pragma once

template <typename T>
class Node
{
private:
	T key;
public:
	Node* next;
	Node* prev;
	Node(T key)
	{
		this->key = key;
		this->next = nullptr;
		this->prev = nullptr;
	};
	T getKey() const {
		return T(this->key);
	};
	~Node() {
		delete next;
		delete prev;
	};
};