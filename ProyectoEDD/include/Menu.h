#ifndef MENU_H
#define MENU_H

/*
Begin all clases for the game
*/

    #include "Read_File.h"//  for files
    #include "CirculadDoublyLinkedList.h"//for dicctionary
    #include "Sparse_Matrix.h" // for the table
    #include "Arbol_Busqueda.h" //for the users
    #include "Cola.h"

/*
End ALl class for the game
*/

#include <iostream>
#include <string>
#include <string.h>
using namespace std;


class Menu
{
    public:
        Menu();
        virtual ~Menu();
        //begin all the method for initial menu
        void menu_initial();
        void menu_File();
        void menu_users();
        void menu_Reports();

    protected:

    private:
        Read_File *new_Read_File;
        CirculadDoublyLinkedList *dicctionary;
        Sparse_Matrix *board;
        Arbol_Busqueda *users;
        Cola *Token_Cola;
};

#endif // MENU_H
