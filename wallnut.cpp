#include "wallnut.h"

wallnut::wallnut()
{
    hp=3000;
    setMovie(":/new/prefix1/WallNut.gif");
}
void wallnut::advance(int phase)
{
    if(!phase)
        return;

    if(hp<=0)
    {
        delete this;
        return;
    }
    else if(hp<1000)
    {
        setMovie(":/new/prefix1/WallNut2.gif");
        return;
    }
    else if(hp<2000)
    {
        setMovie(":/new/prefix1/WallNut1.gif");
        return;
    }
}
