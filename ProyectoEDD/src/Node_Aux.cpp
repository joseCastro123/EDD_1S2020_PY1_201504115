#include "Node_Aux.h"


#include <iostream>
#include <string>
using namespace std;

Node_Aux::Node_Aux(string word1)
{
    //ctor
    word_tree = word1;
    next_Data = NULL;
}

Node_Aux::~Node_Aux()
{
    //dtor
}


void Node_Aux::setWord(string word1){
    word_tree = word1;
}
string Node_Aux::getWord(){
    return word_tree;
}

void Node_Aux::setNode_Next(Node_Aux *next1){

next_Data = next1;
}
Node_Aux *Node_Aux::getNode_Next(){

return next_Data;
}
