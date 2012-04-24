#include "sled.h"
#include <cstdlib>
#include <iostream>

Sled::Sled(int w, int z, int a, int b, char* derp) 
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

Sled::~Sled() {

   
}

void Sled::imageChange(char* A)
{
image.load(A);

}

void Sled::imageChangeright(char *B)
{
image.load(B);

}

void Sled::resetState()
{
  rect.moveTo(10, 10);
}

QRect Sled::getRect()
{
  return rect;
}

void Sled::setRect(QRect rct)
{
  rect = rct;
}

QImage & Sled::getImage()
{
  return image;
}

bool Sled::isDestroyed()
{
  return destroyed;
}


void Sled::autoMove()
{
 
  getRect();

  if (rect.left() <= 2) {
   
    xdir = 20;
    
  }

  else if (rect.right() >= 698) {
    
    xdir =-20;

  }



  if (rect.top() <= 100) {
    
  }
  
  if (rect.bottom() == 400) {
    
  }


  rect.translate(xdir, ydir);
}
 
  



void Sled::setDestroyed(bool destr)
{
  destroyed = destr;
}

int Sled::getX()
{
  return x;
}
int Sled::getY()
{
  return y;
}
