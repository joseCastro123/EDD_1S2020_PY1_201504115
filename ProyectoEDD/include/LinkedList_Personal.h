#ifndef LINKEDLIST_PERSONAL_H
#define LINKEDLIST_PERSONAL_H

#include "Node_Score_Personal.h"

#include <iostream>
#include <string>

using namespace std;
class LinkedList_Personal
{
    public:
        //meths
        bool is_Empty_scp();
        void insert_Front(int);
        void insert_middle(int);
        //void insert_end(int);
        void diplays_Data_scP();
        void delete_data_scP(int);

        LinkedList_Personal();
        virtual ~LinkedList_Personal();

    protected:

    private:
        Node_Score_Personal *header_score_p;
        Node_Score_Personal *tail_scrore_p;
};

#endif // LINKEDLIST_PERSONAL_H



