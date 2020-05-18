#ifndef NODO_ABB_H
#define NODO_ABB_H

//import class list score for each user
#include "LinkedList_Personal.h"

#include <iostream>
#include <string>
using namespace std;

class Nodo_ABB
{
    public:

        LinkedList_Personal *myScore;
        Nodo_ABB(string);
        virtual ~Nodo_ABB();
        //sets
        void setData(string);
        void setLeft(Nodo_ABB *);
        void setRight(Nodo_ABB *);


        //gets
        string getData();
        Nodo_ABB * getLeft();
        Nodo_ABB * getRight();

    protected:

    private:
        string data;
        Nodo_ABB *left;
        Nodo_ABB *right;


};

#endif // NODO_ABB_H
