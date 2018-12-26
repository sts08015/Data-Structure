#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

typedef struct _point
{
    int xpos;
    int ypos;
}Point;

void SetPointPos(Point * ppos,int xpos,int ypos);
void ShowPointPos(Point * ppos);
int PointComp(Point * pos1,Point * pos2);


#endif // POINT_H_INCLUDED
