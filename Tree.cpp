#include "Tree.h"

/*Se inserta de manera recursiva el nodo 
 * */

template <typename T>
void Tree<T>::insertNode(T key, Node<T>* node){
	if (node == nullptr){
		node = new Node<T>(key);
	}

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

template <typename T>
void Tree<T>::deleteNode(T key, Node<T>* root){
	if(key < root->key)
		deleteNode(key, root->left);
	else if(key > root->key)
		deleteNode(key, root->right);
	else
		delete root;
}

template <typename T>
int Tree<T>::calculateHeight(Node<T>* root){
	int left = calculateHeight(root->left);
	int right = calculateHeight(root->right);
	if(left > right)
		return left++;
	else
		return right++;
}

template <typename T>
void destroyTree(Node<T>* root){
	if(root != nullptr){
		destroyTree(root->left);
		destroyTree(root->right);
		delete root;
	}
}

template <typename T>
void inOrder(Node<T>* root){
	inOrder(root->left);
	std::cout << root->key << " ";
	inOrder(root->right);
}

template <typename T>
void preOrder(Node<T>* root){
	std::cout << root->key << " ";
	preOrder(root->left);
	preOrder(root->right);
}

template <typename T>
void postOrder(Node<T>* root){
	postOrder(root->left);
	postOrder(root->right);
	std::cout << root->key << " ";
}

template <typename T>
void nextNode(std::vector<Node<T>*> list, Node<T>* root, T value){
	// ver si la lista está vacia
	if(list.size() == 0){
		list.push_back(root);
		nextNode(list,root,value);
		return;
	}
	else{
		// ver si está en la lista
		for(auto i = 0; i < list.size(); ++i){
			if(list[i]->key == value){
				if(i == list.size()){
					std::cout << value << "es el último valor de ese nivel";
					return;
				}
				else{
					std::cout << list[i++]->key << std::endl;
					return;
				}
			}
		}
	}
	//Meter hijos 	
	std::vector<Node<T>*> newList;
	for(auto item:list){
		newList.push_back(item->left);
		newList.push_back(item->right);
	}
	list.clear();
	nextNode(newList, root, value);
}

template <typename T>
bool isComplete(std::vector<Node<T>*> list, bool hojas, Node<T>* root){
	if(list.size() == 0)
		list.push_back(root);

	std::vector<Node<T>*> new_list;
	for(auto item:list){
		if(item->left != nullptr && item->right != nullptr){
			new_list.push_back(item->left);
			new_list.push_back(item->right);
		}
		else if(item->right != nullptr)
			return false;
		else
			hojas = true;
	}

	return(isComplete(new_list,hojas,root) || false);
}


