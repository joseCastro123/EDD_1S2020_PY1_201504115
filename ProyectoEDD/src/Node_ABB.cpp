#include "Node_ABB.h"
#include <iostream>
#include <string>
using namespace std;

Nodo_ABB::Nodo_ABB(string data1)
{
    //ctor
    data = data1;
    left = NULL;
    right = NULL;
}

Nodo_ABB::~Nodo_ABB()
{
    //dtor
}
//sets
void Nodo_ABB::setData(string data1)
{

data = data1;
}
void Nodo_ABB::setLeft(Nodo_ABB *left1)
{

    left = left1;
}

void Nodo_ABB::setRight(Nodo_ABB * right1)
{

    right = right1;
}

//gets
string Nodo_ABB::getData()
{
 return data;

}

Nodo_ABB * Nodo_ABB::getLeft()
{
 return left;
}

Nodo_ABB * Nodo_ABB::getRight()
{

return right;
}
