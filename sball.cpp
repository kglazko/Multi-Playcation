#include "sball.h"
#include <cstdlib>
#include <iostream>

Sball::Sball(int w, int z, int a, int b, char* derp) 
{
  pic = derp;
  image.load(pic);
  destroyed = FALSE;
  resetState();
  rect = image.rect();
  rect.translate(w, z);
  xdir = a;
  ydir = b;
  x =w;
  y =z;
  
}

Sball::~Sball() {

   
}

void Sball::imageChange(char* A)
{
image.load(A);

}

void Sball::imageChangeright(char *B)
{
image.load(B);

}

void Sball::resetState()
{
  rect.moveTo(10, 10);
}

QRect Sball::getRect()
{
  return rect;
}

void Sball::setRect(QRect rct)
{
  rect = rct;
}

QImage & Sball::getImage()
{
  return image;
}

bool Sball::isDestroyed()
{
  return destroyed;
}


void Sball::autoMove(int x, int y)
{
  rect.translate(xdir,ydir);

  if (rect.left() <= 5) {
    xdir = x+5;
  }

  if (rect.right() >= 690) {
    xdir = -x-5;
  }

  if (rect.top() <= 20) {
    ydir =y+5;
  }

  if (rect.bottom() >= 695) {
    ydir = -y-5;
  }
}


void Sball::setDestroyed(bool destr)
{
  destroyed = destr;
}

int Sball::getX()
{
  return x;
}

int Sball::getY()
{
  return y;
}
