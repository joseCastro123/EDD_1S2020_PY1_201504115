/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sparse_Matrix.cpp
 * Author: dark
 * 
 * Created on 29 de marzo de 2020, 20:42
 */

#include "Sparse_Matrix.h"

//para archivos
#include <fstream>//create file
#include <iostream>

#include <iostream>
#include <string>
#include <string.h>
using namespace std;
//import clases
#include "Node_Sparse.h"

Sparse_Matrix::Sparse_Matrix() {
    begin_Matrix= new Node_Sparse(0, 0, "M");
}

Sparse_Matrix::Sparse_Matrix(const Sparse_Matrix& orig) {
}

Sparse_Matrix::~Sparse_Matrix() {
}

//begin all method
Node_Sparse * Sparse_Matrix::getInicio()
{
    return begin_Matrix;
}
//methods headers
bool Sparse_Matrix::existHeaders(int x)
{
        Node_Sparse *aux;
        bool exist = false;
        for (aux = begin_Matrix; aux != NULL; aux = aux->getNode_S_Right()) {
            if (aux->getPos_x() == x) {
                exist = true;
                break;
            }
        }
        return exist;
}


void Sparse_Matrix::Headers(int x)
{

    if(begin_Matrix->getNode_S_Right()==NULL){
      Node_Sparse *temp = new Node_Sparse(x,0);

      begin_Matrix->setNode_S_Right(temp);
      temp->setNode_S_Left(begin_Matrix);

    }else{

      Node_Sparse *temp = begin_Matrix;

      while(temp->getNode_S_Right()!=NULL && temp->getNode_S_Right()->getPos_x()<x){
        temp = temp->getNode_S_Right();
      }
      if(temp->getNode_S_Right()==NULL){
        Node_Sparse *new_temp = new Node_Sparse(x,0);
        temp->setNode_S_Right(new_temp);
        new_temp->setNode_S_Left(temp);

      }else if(temp->getNode_S_Right()!=NULL && temp->getNode_S_Right()->getPos_x() !=x){
        Node_Sparse *new_temp = new Node_Sparse(x,0);
        Node_Sparse *der = temp->getNode_S_Right();


        temp->setNode_S_Right(new_temp);
        new_temp->setNode_S_Left(temp);
        new_temp->setNode_S_Right(der);
        der->setNode_S_Left(new_temp);
      }
    }
}

void Sparse_Matrix::display_headerHeader()
{

    Node_Sparse *temp = begin_Matrix;
    while(temp->getNode_S_Right()!=NULL){
      cout<<temp->getCaracter()<<"->";
      //cout<<"->";
      temp = temp->getNode_S_Right();
      }
    cout<<temp->getCaracter();
    cout<<"\n";

}


//begin method lateral
bool Sparse_Matrix::existLateral(int y)
{
        Node_Sparse *aux;
        bool exist = false;
        for (aux = begin_Matrix; aux != NULL; aux = aux->getNode_S_Down())
        {
            if (aux->getPos_y() == y)
            {
                exist = true;
                break;
            }
        }
        return exist;
}

void Sparse_Matrix::Lateral(int y)
{
    if (begin_Matrix->getNode_S_Down()==NULL){

      Node_Sparse *temp = new Node_Sparse(0,y);
      begin_Matrix->setNode_S_Down(temp);
      temp->setNode_S_Up(begin_Matrix) ;

    }else{
      Node_Sparse * temp = begin_Matrix;

      while(temp->getNode_S_Down()!=NULL && temp->getNode_S_Down()->getPos_y()<y){
        temp = temp->getNode_S_Down();
      }

      if(temp->getNode_S_Down()==NULL){
        Node_Sparse *new_temp = new Node_Sparse(0,y);
        temp->setNode_S_Down(new_temp);
        new_temp->setNode_S_Up(temp);
      }else if (temp->getNode_S_Down()!=NULL && temp->getNode_S_Down()->getPos_y() != y){
        Node_Sparse *new_temp = new Node_Sparse(0,y);
        Node_Sparse *down_ult = temp->getNode_S_Down();
        temp->setNode_S_Down(new_temp);
        new_temp->setNode_S_Up(temp);
        new_temp->setNode_S_Down(down_ult);
        down_ult->setNode_S_Up(new_temp);
      }
    }
}

