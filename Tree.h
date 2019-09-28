#ifndef TREE_H
#define TREE_H
#include "Node.h"
#include <iostream>
#include <vector>

//binary search tree
template <typename T>
class Tree{
	public:
		Node<T>* root = nullptr;
		Tree(): root(NULL) {}

		void insertNode(T key, Node<T>* node){
			if (node == nullptr){
				node = new Node<T>(key);
			}

			if(key < node->key){
				if(node->left != nullptr)
					insertNode(key, node->left);
				else
					node->left=new Node<T>(key);
			}
			else if(key >= node->key){
				if(node->right != nullptr)
					insertNode(key, node->right);
				else
					node->right=new Node<T>(key);
			}
		};

		Node<T>* deleteNode(T key, Node<T>* root){
			if(key > root->key)
				root->left = deleteNode(key, root->left);
			else if(key < root->key)
				root->right = deleteNode(key, root->right);
			else{
				if(root->left == nullptr){
					auto temp = root->right;
					delete root;
					return temp;
				}
				else if(root->right == nullptr){
					auto temp = root->left;
					delete root;
					return temp;
				}
				else{
					auto temp = minValueNode(root->right);
					root->key = temp->key;
					root->right = deleteNode(temp->key, root->righti);
				}
			}
			return root;
		};

		void deleteTree(Node<T>* root){
			if(root != nullptr){
				destroyTree(root->left);
				destroyTree(root->right);
				delete root;
			}
		};

		int calculateHeight(Node<T>* node){
			int left = calculateHeight(root->left);
			int right = calculateHeight(root->right);
			if(left > right)
				return left++;
			else
				return right++;
		};

		void inOrder(Node<T>* root){
			inOrder(root->left);
			std::cout << root->key << " ";
			inOrder(root->right);
		};

		void preOrder(Node<T>* root){
			std::cout << root->key << " ";
			preOrder(root->left);
			preOrder(root->right);
		};

		void postOrder(Node<T>* root){
			postOrder(root->left);
			postOrder(root->right);
			std::cout << root->key << " ";
		};

		void inOrderList(Node<T>* root, std::vector<T> list){
			inOrderList(root->left);
			list.push_back(root->key);
			inOrderList(root->right);
		};


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
		};

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
		};

		bool equal(Node<T>* root1, Node<T>* root2){
			std::vector<T> arbol1;
			std::vector<T> arbol2;

			inOrderList(root1,arbol1);
			inOrderList(root2,arbol2);

			for(auto i=0; i<arbol1.size(); i++){
				if(arbol1[i] != arbol2[i])
					return false;
			}

			return true;
		};


};

#endif
