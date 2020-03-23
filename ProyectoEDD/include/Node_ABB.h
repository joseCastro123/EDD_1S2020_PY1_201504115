#ifndef NODE_ABB_H
#define NODE_ABB_H


#include <iostream>
#include <string>
#include "LinkedList_Personal.h"

using namespace std;


class Node_ABB
{
    public:
        Node_ABB();
        virtual ~Node_ABB();
        //Variables
        int data;
        Node_ABB *left_ABB;
        Node_ABB *right_ABB;
        //sets
            /*
            void setData(int);
            void setLeft_ABB(Node_ABB *);
            void setRight_ABB(Node_ABB *);
            */
        //gets

            /*
            int getData();

            Node_ABB * getLeft_ABB();
            Node_ABB * getRight_ABB();
            */

    protected:

    private:

};

#endif // NODE_ABB_H
