#include "rain.h"
#include <cstdlib>
#include <iostream>

Rain::Rain(int w, int z, int a, int b, char* derp) 
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

Rain::~Rain() {

   
}

void Rain::imageChange(char* A)
{
image.load(A);

}

void Rain::imageChangeright(char *B)
{
image.load(B);

}

void Rain::resetState()
{
  rect.moveTo(10, 10);
}

QRect Rain::getRect()
{
  return rect;
}

void Rain::setRect(QRect rct)
{
  rect = rct;
}

QImage & Rain::getImage()
{
  return image;
}

bool Rain::isDestroyed()
{
  return destroyed;
}


void Rain::autoMove()
{
  rect.translate(xdir, ydir);

  if (rect.left() <= 5) {
    xdir = 1;
  }

  if (rect.right() >= 690) {
    xdir = -1;
  }

  if (rect.top() <= 100) {
    ydir = 2;
  }

  if (rect.bottom() >= 695) {
    rect.moveTo(rect.left(), 0);
  }
}


void Rain::setDestroyed(bool destr)
{
  destroyed = destr;
}

int Rain::getX()
{
  return x;
}

int Rain::getY()
{
  return y;
}
