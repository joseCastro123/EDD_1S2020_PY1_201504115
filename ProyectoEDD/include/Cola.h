#ifndef COLA_H
#define COLA_H

#include "Node_Token.h"

#include <iostream>
#include <string>

#include <cstdlib>//for number ramdom

//for read file .json
#include <iostream>
#include <fstream>
#include <jsoncpp/json/json.h>

#include <locale.h>

using namespace std;

class Cola
{
    public:
        Node_Token *header_Cola;
        Node_Token *tail_Cola;
        Cola();

        //methods sets
        /*
        Crear: se crea la cola vacía.
        Encolar (añadir, entrar, push):
        Desencolar (sacar, salir, pop):
        Frente
        */
        bool is_Empty_Cola();
        void push_Cola(int,int,string,int);
        void insertCola_Front(Node_Token *);
        void insertCola_Middle(Node_Token *);
        void insertCola_End(Node_Token *);
        void pop_Cola();
        bool searchId(int);
        void addWord();
        void graphCola();
        void front_Cola();
        void display_Cola();

        virtual ~Cola();

    protected:

    private:
};

#endif // COLA_H
