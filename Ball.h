	#pragma once
	#include "Shape.h"

enum Dir{STOP=0,LEFT=1,UPLEFT=2,DOWNLEFT=3,RIGHT=4,UPRIGHT=5,DOWNRIGHT=6}
	
class Ball :public Shape
{
    private:
        int x,y;
        int originalX, originalY;
        Dir direction;
    public:
        Ball(int posX, int posY)
        {
            originalX=posX;
            originalY=posY;
            x=posX,y=posY;
            direction=STOP;
        }
        ~Ball();
    void Reset()
    {
        x=originalX;
        y=originalY;
        direction=STOP;
        
    }
    void chageDirection(Dir d)
    {
        direction=d;
    }
    
    int getX()const{return x;}
    int getY()const {return y;}
    Dir getDirection cost {return diredtion;}
    
    void Move()
    {
    switch (direction)
    case STOP:
        break;
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UPLEFT:
        x--;y--;
        break;
    case DOWNLEFT:
        x--;y++;
        break;
    case UPRIGHT:
        x++;y--;
        break;
    case DOWNRIGHT:
        x++;y++;
        break;
        default
        break;
        
        
    }

        //int speed() { return 0; }
        //void draw(int x, int y);
        //void collisionDetect(int xCo, int yCo) { }


	


};

