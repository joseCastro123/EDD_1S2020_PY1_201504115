#include <iostream>
#include <string>
//#include "CirculadDoublyLinkedList.h"
//#include "Cola.h"
#include "Tree_ABB.h"
#include "Node_ABB.h"
#include "LinkedList_Personal.h"

using namespace std;

int main()
{
    Tree_ABB *arbol = new Tree_ABB();
    Node_ABB *raiz = NULL;
    arbol->insertNode(raiz,10);
    arbol->insertNode(raiz,5);
    arbol->insertNode(raiz,15);
    //arbol->insertNode(raiz,12);
    //arbol->insertNode(raiz,17);
    arbol->display_Tree(raiz,0);


    return 0;
}
