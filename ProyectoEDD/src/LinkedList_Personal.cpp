#include "LinkedList_Personal.h"


#include <iostream>
#include <string>

using namespace std;


LinkedList_Personal::LinkedList_Personal()
{
    //ctor

    header_score_p = NULL;
    tail_scrore_p = NULL;

}

LinkedList_Personal::~LinkedList_Personal()
{
    //dtor
}

bool LinkedList_Personal::is_Empty_scp()
{
    return header_score_p == NULL;
}

void LinkedList_Personal::insert_Front(int point1)
{

    Node_Score_Personal *new_score_p = new Node_Score_Personal(point1);
    if(is_Empty_scp())
    {
        header_score_p = new_score_p;
        header_score_p->setNext_Score_P(NULL);
        tail_scrore_p = header_score_p;
    }
    else
    {

        Node_Score_Personal *temp_score = header_score_p;
        Node_Score_Personal *previous_scoreT;

        while(temp_score!= NULL && point1 < temp_score->getPoints_Personal())
        {
            cout<<"Entro con: "<<temp_score->getPoints_Personal()<<endl;
            previous_scoreT = temp_score;
            temp_score = temp_score->getNext_Score_P();
            //cout<<"Entro con: "<<temp_score->getPoints_Personal()<<endl;

        }

        if(temp_score == header_score_p)
        {
            new_score_p->setNext_Score_P(header_score_p);
            header_score_p =new_score_p;
        }
        else if(temp_score == tail_scrore_p)
        {
            tail_scrore_p->setNext_Score_P(new_score_p);
            tail_scrore_p = new_score_p;

        }
        else
        {
            previous_scoreT->setNext_Score_P(new_score_p);
            new_score_p->setNext_Score_P(temp_score);

        }

    }

}
//end inser front

void LinkedList_Personal::delete_data_scP(int value_point)
{
        Node_Score_Personal *temp_score = header_score_p;
        Node_Score_Personal *previous_scoreT;

        if(header_score_p != NULL)
        {

            while(temp_score!= NULL)
            {

                if(temp_score->getPoints_Personal()== value_point)
                {
                    if(temp_score == header_score_p)
                    {

                        header_score_p = header_score_p->getNext_Score_P();
                    }
                    else if(temp_score == tail_scrore_p)
                    {
                        tail_scrore_p = previous_scoreT;

                    }
                    else
                    {
                       previous_scoreT->setNext_Score_P(temp_score->getNext_Score_P());
                    }

                }

                previous_scoreT = temp_score;
                temp_score = temp_score->getNext_Score_P();
            }

        }
        else
        {
            cout<<"the list is empty";
        }

}
void LinkedList_Personal::diplays_Data_scP()
{
    Node_Score_Personal *temp_scoP = header_score_p;
    if(header_score_p != NULL)
    {
        while(temp_scoP != NULL)
        {
            cout<<temp_scoP->getPoints_Personal()<<"-->";;
            temp_scoP = temp_scoP->getNext_Score_P();

        }
        cout<<endl;


    }
    else
    {
        cout<<"Is empty";

    }


}


void LinkedList_Personal::insert_middle(int points1)
{

}






