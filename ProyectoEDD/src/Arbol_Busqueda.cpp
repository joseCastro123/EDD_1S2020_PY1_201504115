#include "Arbol_Busqueda.h"
//clases importadas
#include "Node_ABB.h"

#include <iostream>
#include <string>
using namespace std;

Arbol_Busqueda::Arbol_Busqueda()
{
    //ctor
    root = NULL;
}

Arbol_Busqueda::~Arbol_Busqueda()
{
    //dtor
}

int Arbol_Busqueda::getIndice_String(string pal_Inicio)
{
return tolower(pal_Inicio[0]);
}

/*
    Begin method seach

*/

bool Arbol_Busqueda::search_Node(Nodo_ABB *raizSub,string buscado)
{

    if (raizSub == NULL)
        return NULL;
    else if (buscado == raizSub->getData())
        return true;
    else if (getIndice_String(buscado)<getIndice_String(raizSub->getData()))
        return search_Node(raizSub->getLeft(), buscado);
    else
        return search_Node(raizSub->getRight(), buscado);

}



//end method seach
void Arbol_Busqueda::insertar(string dato1)
{
    bool found = search_Node(root,dato1);
    if(found == true)
        cout<<"Usuario ya existe"<<endl;
    else
        root = insertar(root,dato1);

}


Nodo_ABB * Arbol_Busqueda::insertar(Nodo_ABB *raizSub,string dato1)
{
    if(raizSub == NULL)
    {
        Nodo_ABB *new_Nodo= new Nodo_ABB(dato1);
        raizSub = new_Nodo;
        //return raizSub;

    }
    else
    {
        if(getIndice_String(dato1)<getIndice_String(raizSub->getData()))
        {

            //dato1 < raizSub->getData()

            Nodo_ABB *new_Izq = insertar(raizSub->getLeft(),dato1);
            raizSub->setLeft(new_Izq);
        }
        else if(getIndice_String(dato1)>getIndice_String(raizSub->getData()))
        {
            Nodo_ABB *new_Der = insertar(raizSub->getRight(),dato1);
            raizSub->setRight(new_Der);
        }
        else if(getIndice_String(dato1)==getIndice_String(raizSub->getData()))
        {
            cout<<"El Usuario Ya existe"<<endl;
        }

    }
    return raizSub;
}

void Arbol_Busqueda::mostrarNodo(int contador)
{

display_Tree(root,contador);
}



void Arbol_Busqueda::display_Tree(Nodo_ABB *arbol,int contador)
{

        //if(arbol !=NULL)cout<<"Dato primero es: "<<arbol->getData()<<endl;

    if(arbol == NULL)
    {
        //cout<<"Esta Vacio"<<endl;
        //numero++;
        return;
    }
    else
    {

        display_Tree(arbol->getRight(), contador+1);

        for(int i=0; i<contador; i++)
        cout<<"        ";
        cout<< arbol->getData()<<endl;
        display_Tree(arbol->getLeft(), contador+1);

    }
}



void Arbol_Busqueda::display_preOrder()
{
    preOrden(root);

}

void Arbol_Busqueda::preOrden(Nodo_ABB *tree)
{

    if(tree == NULL)
    {
        return;
    }
    else
    {
        cout<<tree->getData()<<"--->";
        preOrden(tree->getLeft());
        preOrden(tree->getRight());

    }

}


void Arbol_Busqueda::display_InOrder()
{
    In_Order(root);

}

void Arbol_Busqueda::In_Order(Nodo_ABB *tree)
{

    if(tree == NULL)
    {
        return;
    }
    else
    {
        In_Order(tree->getLeft());
        cout<<tree->getData()<<"--->";
        In_Order(tree->getRight());

    }

}


void Arbol_Busqueda::display_postOrder()
{
    Post_Order(root);

}

void Arbol_Busqueda::Post_Order(Nodo_ABB *tree)
{

    if(tree == NULL)
    {
        return;
    }
    else
    {
        Post_Order(tree->getLeft());
        Post_Order(tree->getRight());
        cout<<tree->getData()<<"--->";

    }
}


void Arbol_Busqueda::delete_Nodo(string data1)
{

    root = delete_Root(root,data1);
}

Nodo_ABB * Arbol_Busqueda::delete_Root(Nodo_ABB* raizSub,string data1)
{

    if (raizSub == NULL)
        throw "No se ha encontrado el nodo con la clave";
    else if (getIndice_String(data1)<getIndice_String(raizSub->getData()))
    {
        Nodo_ABB* iz;
        iz = delete_Root(raizSub->getLeft(), data1);
        raizSub->setLeft(iz);
    }
    else if (getIndice_String(data1)>getIndice_String(raizSub->getData()))
    {
        Nodo_ABB *dr;
        dr = delete_Root(raizSub->getRight(), data1);
        raizSub->setRight(dr);
    }
    else
// Nodo encontrado
    {
        Nodo_ABB *q;
        q = raizSub;
        // nodo a quitar del árbol
        if (q->getLeft() == NULL)
            raizSub = q->getRight();
        else if (q->getRight()== NULL)
            raizSub = q->getLeft();
        else
            q = replace_Node(q);

        q = NULL;
    }


return raizSub;
}

Nodo_ABB * Arbol_Busqueda::replace_Node(Nodo_ABB * current)
{

    Nodo_ABB *a, *p;
    p = current;
    a = current->getLeft();
    // rama de nodos menores
    while (a->getRight() != NULL)
    {
        p = a;
        a = a->getRight();
    }
    // copia en act el valor del nodo apuntado por a
    current->setData(a->getData());
    if (p == current) // a es el hijo izquierdo de act
    p->setLeft(a->getLeft()); // enlaza subarbol izquierdo. Fig. 16.32b
    else
    p->setRight(a->getLeft()); // se enlaza subarbol derecho. Fig. 16.32a
    return a;

}









