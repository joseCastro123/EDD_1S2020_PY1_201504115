#include "Cola.h"
#include "Node_Token.h"

#include <iostream>
#include <string>

using namespace std;



Cola::Cola()
{
    header_Cola = NULL;
    tail_Cola = NULL;

    //ctor
}

Cola::~Cola()
{
    //dtor
}

bool Cola::is_Empty_Cola()
{
    return header_Cola == NULL;
}
void Cola::push_Cola(int point1,char caracter1,int number_token1)
{
    Node_Token *new_Node_Token = new Node_Token(point1,caracter1,number_token1);
    if(is_Empty_Cola())
    {
        header_Cola = new_Node_Token;
        header_Cola->setNext_Token(NULL);
        tail_Cola = header_Cola;

    }
    else
    {

        tail_Cola->setNext_Token(new_Node_Token);
        new_Node_Token->setNext_Token(NULL);
        tail_Cola = new_Node_Token;

    }

}


void Cola::pop_Cola()
{
    Node_Token *temp = header_Cola;
    if(header_Cola!= NULL)
    {
        header_Cola = header_Cola->getNext_Token();

    }
    else
    {
        cout<<"La Lista esta vacia!!!!";

    }



}

void Cola::front_Cola()
{
cout<<"Word_Front: "<<header_Cola->getCaracter();
}

void Cola::display_Cola()
{
    Node_Token *temp = header_Cola;
    if(header_Cola!= NULL)
    {
        while(temp != NULL)
        {
        cout<<temp->getCaracter()<<endl;
        temp = temp->getNext_Token();


        }

    }
    else
    {
        cout<<"La Lista esta vacia!!!!";

    }



}








