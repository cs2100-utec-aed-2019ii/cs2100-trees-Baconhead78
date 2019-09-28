#include "Tree.h"

int main()
{
	Tree<int>* arbol = new Tree<int>();
	arbol->root = nullptr;

	arbol->insertNode(10, arbol->root);
	std::cout << arbol->root;

	arbol->insertNode(15, arbol->root);
	arbol->insertNode(5, arbol->root);
	arbol->insertNode(4, arbol->root);
	arbol->insertNode(6, arbol->root);
	arbol->insertNode(8, arbol->root);

	arbol->inOrder(arbol->root);


	return 0;

}

