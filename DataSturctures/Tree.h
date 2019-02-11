#pragma once
#include<iostream>
#include<algorithm>
#include "LLQueue.h"

template <typename T>
class Tree
{
public:
	T root;
	Tree *left, *right;

	Tree(T, Tree<T>* = nullptr, Tree<T>* = nullptr);
	bool isLeaf() const;
	int Height() const;
	int Size() const;
	void PreOrderPrint() const;
	void InOrderPrint() const;
	void PostOrderPrint() const;
	void BFS();
	~Tree();
};


template <typename T>
inline Tree<T>::Tree(T val, Tree<T>* l, Tree<T>* r)
{
	root = val;
	left = l;
	right = r;
}

template<typename T>
inline bool Tree<T>::isLeaf() const
{
	return (this->left == nullptr) && (this->right == nullptr);
}

template<typename T>
inline int Tree<T>::Height() const
{
	if (this->isLeaf()) return 1;
	else {
		int hl = (this->left != nullptr) ? left->Height() : 0,
			hr = (this->right != nullptr) ? right->Height() : 0;
		return  1 + ((hl >= hr) ? hl : hr);
	}
}

template<typename T>
inline int Tree<T>::Size() const
{
	if (this->isLeaf()) return 1;
	else {
		int tot = 1;
		if (this->left != nullptr) tot += left->Size();
		if (this->right != nullptr) tot += right->Size();
		return  tot;
	}
}

template<typename T>
inline void Tree<T>::PreOrderPrint() const
{
	if (this->isLeaf()) {
		std::cout << this->root << ' ';
		return;
	}
	else {
		std::cout << this->root << ' ';
		if (this->left != nullptr) this->left->PreOrderPrint();
		if (this->right != nullptr)this->right->PreOrderPrint();
	}
}

template<typename T>
inline void Tree<T>::InOrderPrint() const
{
	if (this->isLeaf()) {
		std::cout << this->root << ' ';
		return;
	}
	else {
		if (this->left != nullptr) left->InOrderPrint();
		std::cout << this->root << ' ';
		if (this->right != nullptr) right->InOrderPrint();
	}

}

template<typename T>
inline void Tree<T>::PostOrderPrint() const
{
	if (this->isLeaf()) {
		std::cout << this->root << ' ';
		return;
	}
	else {
		if (this->left != nullptr) this->left->PostOrderPrint();
		if (this->right != nullptr) this->right->PostOrderPrint();
		std::cout << this->root << ' ';
	}
}

template<typename T1>
inline void Tree<T1>::BFS()
{
	LLQueue<Tree*>* q = new LLQueue<Tree*>;
	q->Enqueue(this);
	while (!(q->isEmpty())) {
		Tree* t = q->Dequeue();
		std::cout << t->root << ' ';
		if (t->left != nullptr) q->Enqueue(t->left);
		if (t->right != nullptr) q->Enqueue(t->right);
	}
}

template <typename T>
inline Tree<T>::~Tree()
{
	delete left;
	delete right;
}
