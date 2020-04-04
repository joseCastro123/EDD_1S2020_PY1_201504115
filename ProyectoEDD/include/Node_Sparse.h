/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node_Sparse.h
 * Author: dark
 *
 * Created on 29 de marzo de 2020, 20:37
 */

#ifndef NODE_SPARSE_H
#define NODE_SPARSE_H

//important
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Node_Sparse {
public:
    //Node_Sparse();
    Node_Sparse(int,int,string);
    Node_Sparse(int,int);
    Node_Sparse(const Node_Sparse& orig);
    virtual ~Node_Sparse();
    //Begin all
    //set and get pos_x
        void setPos_x(int);
        int getPos_x();

        //set and get pos_y
        void setPos_y(int);
        int getPos_y();

        //set and get Caracter
        void setCaracter(string);
        string getCaracter();
        //set and get Node_Left
        void setNode_S_Left(Node_Sparse *);
        Node_Sparse * getNode_S_Left();

        //set and get Node_Right
        void setNode_S_Right(Node_Sparse *);
        Node_Sparse * getNode_S_Right();

        //set and get Node_Up
        void setNode_S_Up(Node_Sparse *);
        Node_Sparse * getNode_S_Up();

        //set and get Node_Down
        void setNode_S_Down(Node_Sparse *);
        Node_Sparse * getNode_S_Down();
    
private:
        int pos_x;
        int pos_y;
        string caracter;
        Node_Sparse *right;
        Node_Sparse *left;
        Node_Sparse *up;
        Node_Sparse *down;

};

#endif /* NODE_SPARSE_H */

