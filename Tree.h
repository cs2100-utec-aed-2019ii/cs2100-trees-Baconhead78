#ifndef TREE_H
#define TREE_H
#include "Node.h"

template <typename T>
class Tree{
	public:
		Node<T> * root;
		Tree(void):root(nullptr){}

};

#endif
