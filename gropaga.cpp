#include "gropaga.h"
#include <iostream>


Gropaga::Gropaga(int x, int y)
{

 for (int i =0; i< 15; i++)
 {
  xdir = x;
 }
  ydir = y;

  image.load("airplane1.gif"); 

  rect = image.rect();
  resetState();

}

Gropaga::~Gropaga() {
  
}



void Gropaga::autoMove()


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


void Gropaga :: followMove(int x, int y)
{

xdir = x-5;
ydir=y;
rect.translate(xdir, ydir);


}

void Gropaga::resetState() 
{
  rect.moveTo(620, 350);
}

void Gropaga::moveBottom(int bottom)
{
  rect.moveBottom(bottom);
}

void Gropaga::moveTop(int top)
{
  rect.moveTop(top);
}

void Gropaga::moveLeft(int left)
{
  rect.moveLeft(left);
}

void Gropaga::moveRight(int right)
{
  rect.moveRight(right);
}

void Gropaga::setXDir(int x)
{
  xdir = x;
}

void Gropaga::setYDir(int y)
{
  ydir = y;
}

int Gropaga::getXDir()
{
  return xdir;
}

int Gropaga::getYDir()
{
  return ydir;
}

QRect Gropaga::getRect()
{
  return rect;
}

QImage & Gropaga::getImage()
{
  return image;
}

