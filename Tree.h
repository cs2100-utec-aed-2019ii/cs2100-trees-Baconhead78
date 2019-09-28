#ifndef TREE_H
#define TREE_H
#include "Node.h"
#include <iostream>
#include <vector>

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
		void deleteNode(T key, Node<T>* root);
		void deleteTree(Node<T>* root);
		int calculateHeight(Node<T>* node);
		void inOrder(Node<T>* root);
		void preOrder(Node<T>* root);
		void postOrde(Node<T>* root);
		void nextNode(std::vector<Node<T>*> list, Node<T>* root, T value);
		bool isComplete(std::vector<Node<T>*> list, Node<T>* root);
		Node<T>* getRoot(){return (this->root);};
		~Tree();
};

#endif
