#include <iostream>
#include <string>
//#include "CirculadDoublyLinkedList.h"
//#include "Cola.h"
#include "Tree_ABB.h"
#include "Node_ABB.h"
#include "LinkedList_Personal.h"
#include "Sparse_Matrix.h"

using namespace std;

int main()
{
   /*
    Tree_ABB *arbol = new Tree_ABB();
    Node_ABB *raiz = NULL;
    arbol->insertNode(raiz,10);
    arbol->insertNode(raiz,5);
    arbol->insertNode(raiz,15);
    //arbol->insertNode(raiz,12);
    //arbol->insertNode(raiz,17);
    arbol->display_Tree(raiz,0);
*/
 Sparse_Matrix *matrix = new Sparse_Matrix();
    //matrix->insert_Data(X,Y,Data);

   matrix->insert_Data(2,2,"A");
   matrix->insert_Data(4,2,"J");
   matrix->insert_Data(8,2,"O");

   matrix->insert_Data(4,4,"O");
   matrix->insert_Data(8,2,"E");
  // matrix->insert_Data(8,4,"S");



    //matrix->insert_Data(5
   matrix->display_headerHeader();
   matrix->display_headerLateral();
    cout<<"\n";
    matrix->display_Column_x();
    matrix->Display_Data();

   // cout<<"Mi valor es Eje Y: "<<matrix->getInicio()->getNode_S_Down()->getNode_S_Right()->getNode_S_Right()->getCaracter()<<endl;
    //cout<<"Mi valor es Eje X: "<<matrix->getInicio()->getNode_S_Right()->getNode_S_Down()->getNode_S_Right()->getCaracter()<<endl;
    //cout<<endl;
    cout<<endl;
    matrix->Imprimir();
    matrix->Graph_Data();
    system("dot -Tpng datos.dot -o output.png");
    system("eog output.png");


    return 0;
}
