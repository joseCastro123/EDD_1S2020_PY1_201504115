#ifndef TREE_ABB_H
#define TREE_ABB_H

#include "Node_ABB.h"

#include <iostream>
#include <string>


using namespace std;

class Tree_ABB
{
    public:
        Node_ABB *root_ABB;
        Node_ABB * crearNodo(int);
        bool is_Empty_ABB();

        void insertNode(Node_ABB *&,int);
        void display_Tree(Node_ABB *,int);

        Tree_ABB();
        virtual ~Tree_ABB();

    protected:

    private:
};

#endif // TREE_ABB_H
