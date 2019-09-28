#include "Tree.h"

int main()
{
	Tree<int>* arbol = new Tree<int>();
	arbol->insertNode(10, arbol->getRoot());
	arbol->insertNode(15, arbol->getRoot());
	arbol->insertNode(5, arbol->getRoot());
	arbol->insertNode(4, arbol->getRoot());
	arbol->insertNode(6, arbol->getRoot());
	arbol->insertNode(8, arbol->getRoot());

	arbol->inOrder(arbol->getRoot());


}

