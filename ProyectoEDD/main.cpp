#include <iostream>
#include <string>
using namespace std;
#include "CirculadDoublyLinkedList.h"
#include "Cola.h"
#include "Arbol_Busqueda.h"
#include "Node_ABB.h"
#include "LinkedList_Personal.h"
#include "Sparse_Matrix.h"
#include "Read_File.h"
//library for read file json
//investiguet About JsonCpp
#include <iostream>
#include <fstream>
#include <jsoncpp/json/json.h>

int main()
{
    Sparse_Matrix *matrix = new Sparse_Matrix();

    //ifstream ifs("profile.json");
    CirculadDoublyLinkedList *cdl = new CirculadDoublyLinkedList();
    Read_File *rf = new Read_File();
    rf->readFile("profile.json",cdl,matrix);
    cdl->display_Data();
    cdl->graph_CircuDoble();


    return 0;
}
