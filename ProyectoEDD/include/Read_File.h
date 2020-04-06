#ifndef READ_FILE_H
#define READ_FILE_H


#include <iostream>
#include <string>

//include header
#include "Sparse_Matrix.h";
#include "CirculadDoublyLinkedList.h"
using namespace std;

class Read_File
{
    public:
        Read_File();
        virtual ~Read_File();
        void readFile(string path,CirculadDoublyLinkedList*,Sparse_Matrix*);

    protected:

    private:
};

#endif // READ_FILE_H
