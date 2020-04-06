#include "CirculadDoublyLinkedList.h"

#include "Node_CD.h"
#include <fstream>//create file
#include <iostream>
#include <string>

using namespace std;


CirculadDoublyLinkedList::CirculadDoublyLinkedList()
{
    //ctor
    tamano=0;
    header_CircularDoubly_LL = NULL;
    tail_CircularDoubly_LL = NULL;

}

bool CirculadDoublyLinkedList::is_Empty()
{
    return header_CircularDoubly_LL == NULL;
}

void CirculadDoublyLinkedList::insert_front(string word1)
{
    tamano++;
    Node_CD *new_node_CDLL = new Node_CD(word1);
    new_node_CDLL->setSize_Word(tamano);

    if(is_Empty()){
        header_CircularDoubly_LL = new_node_CDLL;
        header_CircularDoubly_LL->setNext(header_CircularDoubly_LL);
        header_CircularDoubly_LL->setPrevious(header_CircularDoubly_LL);
        tail_CircularDoubly_LL = header_CircularDoubly_LL;


	}else{

        header_CircularDoubly_LL->setPrevious(new_node_CDLL);
        new_node_CDLL->setNext(header_CircularDoubly_LL);
        new_node_CDLL->setPrevious(tail_CircularDoubly_LL);
        tail_CircularDoubly_LL->setNext(new_node_CDLL);
        header_CircularDoubly_LL = new_node_CDLL;


	}


}//end methods insert_front

// begin methods insert middle
void CirculadDoublyLinkedList::insert_middle(string word1)
{
        int cont=1;
        tamano++;
        Node_CD *new_Node = new Node_CD(word1);
        new_Node->setSize_Word(tamano);
        if(is_Empty())
        {
            header_CircularDoubly_LL = new_Node;
            header_CircularDoubly_LL->setNext(header_CircularDoubly_LL);
            header_CircularDoubly_LL->setPrevious(header_CircularDoubly_LL);
            tail_CircularDoubly_LL = header_CircularDoubly_LL;

        }
        else
        {
            Node_CD *temp = header_CircularDoubly_LL;
            Node_CD *previous_temp;
            do
            {
                if(cont==5)
                {
                    previous_temp->setNext(new_Node);
                    temp->setPrevious(new_Node);
                    new_Node->setNext(temp);
                    new_Node->setPrevious(previous_temp);

                    break;
                }
                cont++;
                previous_temp = temp;
                temp = temp->getNext();
            }while(temp != header_CircularDoubly_LL);


        }
}//end insert middle

//begin insert end
void CirculadDoublyLinkedList::insert_end(string word1)
{
    tamano++;
    Node_CD *new_node_CDLL = new Node_CD(word1);
    new_node_CDLL->setSize_Word(tamano);

    if(is_Empty()){
		header_CircularDoubly_LL = new_node_CDLL;
        header_CircularDoubly_LL->setNext(header_CircularDoubly_LL);
		header_CircularDoubly_LL->setPrevious(header_CircularDoubly_LL);
		tail_CircularDoubly_LL = header_CircularDoubly_LL;
	}
	else
	{


        tail_CircularDoubly_LL->setNext(new_node_CDLL);
        new_node_CDLL->setNext(header_CircularDoubly_LL);
        new_node_CDLL->setPrevious(tail_CircularDoubly_LL);
        tail_CircularDoubly_LL = new_node_CDLL;
        header_CircularDoubly_LL->setPrevious(tail_CircularDoubly_LL);

	}
}//end methos insert end

//begin methods display data
void CirculadDoublyLinkedList::display_Data()
{
    Node_CD *temp = header_CircularDoubly_LL;
    if(header_CircularDoubly_LL != NULL)
    {

        do{
            cout<<temp->getWord()<<endl;
            temp = temp->getNext();

        }while(temp != header_CircularDoubly_LL);

    }
    else
    {
    cout<<"The list is empty@@@!!!";

    }


}//end methos display data

