/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Node_Sparse.cpp
 * Author: dark
 *
 * Created on 29 de marzo de 2020, 20:37
 */

#include "Node_Sparse.h"

//important
#include <iostream>
#include <string>
#include <string.h>
using namespace std;
/*
Node_Sparse::Node_Sparse() {
}
 */
//pase insertar Nodo con dato
Node_Sparse::Node_Sparse(int pos_x1,int pos_y1,string caracter1)
{
    //ctor
    pos_x = pos_x1;
    pos_y = pos_y1;
    caracter = caracter1;
    right = NULL;
    left = NULL;
    up = NULL;
    down = NULL;
}

//Para insertar cabeceras
Node_Sparse::Node_Sparse(int pos_x1,int pos_y1)
{
    //ctor
    pos_x = pos_x1;
    pos_y = pos_y1;
    if(pos_x == 0)
        caracter = "Y:"+to_string(pos_y);
    else
        caracter = "X:"+to_string(pos_x);
}


Node_Sparse::Node_Sparse(const Node_Sparse& orig) {
}

Node_Sparse::~Node_Sparse() {
}

//Begin all method for sparse matrix

//set and get pos_x
void Node_Sparse::setPos_x(int pos_x1)
{

    pos_x = pos_x1;
}

int Node_Sparse::getPos_x()
{
    return pos_x;
}

//set and get pos_y
void Node_Sparse::setPos_y(int pos_y1)
{

    pos_y = pos_y1;
}

int Node_Sparse::getPos_y()
{
    return pos_y;
}

//set and get Caracter
void Node_Sparse::setCaracter(string caracater1)
{

    caracter = caracater1;
}

string Node_Sparse:: getCaracter()
{
    return caracter;
}
//set and get Node_Left
void Node_Sparse::setNode_S_Left(Node_Sparse *left1)
{
    left =left1;
}

Node_Sparse * Node_Sparse::getNode_S_Left()
{
    return left;
}

//set and get Node_Right
void Node_Sparse::setNode_S_Right(Node_Sparse *rigth1)
{
    right = rigth1;
}
Node_Sparse * Node_Sparse::getNode_S_Right()
{

    return right;
}
//set and get Node_Up
void Node_Sparse::setNode_S_Up(Node_Sparse *up1)
{
    up = up1;
}
Node_Sparse * Node_Sparse::getNode_S_Up()
{
    return up;
}

//set and get Node_Down
void Node_Sparse::setNode_S_Down(Node_Sparse * down1)
{
    down = down1;
}

Node_Sparse * Node_Sparse::getNode_S_Down()
{
    return down;
}

