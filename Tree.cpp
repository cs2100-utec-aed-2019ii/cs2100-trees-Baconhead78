#include "Tree.h"


/*Se inserta de manera recursiva el nodo 
 * */

template <typename T>
void Tree<T>::insertNode(T key, Node<T>* node){
	if(key < node->key){
		if(node->left != nullptr)
			insert(key, node->left);
		else
			node->left=new Node<T>(key);
	}
	else if(key >= node->key){
		if(node->right != nullptr)
			insert(key, node->right);
		else
			node->right=new Node<T>(key);
	}
}

 
