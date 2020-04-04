/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sparse_Matrix.h
 * Author: dark
 *
 * Created on 29 de marzo de 2020, 20:42
 */

#ifndef SPARSE_MATRIX_H
#define SPARSE_MATRIX_H

#include <iostream>
#include <string>
#include <string.h>
using namespace std;
//import clases
#include "Node_Sparse.h"

class Sparse_Matrix {
public:
    Sparse_Matrix();
    Sparse_Matrix(const Sparse_Matrix& orig);
    virtual ~Sparse_Matrix();
    
    //BUuuuuuuuuu
    //begin all methos
        //verify header and lateras



        //begin method headers
        bool existHeaders(int);
        //Node_Sparse *Headers(int);
        void Headers(int);
        void display_headerHeader();

        //begin method lateral
        bool existLateral(int);
        //Node_Sparse *Lateral(int);
        void Lateral(int);
        void display_headerLateral();

        //begin methos insertarNode
        void insert_Data(int,int,string);
        void insert_Y(Node_Sparse *,int,int);
        void insert_X(Node_Sparse *,int,int);
        void display_Column_x(); 
        
        //begin display method
        void Display_Data();
        void Graph_Data();
        void Imprimir();
        Node_Sparse * getInicio();
private:
    Node_Sparse *begin_Matrix;

};

#endif /* SPARSE_MATRIX_H */

