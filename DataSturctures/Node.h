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
	void setKey(T val) {
		this->key = val;
	};
	~Node() {
	//	delete next;
	//	delete prev;
	};
};