#ifndef NODE_SCORE_PERSONAL_H
#define NODE_SCORE_PERSONAL_H


class Node_Score_Personal
{
    public:
        Node_Score_Personal(int);
        virtual ~Node_Score_Personal();
        //sets
        void setPoints_Personal(int);
        void setNext_Score_P(Node_Score_Personal *);

        //gets
        int getPoints_Personal();
        Node_Score_Personal * getNext_Score_P();

    protected:

    private:
        int points;
        Node_Score_Personal *next_score_personal;
};

#endif // NODE_SCORE_PERSONAL_H
