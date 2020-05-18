#ifndef NODE_AUX_H
#define NODE_AUX_H

#include <iostream>
#include <string>
using namespace std;


class Node_Aux
{
    public:
        Node_Aux(string);
        virtual ~Node_Aux();

        //begin all methods
        void setWord(string);
        string getWord();

        void setNode_Next(Node_Aux *);
        Node_Aux *getNode_Next();



    protected:

    private:
        string word_tree;
        Node_Aux *next_Data;
};

#endif // NODE_AUX_H
