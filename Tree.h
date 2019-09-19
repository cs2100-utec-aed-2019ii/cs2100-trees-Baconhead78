#ifndef TREE_H
#define TREE_H
#include "Node.h"

//binary search tree
template <typename T>
class Tree{
	private:
		Node<T> * root;
		void insertNode(T key);
		void destroyTree();
	public:
		Tree(void):root(nullptr){}
		void insertNode(T key, Node<T>* node);
		void deleteNode(Node<T>* node);
		void deleteTree(Node<T>* root);
		~Tree();
};

#endif
