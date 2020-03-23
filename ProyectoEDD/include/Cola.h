#ifndef COLA_H
#define COLA_H

#include "Node_Token.h"

#include <iostream>
#include <string>

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
        void push_Cola(int,char,int);
        void pop_Cola();
        void front_Cola();
        void display_Cola();

        virtual ~Cola();

    protected:

    private:
};

#endif // COLA_H
