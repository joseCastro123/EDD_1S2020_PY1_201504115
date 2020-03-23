#include "Tree_ABB.h"

#include <iostream>
#include <string>

using namespace std;

Tree_ABB::Tree_ABB()
{
    //ctor
    root_ABB = NULL;

}

Tree_ABB::~Tree_ABB()
{
    //dtor
}

bool Tree_ABB::is_Empty_ABB()
{

    return root_ABB == NULL;
}

Node_ABB * Tree_ABB::crearNodo(int dato1)
{
    Node_ABB *nuevoNodo = new Node_ABB();
    nuevoNodo->data = dato1;
    nuevoNodo->left_ABB = NULL;
    nuevoNodo->right_ABB = NULL;

    return nuevoNodo;

}
int contado = 0;
void Tree_ABB::insertNode(Node_ABB *& arbol,int data1)
{

    if(arbol==NULL)
    {
        contado++;
        cout<<"Entro en el if "<<contado<<endl;
        arbol = crearNodo(data1);
        cout<<"Dato: "<<arbol->data<<endl;

    }
    else
    {
            if(data1 < arbol->data)
            {
                cout<<"Entro en el izquierdo"<<endl;
                insertNode(arbol->left_ABB,data1);
            }
            else
            {

                cout<<"Entro en el DERECHO"<<endl;
                insertNode(arbol->right_ABB, data1);
            }

    }



}


void Tree_ABB::display_Tree(Node_ABB *arbol,int contador)
{
    if(arbol == NULL)
    {
        return;
    }
    else
    {
        display_Tree(arbol->right_ABB, contador+1);

        for(int i=0; i<contador; i++)
         cout<<"   ";

        cout<< arbol->data<<endl;

        display_Tree(arbol->left_ABB, contador+1);

    }

}