void Sparse_Matrix::display_headerLateral()
{
    Node_Sparse *temp = begin_Matrix->getNode_S_Down();
    while(temp->getNode_S_Down()!=NULL){
      cout<<temp->getCaracter();
      cout<<"\n";
      cout<<"↓\n";
      temp = temp->getNode_S_Down();
      }
    cout<<temp->getCaracter();
    cout<<"\n";


}


//begin method insertNode
void Sparse_Matrix::insert_Data(int x,int y,string caracter)
{

    if (existLateral(y) == false && existHeaders(x) == false)
        {
            Headers(x);
            Lateral(y);

            Node_Sparse *new_Node = new Node_Sparse(x,y,caracter);
            insert_Y(new_Node,x,y);
            insert_X(new_Node,x,y);



        }
        else if (existLateral(y) == true && existHeaders(x) == false)
        {
            Headers(x);

            Node_Sparse *new_Node = new Node_Sparse(x,y,caracter);
            insert_Y(new_Node,x,y);
            insert_X(new_Node,x,y);

        }
        else if (existLateral(y) == false && existHeaders(x) == true)
        {

            Lateral(y);

            Node_Sparse *new_Node = new Node_Sparse(x,y,caracter);
            insert_Y(new_Node,x,y);
            insert_X(new_Node,x,y);

           
        }
        else if (existLateral(y) == true && existHeaders(x) == true)
        {

            Node_Sparse *new_Node = new Node_Sparse(x,y,caracter);
            insert_Y(new_Node,x,y);
            insert_X(new_Node,x,y);

           
        }





}


void Sparse_Matrix::insert_X(Node_Sparse *new_Node,int x,int y){
     
    Node_Sparse *temp = begin_Matrix;
    Node_Sparse *temp_Down;
    
    while(temp->getPos_x()!=x){
      temp = temp->getNode_S_Right();
    }
    
    if(temp->getNode_S_Down() ==NULL){
      temp->setNode_S_Down(new_Node);
      new_Node->setNode_S_Up(temp);
    }//aqui puedo borrar jajaa
    else
    {
       /**********************/  
       if (temp->getNode_S_Down()==NULL){

      //Node_Sparse *temp = new Node_Sparse(0,y);
      temp->setNode_S_Down(new_Node);
      new_Node->setNode_S_Up(temp) ;

    }else{
      temp_Down = temp;

      while(temp_Down->getNode_S_Down()!=NULL && temp_Down->getNode_S_Down()->getPos_y()<y){
        temp_Down = temp_Down->getNode_S_Down();
      }

      if(temp_Down->getNode_S_Down()==NULL){
        //Node_Sparse *new_temp = new Node_Sparse(0,y);
        temp_Down->setNode_S_Down(new_Node);
        new_Node->setNode_S_Up(temp_Down);
      }else if (temp_Down->getNode_S_Down()!=NULL && temp_Down->getNode_S_Down()->getPos_y() != y){
          
        Node_Sparse *down_ult = temp_Down->getNode_S_Down();
        temp_Down->setNode_S_Down(new_Node);
        new_Node->setNode_S_Up(temp_Down);
        new_Node->setNode_S_Down(down_ult);
        down_ult->setNode_S_Up(new_Node);
      }
    }
        
        /****************************/
    }//aqui tambien jajaaj
   
 }
    

