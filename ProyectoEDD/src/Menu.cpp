#include "Menu.h"

/*
Begin all clases for the game
*/

    #include "Read_File.h"//  for files
    #include "Arbol_Busqueda.h"
/*
End ALl class for the game
*/

#include <iostream>
#include <string>
//#include <string.h>
using namespace std;

Menu::Menu()
{
    //ctor
    new_Read_File = new Read_File();
    dicctionary = new CirculadDoublyLinkedList();
    board = new Sparse_Matrix();

    users = new Arbol_Busqueda();
    users->insertar("Jose");
    users->insertar("Roxana");
    users->insertar("Belinda");


    Token_Cola = new Cola();
    Token_Cola->addWord();

}

Menu::~Menu()
{
    //dtor
}
/**
    read all option in each switch
*/

void Menu::menu_initial(){
    int option =0;

    do{
        cout<<"\tChoose one option:\n\t1.Read File\n\t2.Insert User\n\t3.Play Game\n\t4.Reports\n\t5.Exit"<<endl;

        cout<<"\t";cin>>option;


        switch(option){
        case 1:
            system("clear");
            menu_File();
            system("clear");
        break;

        case 2:
            system("clear");
            menu_users();
            system("clear");

        break;

        case 3:
        break;

        case 4:
            system("clear");
            menu_Reports();
            system("clear");
        break;

        default:
        break;
    }

    }while(option!=5);


}

//method for read file
void Menu::menu_File(){

//poder leer or archivos que son

            string path ="";
            cout<<"Ingrese la direccion del archivo:\n";
            cin>>path;
            new_Read_File->readFile(path,dicctionary,board);


}


//method for insert users, delete users, and search users
void Menu::menu_users(){
    int option = 0;
    string name ="";

    do{

        cout<<"\tIngrese una opcion\n\t1.Insert Users\n\t2.Delete Users\n\t3.Exit\n";
        cout<<"\t";cin>>option;

        switch(option){
        case 1:
            system("clear");
            cout<<"\tName Users:\n";
            cout<<"\t";cin>>name;
            users->insertar(name);
            system("clear");
        break;
        case 2:
            system("clear");
            cout<<"\tName Users:\n";
            cout<<"\t";cin>>name;
            users->delete_Nodo(name);
            system("clear");
        break;
        case 3:

        break;
        default:
        break;
    }

    }while(option!=3);


}




void Menu::menu_Reports(){

        int option = 0;
    string name ="";

    do{

        cout<<"\tChoose one option\n\t1.Report Dicctionary\n\t2.Report Token\n\t3.Report Users\n";
        cout<<"\t4.Report Users PreOrden\n\t5.Report Users InOrden\n\t6.Report Users PostOrden\n";
        cout<<"\t7.Score Users\n\t8.ScoreBoard\n\t9.Sparse \n\t10.Exit\n";
        cout<<"\t";cin>>option;

        switch(option){
        case 1:
            //for Report Dictionary
            system("clear");
            dicctionary->graph_CircuDoble();
            system("clear");
        break;
        case 2:
            //Report Token
            system("clear");
            Token_Cola->graphCola();
            system("clear");
        break;
        case 3:
            //Report Users
            system("clear");
            users->graph_Nodo();
            system("clear");

        break;
        case 4:
            //Report Preorden
            system("clear");
            users->graph_preOrder();
            system("clear");
        break;
        case 5:
            //Report Inorden
            system("clear");
            users->display_InOrder();
            system("clear");
        break;
        case 6:
            ////Report Postorden
            system("clear");
            users->display_postOrder();
            system("clear");
        break;
        case 7:
            //Report Score User
            system("clear");
            users->display_postOrder();
            system("clear");

        break;
        case 8:
            //Report Scoreboard
        break;
        case 9:

            //Report  Sparse
        break;
        case 10:

        break;
        default:
        break;
    }

    }while(option!=10);




}













