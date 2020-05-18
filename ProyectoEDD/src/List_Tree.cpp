#include "List_Tree.h"


#include <iostream>
#include <string>
using namespace std;

List_Tree::List_Tree()
{
    //ctor
    header_tree = NULL;
    tail_tree = NULL;
}

List_Tree::~List_Tree()
{
    //dtor
}


bool List_Tree::isEmpty(){

    return header_tree == NULL;
}

void List_Tree::insertNode(string word){

   Node_Aux *new_Node= new Node_Aux(word);

    if(isEmpty()==true){
        header_tree = new_Node;
        header_tree->setNode_Next(NULL);
        tail_tree = header_tree;

    }else{

        tail_tree->setNode_Next(new_Node);
        new_Node->setNode_Next(NULL);
        tail_tree = new_Node;
    }

}

void List_Tree::displayNode(string &label,string &info_Node){
    Node_Aux *aux= header_tree;

    while(aux!=NULL){
        //cout<<"Data: "<<aux->getWord()<<endl;
        if(aux->getNode_Next()!=NULL){
            label = label+"\t"+aux->getWord()+"[label=\""+aux->getWord()+"\"]\n";
            info_Node =info_Node +"\t"+aux->getWord()+"->"+aux->getNode_Next()->getWord()+"\n";
        }
        aux = aux->getNode_Next();

    }


}



void List_Tree::delete_All(){
    header_tree = NULL;
    tail_tree = NULL;


}







