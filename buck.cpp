#include "buck.h"
#include <iostream>


Buck::Buck(int x, int y)
{

 for (int i =0; i< 15; i++)
 {
  xdir = x;
 }
  ydir = y;

  image.load("hell.png"); 

  rect = image.rect();
  resetState();

}

Buck::~Buck() {
  
}



void Buck::autoMove()


{
  

  getRect();

  if (rect.left() <= 2) {
    image.load("airplane2.gif"); 
    xdir = 100;
    
  }

  else if (rect.right() >= 698) {
    image.load("airplane1.gif"); 
    xdir =-100;

  }



  if (rect.top() <= 100) {
    
  }
  
  if (rect.bottom() == 400) {
    
  }


  rect.translate(xdir, ydir);
}


void Buck :: followMove(int x, int y)
{
int revX, revY;
revX  = x-getRect().right();
revY =  y-getRect().bottom();

if (revX <= 0 && revY <=0)
{
for (int i =1; i>revX; --i)
{
rect.moveTo(revX-i, y-i);

}


}

else if (revX <= 0 && revY >=0)
{
for (int i =1; i>revX;--i)
{
rect.moveTo(revX-i, y+i);

}

}

else if (revX >= 0 && revY >=0)
{
for (int i =0; i<revX; i++)
{
rect.moveTo(revX+i, y+i);

}

}
else if (revX >= 0 && revY <=0)
{
for (int i =0; i<revX; i++)
{
rect.moveTo(revX+i, y-i);

}

}
 
}

void Buck::resetState() 
{
  rect.moveTo(620, 350);
}

void Buck::moveBottom(int bottom)
{
  rect.moveBottom(bottom);
}

void Buck::moveTop(int top)
{
  rect.moveTop(top);
}

void Buck::moveLeft(int left)
{
  rect.moveLeft(left);
}

void Buck::moveRight(int right)
{
  rect.moveRight(right);
}

void Buck::setXDir(int x)
{
  xdir = x;
}

void Buck::setYDir(int y)
{
  ydir = y;
}

int Buck::getXDir()
{
  return xdir;
}

int Buck::getYDir()
{
  return ydir;
}

QRect Buck::getRect()
{
  return rect;
}

QImage & Buck::getImage()
{
  return image;
}
