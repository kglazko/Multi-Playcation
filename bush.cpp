#include "present.h"
#include "inglip.h"
#include <cstdlib>
#include <iostream>
#include "tree.h"
#include "bush.h"

Bush::Bush(int w, int z, int a, int b, char* derp) 


{
  pic = derp;
  image.load(pic);
  destroyed = FALSE;
  resetState();
  rect = image.rect();
  rect.translate(w, z);
 a = xdir;
 b = ydir;
  x =w;
  y =z;
  
}

Bush::~Bush(){

   
}

void Bush::imageChange(char* A)
{
image.load(A);

}
/*
void Bush::imageChangeright(char *B)
{
image.load(B);

}

void Bush::resetState()
{
  rect.moveTo(10, 10);
}

QRect Bush::getRect()
{
  return rect;
}

void Bush::setRect(QRect rct)
{
  rect = rct;
}

QImage & Bush::getImage()
{
  return image;
}

bool Bush::isDestroyed()
{
  return destroyed;
}


void Bush::autoMove(int x, int y)
{
  
  

  if (rect.top() <= 20) {
    ydir =ydir+5;
  }

  if (rect.bottom() >= 695) {
    rect.moveTo(0, 0);
  }
  
rect.translate(xdir,ydir);
  
}


void Bush::moveLeft(int left)
{
  if (rect.left() >= 2)
    rect.moveTo(left, rect.top());
}

void Bush::moveRight(int right)
{
  if (rect.right() <= 690)
    rect.moveTo(right, rect.top());
}

  

void Bush::setDestroyed(bool destr)
{
  destroyed = destr;
}

int Bush::getX()
{
  return x;
}
int Bush::getY()
{
  return y;
} */
