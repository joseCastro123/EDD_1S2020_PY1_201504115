#ifndef NODE_TOKEN_H
#define NODE_TOKEN_H



#include <iostream>
#include <string>

using namespace std;


class Node_Token
{
    public:
        Node_Token(int,int,string,int);
        virtual ~Node_Token();
        //sets
        void setPoint(int);
        void setCaracter(string);
        void setNumber_Token(int);
        void setNext_Token(Node_Token *);
        void setId(int);
        //gets
        int getId();
        int getPoint();
        string getCaracter();
        int getNumber_Token();
        Node_Token * getNext_Token();


    protected:

    private:
        int id;
        int points;
        string caracter;
        int number_token;
        Node_Token *next_Token;
};

#endif // NODE_TOKEN_H
