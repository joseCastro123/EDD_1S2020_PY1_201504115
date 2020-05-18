#include "Read_File.h"

#include <iostream>
#include <string>
using namespace std;

//libreria para jsoon
#include <iostream>
#include <fstream>
#include <jsoncpp/json/json.h>


#include "Sparse_Matrix.h"
#include "CirculadDoublyLinkedList.h"
Read_File::Read_File()
{
    //ctor
}

Read_File::~Read_File()
{
    //dtor
}
void Read_File::readFile(string path,CirculadDoublyLinkedList *circ_DL,Sparse_Matrix *spar)
{
    ifstream ifs(path);
    Json::Reader reader;
    Json::Value obj;
    reader.parse(ifs, obj); // reader can also read strings
    //const Json::Value& characters = obj["casillas"]["dobles"]; // array of characters
    for (int i = 0; i <obj["diccionario"].size(); i++){
        cout << "Palabra: " << obj["diccionario"][i]["palabra"].asString()<<endl;
        circ_DL->insert_end(obj["diccionario"][i]["palabra"].asString());
        //cout << "Y: " << obj["casillas"]["dobles"][i]["y"].asUInt()<<endl;
        cout << endl;
    }
    cout<<"Datos cargado correctamente....\n";
/*
    const Json::Value& triple = obj["casillas"]["triples"]; // array of characters
    for (int i = 0; i <triple.size(); i++){
        cout << "X: " << triple[i]["x"].asString()<<endl;
        cout << "Y: " << triple[i]["y"].asUInt()<<endl;
        cout << endl;
    }

*/

}
