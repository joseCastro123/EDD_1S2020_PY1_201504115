#include "Cola.h"
#include "Node_Token.h"

#include <iostream>
#include <fstream>
#include <string>


#include <cstdlib>//for number ramdom

//for read file .json
#include <jsoncpp/json/json.h>

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

bool Cola::searchId(int value){
    Node_Token *currentNode = header_Cola;
    bool found = false;
    if(header_Cola!=NULL){

        while(currentNode!=NULL){
            if(currentNode->getId()==value){
                found = true;
                break;

            }

            currentNode = currentNode->getNext_Token();
        }


    }else{

    //cout<<"Not exist node token"<<endl;

    }

    return found;
}


void Cola::addWord(){
    int temp=0;
    ifstream ifs("Token.json");
    Json::Reader reader;
    Json::Value obj;
    reader.parse(ifs, obj);

    int random ;

    while(temp<obj["Token"].size()){
       random = rand()%obj["Token"].size()+1;

        if(searchId(random)==false)
        {
           // cout<<"Ramdom:"<<random<<" Word:"<<obj["Token"][temp]["character"].asString()<<endl;
            int point = obj["Token"][temp]["point"].asInt();
            string  character =obj["Token"][temp]["character"].asString();
            int tok =obj["Token"][temp]["Tokk"].asInt();

            push_Cola(random,point,character,tok);
            temp++;

        }

    }



}

void Cola::push_Cola(int id1,int point1,string caracter1,int number_token1)
{
    Node_Token *new_Node_Token = new Node_Token(id1,point1,caracter1,number_token1);

    if(is_Empty_Cola())
    {
        header_Cola = new_Node_Token;
        header_Cola->setNext_Token(NULL);
        tail_Cola = header_Cola;

    }
    else
    {

        if(new_Node_Token->getId()<header_Cola->getId()){
            insertCola_Front(new_Node_Token);

        }else if(new_Node_Token->getId()>tail_Cola->getId()){
            insertCola_End(new_Node_Token);
        }else{

            insertCola_Middle(new_Node_Token);
        }

    }

}

void Cola::insertCola_Front(Node_Token *newToken)
{
    newToken->setNext_Token(header_Cola);
    header_Cola = newToken;

}

void Cola::insertCola_Middle(Node_Token *newNode)
{
    Node_Token *currentData = header_Cola;
    Node_Token *temp_Previous;
    while(currentData!= NULL)
    {
       if(newNode->getId()<currentData->getId()){
            temp_Previous->setNext_Token(newNode);
            newNode->setNext_Token(currentData);
            break;
       }
    temp_Previous = currentData;
    currentData = currentData->getNext_Token();

    }

}

void Cola::insertCola_End(Node_Token *newNode)
{
    tail_Cola->setNext_Token(newNode);
    tail_Cola = newNode;


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



void Cola::graphCola(){

    string begin_info = "digraph Cola{\n\trankdir=TB\n\tnode [shape=box, fontname=Arial];\nedge [style=\"invis\",weight=0];\n";
    string rank_begin = "{";
    string rank_end = "}\n";
    string begin_rank = "";
    string order_Same = " ";

    string end_info="}";
    string info_label = "";
    string info_rank = "";
    string info_Matrix ="";

    if(header_Cola!= NULL){

        ofstream archivo;  // objeto de la clase ofstream

        archivo.open("Cola.dot");

    //***************************************************************************************
        Node_Token *currentData = header_Cola;//->getNode_S_Right();


                while(currentData!=NULL){

                    info_label = info_label +"\t"+currentData->getCaracter()+"[style=rounded,\tlabel=\""+currentData->getCaracter()+"x"+
                    to_string(currentData->getPoint())+"pts"+"\\l\""+"]\n";


                    order_Same =order_Same + currentData->getCaracter()+"; ";
                    begin_rank =begin_rank+"\t{rank = same; " +order_Same+"}\n";
                    order_Same = "";

                if(currentData->getNext_Token()!=NULL){


                        info_Matrix = info_Matrix +"\t"+
                        currentData->getCaracter()+"->"+currentData->getNext_Token()->getCaracter()+"\n";//+"[dir=none]\n";

                }

                    currentData = currentData->getNext_Token();
                }

           // begin_rank =begin_rank+"{rank = same; " +order_Same+"}\n";
            //order_Same="";

    /************/


    archivo<<begin_info;
    archivo<<info_label+"\n\n";
    archivo<<begin_rank+"\n\n";
    archivo<<info_Matrix+"\n\n";
    archivo<<end_info;
    archivo.close();

    system("dot -Tpng Cola.dot -o Cola.png");
    system("eog Cola.png");
}else
{

cout<<endl<<"the  Cola is empty";

}





}
