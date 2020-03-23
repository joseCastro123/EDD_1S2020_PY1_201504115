#include "Node_CD.h"


#include <iostream>
#include <string>

using namespace std;


Node_CD::Node_CD(string word)
{
    //ctor
    this->word = word;
    size_word =0;
    next = NULL;
    previous = NULL;
}

Node_CD::~Node_CD()
{
    //dtor
}


//sets
void Node_CD::setWord(string word1)
{

    this->word = word1;
}
void Node_CD::setSize_Word(int tam)
{

    size_word = tam;
}

void Node_CD::setPrevious(Node_CD *previous)
{

    this->previous = previous;
}

void Node_CD::setNext(Node_CD *next)
{

    this->next = next;
}

//gets
string Node_CD::getWord()
{

    return word;
}

int Node_CD::getSize_Word()
{

    return size_word;
}

Node_CD * Node_CD::getPrevious()
{

    return previous;
}

Node_CD * Node_CD::getNext()
{

    return next;
}














