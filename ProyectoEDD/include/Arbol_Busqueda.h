#ifndef ARBOL_BUSQUEDA_H
#define ARBOL_BUSQUEDA_H

//clases importadas
#include "Node_ABB.h"
#include "List_Tree.h"

#include <iostream>
#include <string>
using namespace std;

class Arbol_Busqueda
{
    public:

        Arbol_Busqueda();
        virtual ~Arbol_Busqueda();

        //method search
        bool search_Node(Nodo_ABB *,string);
        Nodo_ABB * search_user(string);
        Nodo_ABB * search_user(Nodo_ABB *,string);
        //method compare
        int getIndice_String(string);

        //method insert
        void insertar(string);
        Nodo_ABB * insertar(Nodo_ABB *,string);

        //method display Data
        void mostrarNodo(int);
        void display_Tree(Nodo_ABB *,int);

        //method preOrder
        void display_preOrder();
        void preOrden(Nodo_ABB *);
        //method inOrder
        void display_InOrder();
        void In_Order(Nodo_ABB*,List_Tree*);
        //method postOrder
        void display_postOrder();
        void Post_Order(Nodo_ABB*,List_Tree*);
        //method deleteNodo
        void delete_Nodo(string data);
        Nodo_ABB * delete_Root(Nodo_ABB *,string data);
        Nodo_ABB * replace_Node(Nodo_ABB *);
        //method graphviz data
        void graph_Nodo();
        string graph_Nodo(Nodo_ABB *,string &);
        //method graph preOrder
        void graph_preOrder();
        void graph_preOrder(Nodo_ABB *,List_Tree *);

    protected:

    private:
        Nodo_ABB *root;
};

#endif // ARBOL_BUSQUEDA_H
