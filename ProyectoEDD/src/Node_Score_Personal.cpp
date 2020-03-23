#include "Node_Score_Personal.h"

#include <iostream>
#include <string>

using namespace std;

Node_Score_Personal::Node_Score_Personal(int points1)
{

    this->points = points1;
    this->next_score_personal = NULL;
}

Node_Score_Personal::~Node_Score_Personal()
{
    //dtor
}

//begin sets
void Node_Score_Personal::setPoints_Personal(int point1)
{
    this->points = point1;
}

void Node_Score_Personal::setNext_Score_P(Node_Score_Personal *nex_score)
{
    this->next_score_personal = nex_score;

}


//begin gets
int Node_Score_Personal::getPoints_Personal()
{
    return points;
}

Node_Score_Personal * Node_Score_Personal::getNext_Score_P()
{
    return next_score_personal;
}