void Sparse_Matrix::insert_Y(Node_Sparse *new_Node,int x,int y){
    Node_Sparse *temp = begin_Matrix;
    Node_Sparse *temp_Right;
    
    while(temp->getPos_y()!=y){
      temp = temp->getNode_S_Down();
    }
    
    if(temp->getNode_S_Right() ==NULL){
      temp->setNode_S_Right(new_Node);
      new_Node->setNode_S_Left(temp);
    }//aqui puedo borrar jajaa
    else
    {
     /*******************/
        if(temp->getNode_S_Right()==NULL){
      
      temp->setNode_S_Right(new_Node);
      new_Node->setNode_S_Left(temp);

    }else{

        temp_Right = temp;

      while(temp_Right->getNode_S_Right()!=NULL && temp_Right->getNode_S_Right()->getPos_x()<x){
        temp_Right = temp_Right->getNode_S_Right();
      }
      if(temp_Right->getNode_S_Right()==NULL){
        
        temp_Right->setNode_S_Right(new_Node);
        new_Node->setNode_S_Left(temp_Right);

      }else if(temp_Right->getNode_S_Right()!=NULL && temp_Right->getNode_S_Right()->getPos_x() !=x){
        
        Node_Sparse *der = temp_Right->getNode_S_Right();

        temp_Right->setNode_S_Right(new_Node);
        new_Node->setNode_S_Left(temp_Right);
        new_Node->setNode_S_Right(der);
        der->setNode_S_Left(new_Node);
      }
    }
     /******************/
    }//aqui tambien jajaaj
    
    }
//begin method display data
void Sparse_Matrix::display_Column_x()
{
    Node_Sparse *temp = begin_Matrix->getNode_S_Right();
    Node_Sparse *temp_down ;//= temp->getNode_S_Down();

    while(temp != NULL)
    {

        if(temp->getNode_S_Down()!=NULL)
        {
            temp_down = temp->getNode_S_Down();
             while(temp_down!= NULL)
            {
                cout<<temp_down->getCaracter()<<endl;
                temp_down = temp_down->getNode_S_Down();

            }
            cout<<"############"<<endl;

        }
       temp = temp->getNode_S_Right();


    }


}


//display method
void Sparse_Matrix::Display_Data()
{

    //  NodoMatriz ActualColumna = cabezaCabecera;
        Node_Sparse *current_Column = begin_Matrix->getNode_S_Right();
        Node_Sparse *current_Row = current_Column->getNode_S_Down();


        while (current_Column != nullptr)
        {

            while (current_Row != NULL)
            {


                cout<<"Dato: "<<current_Row->getCaracter()<<"  Fila: "<<current_Row->getPos_y()<<" Columna: "<<current_Row->getPos_x()<<endl;
                current_Row = current_Row->getNode_S_Right();
            }


            current_Column = current_Column->getNode_S_Down();
        }




}

