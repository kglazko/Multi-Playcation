#include "kitten.h"
#include <cstdlib>
#include <iostream>

Kitten::Kitten(int w, int z, int a, int b, char* derp) 
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

Kitten::~Kitten() {

   
}

void Kitten::imageChange(char* A)
{
image.load(A);

}

void Kitten::imageChangeright(char *B)
{
image.load(B);

}

void Kitten::resetState()
{
  rect.moveTo(10, 10);
}

QRect Kitten::getRect()
{
  return rect;
}

void Kitten::setRect(QRect rct)
{
  rect = rct;
}

QImage & Kitten::getImage()
{
  return image;
}

bool Kitten::isDestroyed()
{
  return destroyed;
}


void Kitten::autoMove()
{
  rect.translate(xdir, ydir);

  if (rect.left() <= 5) {
    xdir = 1;
  }

  if (rect.right() >= 690) {
    xdir = -1;
  }

  if (rect.top() <= 100) {
    ydir = 1;
  }

  if (rect.bottom() >= 695) {
    ydir = -1;
  }
}


void Kitten::setDestroyed(bool destr)
{
  destroyed = destr;
}

int Kitten::getX()
{
  return x;
}

int Kitten::getY()
{
  return y;
}


