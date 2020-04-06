#ifndef CIRCULADDOUBLYLINKEDLIST_H
#define CIRCULADDOUBLYLINKEDLIST_H

#include "Node_CD.h"
#include <iostream>
#include <string>

using namespace std;


class CirculadDoublyLinkedList
{
    public:
        //var
        Node_CD *header_CircularDoubly_LL;
        Node_CD *tail_CircularDoubly_LL;
        int tamano;
        //methods
        void insert_front(string);
        void insert_middle(string);
        void insert_end(string);
        void display_Data();
        void display_data_tail();
        void delete_Data(string);
        void graph_CircuDoble();
        bool is_Empty();


        CirculadDoublyLinkedList();
        virtual ~CirculadDoublyLinkedList();

    protected:

    private:
};

#endif // CIRCULADDOUBLYLINKEDLIST_H