void Sparse_Matrix::Graph_Data(){
string begin_info = "digraph R { \n rankdir=TB \n node [shape=box fontname=Arial];\n graph[ nodesep = 0.5];\n";
string rank_begin = "{";
string rank_end = "}\n";
string begin_rank = ""; 
string order_Same = " ";

string end_info="}";
string info_label = "";
string info_rank = "";
string info_Matrix ="";

if(begin_Matrix!= NULL){

    ofstream archivo;  // objeto de la clase ofstream

    archivo.open("datos.dot");
    
    Node_Sparse *ActualColumna = begin_Matrix;//->getNode_S_Right();

        while (ActualColumna != NULL) {
            Node_Sparse *ActualFila = ActualColumna;//->getNode_S_Down();

            while (ActualFila != NULL) {
                //order_Same =order_Same +" "+ to_string(ActualFila->getPos_x())+to_string(ActualFila->getPos_y())+"; ";
                ActualFila = ActualFila->getNode_S_Down();
            }
            
            //begin_rank =begin_rank+"{rank = same; " +order_Same+"}\n";
            //order_Same="";
            ActualColumna = ActualColumna->getNode_S_Right();
        }
    
    
    //***************************************************************************************
    Node_Sparse *ActualFila1 = begin_Matrix;//->getNode_S_Right();

        while (ActualFila1 != NULL) {
            Node_Sparse *ActualColumna1 = ActualFila1;//->getNode_S_Rigth();

            while (ActualColumna1 != NULL) {
                //System.out.println("Dato:" + ActualColumna1.Datos + " Fila " + ActualColumna1.x + " Columna " + ActualColumna1.y);
                info_label = info_label +to_string(ActualColumna1->getPos_x())+to_string(ActualColumna1->getPos_y()) +
                        " [label=\""+ActualColumna1->getCaracter()+"\\"+"l\",\tgroup="+to_string(ActualColumna1->getPos_x())+"]\n";
                order_Same =order_Same +"\t"+ to_string(ActualColumna1->getPos_x())+to_string(ActualColumna1->getPos_y())+"; ";

            if(ActualColumna1->getNode_S_Up()== NULL && ActualColumna1->getNode_S_Left()==NULL
                && ActualColumna1->getNode_S_Right()!= NULL &&ActualColumna1->getNode_S_Down()!=NULL)//not fineshe here
            {
     

            info_Matrix = info_Matrix +
                    to_string(ActualColumna1->getPos_x())+to_string(ActualColumna1->getPos_y())+"->"+
                    to_string(ActualColumna1->getNode_S_Right()->getPos_x())+to_string(ActualColumna1->getNode_S_Right()->getPos_y())+"[dir=both]\n"+
                    
                    to_string(ActualColumna1->getPos_x())+to_string(ActualColumna1->getPos_y())+"->"+
                    to_string(ActualColumna1->getNode_S_Down()->getPos_x())+to_string(ActualColumna1->getNode_S_Down()->getPos_y())+"[dir=both]\n";
                        
            }else if(ActualColumna1->getNode_S_Up()== NULL && ActualColumna1->getNode_S_Left()!=NULL
                && ActualColumna1->getNode_S_Right()!= NULL &&ActualColumna1->getNode_S_Down()!=NULL){
            
            info_Matrix = info_Matrix +
                    to_string(ActualColumna1->getPos_x())+to_string(ActualColumna1->getPos_y())+"->"+
                    to_string(ActualColumna1->getNode_S_Right()->getPos_x())+to_string(ActualColumna1->getNode_S_Right()->getPos_y())+"[dir=both]\n"+
                    
                    to_string(ActualColumna1->getPos_x())+to_string(ActualColumna1->getPos_y())+"->"+
                    to_string(ActualColumna1->getNode_S_Down()->getPos_x())+to_string(ActualColumna1->getNode_S_Down()->getPos_y())+"[dir=both]\n";//+
                    
                    //to_string(ActualColumna1->getPos_x())+to_string(ActualColumna1->getPos_y())+"->"+
                    //to_string(ActualColumna1->getNode_S_Left()->getPos_x())+to_string(ActualColumna1->getNode_S_Left()->getPos_y())+"[dir=both]\n"
                    //;
            
            
            }else if(ActualColumna1->getNode_S_Up()== NULL && ActualColumna1->getNode_S_Left()!=NULL
                && ActualColumna1->getNode_S_Right()== NULL && ActualColumna1->getNode_S_Down()!=NULL){
            
            info_Matrix = info_Matrix +
                    
                    to_string(ActualColumna1->getPos_x())+to_string(ActualColumna1->getPos_y())+"->"+
                    to_string(ActualColumna1->getNode_S_Down()->getPos_x())+to_string(ActualColumna1->getNode_S_Down()->getPos_y())+"[dir=both]\n";//+
                    
              //      to_string(ActualColumna1->getPos_x())+to_string(ActualColumna1->getPos_y())+"->"+
               //     to_string(ActualColumna1->getNode_S_Left()->getPos_x())+to_string(ActualColumna1->getNode_S_Left()->getPos_y())+"[dir=both]\n"
                 //   ;
            
            
            }else if(ActualColumna1->getNode_S_Up()!= NULL && ActualColumna1->getNode_S_Left()==NULL
                && ActualColumna1->getNode_S_Right()!= NULL && ActualColumna1->getNode_S_Down()==NULL){
            
            info_Matrix = info_Matrix +
                    
                    //to_string(ActualColumna1->getPos_x())+to_string(ActualColumna1->getPos_y())+"->"+
                    //to_string(ActualColumna1->getNode_S_Up()->getPos_x())+to_string(ActualColumna1->getNode_S_Up()->getPos_y())+"[dir=both]\n"+
                    
                    to_string(ActualColumna1->getPos_x())+to_string(ActualColumna1->getPos_y())+"->"+
                    to_string(ActualColumna1->getNode_S_Right()->getPos_x())+to_string(ActualColumna1->getNode_S_Right()->getPos_y())+"[dir=both]\n"
                    ;
            
            }else if(ActualColumna1->getNode_S_Up()!= NULL && ActualColumna1->getNode_S_Left()!=NULL
                && ActualColumna1->getNode_S_Right()!= NULL && ActualColumna1->getNode_S_Down()==NULL){
            
            info_Matrix = info_Matrix +
                    
                    //to_string(ActualColumna1->getPos_x())+to_string(ActualColumna1->getPos_y())+"->"+
                    //to_string(ActualColumna1->getNode_S_Up()->getPos_x())+to_string(ActualColumna1->getNode_S_Up()->getPos_y())+"[dir=both]\n"+
                    
                    to_string(ActualColumna1->getPos_x())+to_string(ActualColumna1->getPos_y())+"->"+
                    to_string(ActualColumna1->getNode_S_Right()->getPos_x())+to_string(ActualColumna1->getNode_S_Right()->getPos_y())+"[dir=both]\n";//+
             
                    //to_string(ActualColumna1->getPos_x())+to_string(ActualColumna1->getPos_y())+"->"+
                    //to_string(ActualColumna1->getNode_S_Left()->getPos_x())+to_string(ActualColumna1->getNode_S_Left()->getPos_y())+"[dir=both]\n"
                    //;
            
            }else if(ActualColumna1->getNode_S_Up()!= NULL && ActualColumna1->getNode_S_Left()!=NULL
                && ActualColumna1->getNode_S_Right()== NULL && ActualColumna1->getNode_S_Down()==NULL){
            
            //info_Matrix = info_Matrix +
                    
                    //to_string(ActualColumna1->getPos_x())+to_string(ActualColumna1->getPos_y())+"->"+
                    //to_string(ActualColumna1->getNode_S_Up()->getPos_x())+to_string(ActualColumna1->getNode_S_Up()->getPos_y())+"[dir=both]\n"+
                     
                    //to_string(ActualColumna1->getPos_x())+to_string(ActualColumna1->getPos_y())+"->"+
                    //to_string(ActualColumna1->getNode_S_Left()->getPos_x())+to_string(ActualColumna1->getNode_S_Left()->getPos_y())+"[dir=both]\n"
                    //;
            
            
            
            }else if(ActualColumna1->getNode_S_Up()!= NULL && ActualColumna1->getNode_S_Left()!=NULL
                && ActualColumna1->getNode_S_Right()!= NULL && ActualColumna1->getNode_S_Down()!=NULL){
            
            info_Matrix = info_Matrix +
                    
                    //to_string(ActualColumna1->getPos_x())+to_string(ActualColumna1->getPos_y())+"->"+
                    //to_string(ActualColumna1->getNode_S_Up()->getPos_x())+to_string(ActualColumna1->getNode_S_Up()->getPos_y())+"[dir=both]\n"+
                    
                    to_string(ActualColumna1->getPos_x())+to_string(ActualColumna1->getPos_y())+"->"+
                    to_string(ActualColumna1->getNode_S_Right()->getPos_x())+to_string(ActualColumna1->getNode_S_Right()->getPos_y())+"[dir=both]\n"+
                    
                    //to_string(ActualColumna1->getPos_x())+to_string(ActualColumna1->getPos_y())+"->"+
                    //to_string(ActualColumna1->getNode_S_Left()->getPos_x())+to_string(ActualColumna1->getNode_S_Left()->getPos_y())+"[dir=both]\n"+
                    
                    to_string(ActualColumna1->getPos_x())+to_string(ActualColumna1->getPos_y())+"->"+
                    to_string(ActualColumna1->getNode_S_Down()->getPos_x())+to_string(ActualColumna1->getNode_S_Down()->getPos_y())+"[dir=both]\n"
                    ;
            
            
            }else if(ActualColumna1->getNode_S_Up()!= NULL && ActualColumna1->getNode_S_Left()==NULL
                && ActualColumna1->getNode_S_Right()!= NULL && ActualColumna1->getNode_S_Down()!=NULL){
            
            info_Matrix = info_Matrix +
                    
                    //to_string(ActualColumna1->getPos_x())+to_string(ActualColumna1->getPos_y())+"->"+
                    //to_string(ActualColumna1->getNode_S_Up()->getPos_x())+to_string(ActualColumna1->getNode_S_Up()->getPos_y())+"[dir=both]\n"+
                    
                    to_string(ActualColumna1->getPos_x())+to_string(ActualColumna1->getPos_y())+"->"+
                    to_string(ActualColumna1->getNode_S_Right()->getPos_x())+to_string(ActualColumna1->getNode_S_Right()->getPos_y())+"[dir=both]\n"+
                    
                    //to_string(ActualColumna1->getPos_x())+to_string(ActualColumna1->getPos_y())+"->"+
                    //to_string(ActualColumna1->getNode_S_Left()->getPos_x())+to_string(ActualColumna1->getNode_S_Left()->getPos_y())+"[dir=both]\n"+
                    
                    to_string(ActualColumna1->getPos_x())+to_string(ActualColumna1->getPos_y())+"->"+
                    to_string(ActualColumna1->getNode_S_Down()->getPos_x())+to_string(ActualColumna1->getNode_S_Down()->getPos_y())+"[dir=both]\n"
                    ;
            
            
            
            }else if(ActualColumna1->getNode_S_Up()!= NULL && ActualColumna1->getNode_S_Left()!=NULL
                && ActualColumna1->getNode_S_Right()== NULL && ActualColumna1->getNode_S_Down()!=NULL){
            
            info_Matrix = info_Matrix +
                    
                    //to_string(ActualColumna1->getPos_x())+to_string(ActualColumna1->getPos_y())+"->"+
                    //to_string(ActualColumna1->getNode_S_Up()->getPos_x())+to_string(ActualColumna1->getNode_S_Up()->getPos_y())+"[dir=both]\n"+
                    
                    //to_string(ActualColumna1->getPos_x())+to_string(ActualColumna1->getPos_y())+"->"+
                    //to_string(ActualColumna1->getNode_S_Right()->getPos_x())+to_string(ActualColumna1->getNode_S_Right()->getPos_y())+"[dir=both]\n"+
                    
                    //to_string(ActualColumna1->getPos_x())+to_string(ActualColumna1->getPos_y())+"->"+
                    //to_string(ActualColumna1->getNode_S_Left()->getPos_x())+to_string(ActualColumna1->getNode_S_Left()->getPos_y())+"[dir=both]\n"+
                    
                    to_string(ActualColumna1->getPos_x())+to_string(ActualColumna1->getPos_y())+"->"+
                    to_string(ActualColumna1->getNode_S_Down()->getPos_x())+to_string(ActualColumna1->getNode_S_Down()->getPos_y())+"[dir=both]\n"
                    ;
            
            }
                
                
               cout<<"Dato:"<<ActualColumna1->getCaracter()<<" Fila "<<ActualColumna1->getPos_x()<<" Columna "<<ActualColumna1->getPos_y()<<endl;
                ActualColumna1 = ActualColumna1->getNode_S_Right();
            }//while actual columna
            begin_rank =begin_rank+"{rank = same; " +order_Same+"}\n";
            order_Same="";
            ActualFila1 = ActualFila1->getNode_S_Down();
        }
    
    
    /************/
    
    
    archivo<<begin_info;
    archivo<<info_label+"\n\n";
    archivo<<begin_rank+"\n\n";
    archivo<<info_Matrix+"\n\n";
    archivo<<end_info;
    archivo.close();
    cout<<"Archivo creado correctamente";
}else
{

cout<<"the doubly linked list is empty";

}
}



 void Sparse_Matrix::Imprimir() {
        Node_Sparse *ActualColumna = begin_Matrix;//->getNode_S_Right();

        while (ActualColumna != NULL) {
            Node_Sparse *ActualFila = ActualColumna->getNode_S_Down();

            while (ActualFila != NULL) {
                //System.out.println("Dato:" + ActualFila.Datos + " Fila " + ActualFila.x + " Columna " + ActualFila.y);
                cout<<"Dato:"<<ActualFila->getCaracter()<<" Fila "<<ActualFila->getPos_x()<<" Columna "<<ActualFila->getPos_y()<<endl;
                ActualFila = ActualFila->getNode_S_Down();
            }

            ActualColumna = ActualColumna->getNode_S_Right();
        }

    }
