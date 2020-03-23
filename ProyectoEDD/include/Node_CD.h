#ifndef NODE_CD_H
#define NODE_CD_H

#include <iostream>
#include <string>

using namespace std;

class Node_CD
{
    public:
        Node_CD(string);
        virtual ~Node_CD();
        //sets
        void setWord(string);
        void setSize_Word(int);
        void setPrevious(Node_CD*);
        void setNext(Node_CD*);

        //gets
        string getWord();
        int getSize_Word();
        Node_CD *getPrevious();
        Node_CD *getNext();

    protected:

    private:
     int size_word;
     string word;
     Node_CD *next;
     Node_CD *previous;

};

#endif // NODE_CD_H
