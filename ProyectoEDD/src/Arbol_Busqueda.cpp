#include "Arbol_Busqueda.h"
//clases importadas
#include "Node_ABB.h"
#include "List_Tree.h"

#include <iostream>
#include <fstream>//for create file
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

Nodo_ABB * Arbol_Busqueda::search_user(string name){

    return search_user(root,name);
}

Nodo_ABB * Arbol_Busqueda::search_user(Nodo_ABB *raizSub,string buscado){

    if (raizSub == NULL)
        return NULL;
    else if (buscado == raizSub->getData())
        return raizSub;
    else if (getIndice_String(buscado)<getIndice_String(raizSub->getData()))
        return search_user(raizSub->getLeft(), buscado);
    else
        return search_user(raizSub->getRight(), buscado);

}

//end method seach
void Arbol_Busqueda::insertar(string dato1)
{
    bool found = search_Node(root,dato1);
    if(found == true){
        cout<<"\tUsuario ya existe"<<endl;
        cout << "\tPress enter to continue ...\n";
        cin.ignore();
        cin.get();
    }else{
        root = insertar(root,dato1);
    }
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



    if(arbol == NULL)
    {
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

    string begin_info = "digraph Tree{\n\trankdir=LR\n\tnode [shape=record, fontname=Arial];\n";
    string rank_begin = "{";
    string rank_end = "}\n";
    string begin_rank = "";
    string order_Same = " ";

    string end_info="}";
    string info_label = "";
    string info_rank = "";
    string info_Tree ="";
    List_Tree *list_tree = new List_Tree();


     ofstream archivo;  // objeto de la clase ofstream

    archivo.open("Tree_InOrder.dot");

    In_Order(root,list_tree);
    //In_Order(root);
    list_tree->displayNode(info_label,info_Tree);

    archivo<<begin_info;
    archivo<<begin_rank+"\n\n";

    archivo<<info_label+"\n\n";
    archivo<<info_Tree+"\n\n";
    archivo<<end_info;
    archivo.close();

    system("dot -Tpng Tree_InOrder.dot -o Tree_InOrder.png");
    system("eog Tree_InOrder.png");
    system("clear");


}

void Arbol_Busqueda::In_Order(Nodo_ABB *tree,List_Tree *list_tree)
{

    if(tree == NULL)
    {
        return;
    }
    else
    {
        In_Order(tree->getLeft(),list_tree);
       // cout<<tree->getData()<<"--->";
        list_tree->insertNode(tree->getData());
        In_Order(tree->getRight(),list_tree);

    }

}


void Arbol_Busqueda::display_postOrder()
{

    string begin_info = "digraph Tree{\n\trankdir=LR\n\tnode [shape=record, fontname=Arial];\n";
    string rank_begin = "{";
    string rank_end = "}\n";
    string begin_rank = "";
    string order_Same = " ";

    string end_info="}";
    string info_label = "";
    string info_rank = "";
    string info_Tree ="";
    List_Tree *list_tree = new List_Tree();


     ofstream archivo;  // objeto de la clase ofstream

    archivo.open("Tree_postOrder.dot");

   // In_Order(root,list_tree);
    Post_Order(root,list_tree);

    list_tree->displayNode(info_label,info_Tree);

    archivo<<begin_info;
    archivo<<begin_rank+"\n\n";

    archivo<<info_label+"\n\n";
    archivo<<info_Tree+"\n\n";
    archivo<<end_info;
    archivo.close();

    system("dot -Tpng Tree_postOrder.dot -o Tree_postOrder.png");
    system("eog Tree_postOrder.png");
    system("clear");


}

void Arbol_Busqueda::Post_Order(Nodo_ABB *tree,List_Tree *list_tree)
{

    if(tree == NULL)
    {
        return;
    }
    else
    {
        Post_Order(tree->getLeft(),list_tree);
        Post_Order(tree->getRight(),list_tree);
       // cout<<tree->getData()<<"--->";
        list_tree->insertNode(tree->getData());

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

string aux = "";
string Arbol_Busqueda::graph_Nodo(Nodo_ABB *arbol,string &label)
{
    if(arbol == NULL)
    {
        return "";
    }
    else
    {


        if(arbol->getRight()!=NULL && arbol->getLeft()!=NULL){

            label = "\t"+arbol->getData()+"[label=\"<"+arbol->getData()+"0>|"+"<"+arbol->getData()+"1>"+arbol->getData()+"|<"+arbol->getData()+"2>\"]\n"+label;

             graph_Nodo(arbol->getRight(),label);
             aux = "\t"+arbol->getData()+":<"+arbol->getData()+"0>->"+arbol->getLeft()->getData()+"\n"
                      +"\t"+arbol->getData()+":<"+arbol->getData()+"2>->"+arbol->getRight()->getData()+"\n"+aux;
            graph_Nodo(arbol->getLeft(),label);


        }else if(arbol->getRight()==NULL && arbol->getLeft()!=NULL){

            label = "\t"+arbol->getData()+"[label=\"<"+arbol->getData()+"0>|"+"<"+arbol->getData()+"1>"+arbol->getData()+"|<"+arbol->getData()+"2>\"]\n"+label;

            graph_Nodo(arbol->getRight(),label);
            aux = "\t"+arbol->getData()+":<"+arbol->getData()+"0>->"+arbol->getLeft()->getData()+"\n"+aux;
            graph_Nodo(arbol->getLeft(),label);

        }else if(arbol->getRight()!=NULL && arbol->getLeft()==NULL){

           label = "\t"+arbol->getData()+"[label=\"<"+arbol->getData()+"0>|"+"<"+arbol->getData()+"1>"+arbol->getData()+"|<"+arbol->getData()+"2>\"]\n"+label;

            graph_Nodo(arbol->getRight(),label);
            aux = "\t"+arbol->getData()+":<"+arbol->getData()+"2>->"+arbol->getRight()->getData()+"\n"+aux;
                      //+arbol->getData()+"->"+arbol->getLeft()->getData()+"\n";
            graph_Nodo(arbol->getLeft(),label);

        }else if(arbol->getRight()==NULL && arbol->getLeft()==NULL && arbol != NULL){
           // graph_Nodo(arbol->getRight());
            //aux = aux+"\t"+arbol->getData()+"\n";
            //graph_Nodo(arbol->getLeft());


            label = "\t"+arbol->getData()+"[label=\"<"+arbol->getData()+"0>|"+"<"+arbol->getData()+"1>"+arbol->getData()+"|<"+arbol->getData()+"2>\"]\n"+label;
            aux = "\t"+arbol->getData()+":<"+arbol->getData()+"2>"+"\n"+aux;

        }



        //graph_Nodo(arbol->getRight());
        //aux = aux+arbol->getData()+"\n";
        //graph_Nodo(arbol->getLeft());

    }


    return aux;
}
void Arbol_Busqueda::graph_Nodo(){
    string begin_info = "digraph Tree{\n\trankdir=TB\n\tnode [shape=record, fontname=Arial];\n";
    string rank_begin = "{";
    string rank_end = "}\n";
    string begin_rank = "";
    string order_Same = " ";

    string end_info="}";
    string info_label = "";
    string info_rank = "";
    string info_Tree ="";



     ofstream archivo;  // objeto de la clase ofstream

    archivo.open("Tree.dot");

    archivo<<begin_info;

    archivo<<begin_rank+"\n\n";
    archivo<<graph_Nodo(root,info_label)+"\n\n";
    archivo<<info_label+"\n\n";
    archivo<<end_info;
    archivo.close();

    system("dot -Tpng Tree.dot -o Tree.png");
    system("eog Tree.png");
    system("clear");

}



void Arbol_Busqueda::graph_preOrder()
{
    //preOrden(root);

    string begin_info = "digraph Tree{\n\trankdir=LR\n\tnode [shape=record, fontname=Arial];\n";
    string rank_begin = "{";
    string rank_end = "}\n";
    string begin_rank = "";
    string order_Same = " ";

    string end_info="}";
    string info_label = "";
    string info_rank = "";
    string info_Tree ="";
    List_Tree *list_tree = new List_Tree();


     ofstream archivo;  // objeto de la clase ofstream

    archivo.open("Tree_preOrder.dot");

    graph_preOrder(root,list_tree);
    list_tree->displayNode(info_label,info_Tree);

    archivo<<begin_info;
    archivo<<begin_rank+"\n\n";

    archivo<<info_label+"\n\n";
    archivo<<info_Tree+"\n\n";
    archivo<<end_info;
    archivo.close();

    system("dot -Tpng Tree_preOrder.dot -o Tree_preOrder.png");
    system("eog Tree_preOrder.png");
    system("clear");

}

void Arbol_Busqueda::graph_preOrder(Nodo_ABB *tree,List_Tree *list_tree)
{

    if(tree == NULL)
    {
        return;
    }
    else
    {
        //cout<<tree->getData()<<"->";
        list_tree->insertNode(tree->getData());
        graph_preOrder(tree->getLeft(),list_tree);
        graph_preOrder(tree->getRight(),list_tree);
    }

}