//beign methods delete data
void CirculadDoublyLinkedList::delete_Data(string word_delete)
{
    Node_CD *temp = header_CircularDoubly_LL;
    Node_CD *previous_temp;
    if(is_Empty()==false)
    {
        do
        {


            if(temp->getWord() == word_delete)
            {
                //cout<<temp->getWord()<<endl;
                //cout<<word_delete<<endl;
                if(temp == header_CircularDoubly_LL)
                {

                    header_CircularDoubly_LL = header_CircularDoubly_LL->getNext();
                    header_CircularDoubly_LL->setPrevious(tail_CircularDoubly_LL);
                    tail_CircularDoubly_LL->setNext(header_CircularDoubly_LL);

                    break;
                }
                else if(temp == tail_CircularDoubly_LL)
                {


                    /*
                    tail_CircularDoubly_LL = previous_temp;
                    tail_CircularDoubly_LL->setNext(header_CircularDoubly_LL);
                    header_CircularDoubly_LL->setPrevious(tail_CircularDoubly_LL);
                    */

                    //verificar
                    tail_CircularDoubly_LL = tail_CircularDoubly_LL->getPrevious();
                    cout<<tail_CircularDoubly_LL->getWord();
                    tail_CircularDoubly_LL->setNext(header_CircularDoubly_LL);
                    header_CircularDoubly_LL->setPrevious(tail_CircularDoubly_LL);

                    break;
                }
                else
                {

                    previous_temp->setNext(temp->getNext());
                    temp->getNext()->setPrevious(previous_temp);


                    break;
                }

            }


            previous_temp = temp;
            temp = temp->getNext();

        }while(temp != header_CircularDoubly_LL);


    }
    else
    {
    cout<<"the list is empty";

    }


}

//begin display data tail
void CirculadDoublyLinkedList::display_data_tail()
{
    Node_CD *temp = tail_CircularDoubly_LL;
    do
    {
        cout<<temp->getWord()<<endl;
        temp = temp->getPrevious();


    }while(temp != tail_CircularDoubly_LL);




}

void CirculadDoublyLinkedList::graph_CircuDoble()
{

string begin_info = "digraph R {\n\trankdir=TB\n\tnode [shape=box fontname=Arial];\n\tgraph[ nodesep = 0.5];\n";
string rank_begin = "{";
string rank_end = "}\n";
string begin_rank = "";
string order_Same = " ";

string end_info="}";
string info_label = "";
string info_rank = "";
string info_Matrix ="";

if(header_CircularDoubly_LL!= NULL){

    ofstream archivo;  // objeto de la clase ofstream

    archivo.open("Cir_Double.dot");

    //***************************************************************************************
    Node_CD *currentData = header_CircularDoubly_LL;//->getNode_S_Right();


            do {

                info_label = info_label +"\t"+currentData->getWord()+" [label=\""+currentData->getWord()+""+"\\l\""+"]\n";
                order_Same =order_Same +"\t"+ currentData->getWord()+"; ";


                info_Matrix = info_Matrix +"\t"+
                            currentData->getWord()+"->"+currentData->getNext()->getWord()+"[dir=both]\n";


                    currentData = currentData->getNext();
                }while(currentData!=header_CircularDoubly_LL);

            begin_rank =begin_rank+"{rank = same; " +order_Same+"}\n";
            //order_Same="";

    /************/


    archivo<<begin_info;
    archivo<<info_label+"\n\n";
    archivo<<"\t"+begin_rank+"\n\n";
    archivo<<info_Matrix+"\n\n";
    archivo<<end_info;
    archivo.close();

    system("dot -Tpng Cir_Double.dot -o Cir_Double.png");
    system("eog Cir_Double.png");
}else
{

cout<<"the doubly linked list is empty";

}






}


CirculadDoublyLinkedList::~CirculadDoublyLinkedList()
{
    //dtor
}
