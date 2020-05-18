#ifndef LIST_TREE_H
#define LIST_TREE_H


#include "Node_Aux.h"
#include <iostream>
#include <string>
using namespace std;

class List_Tree
{
    public:
        List_Tree();
        virtual ~List_Tree();

        bool isEmpty();
        void insertNode(string);
        void displayNode(string&,string&);
        void delete_All();

    protected:

    private:
        Node_Aux *header_tree;
        Node_Aux *tail_tree;

};

#endif // LIST_TREE_H
