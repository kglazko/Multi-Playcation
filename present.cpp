#include "present.h"
#include "inglip.h"
#include <cstdlib>
#include <iostream>

Present::Present(int w, int z, int a, int b, char* derp) 
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

Present::~Present() {

   
}

void Present::imageChange(char* A)
{
image.load(A);

}

void Present::imageChangeright(char *B)
{
image.load(B);

}

void Present::resetState()
{
  rect.moveTo(10, 10);
}

QRect Present::getRect()
{
  return rect;
}

void Present::setRect(QRect rct)
{
  rect = rct;
}

QImage & Present::getImage()
{
  return image;
}

bool Present::isDestroyed()
{
  return destroyed;
}


void Present::autoMove(int x, int y)
{
  rect.translate(xdir,ydir);

  //if (rect.left() <= 5) {
   // xdir = x+5;
  //}

 // if (rect.right() >= 690) {
  //  xdir = -x-5;
 // }

  if (rect.top() <= 20) {
    ydir =y+5;
  }

  if (rect.bottom() >= 695) {
    rect.moveTo(0, 0);
  }
}


void Present::moveLeft(int left)
{
  if (rect.left() >= 2)
    rect.moveTo(left, rect.top());
}

void Present::moveRight(int right)
{
  if (rect.right() <= 690)
    rect.moveTo(right, rect.top());
}

  

 
  



void Present::setDestroyed(bool destr)
{
  destroyed = destr;
}

int Present::getX()
{
  return x;
}
int Present::getY()
{
  return y;
}
