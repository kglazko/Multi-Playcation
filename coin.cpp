#include "present.h"
#include "inglip.h"
#include <cstdlib>
#include <iostream>
#include "coin.h"

Coin::Coin(int w, int z, int a, int b, char* derp) 
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

Coin::~Coin() {

   
}

void Coin::imageChange(char* A)
{
image.load(A);

}

void Coin::imageChangeright(char *B)
{
image.load(B);

}

void Coin::resetState()
{
  rect.moveTo(10, 10);
}

QRect Coin::getRect()
{
  return rect;
}

void Coin::setRect(QRect rct)
{
  rect = rct;
}

QImage & Coin::getImage()
{
  return image;
}

bool Coin::isDestroyed()
{
  return destroyed;
}


void Coin::autoMove(int x, int y)
{
  
  

  if (rect.top() <= 20) {
    ydir =ydir+5;
  }

  if (rect.bottom() >= 695) {
    rect.moveTo(0, 0);
  }
  
rect.translate(xdir,ydir);
  
}


void Coin::moveLeft(int left)
{
  if (rect.left() >= 2)
    rect.moveTo(left, rect.top());
}

void Coin::moveRight(int right)
{
  if (rect.right() <= 690)
    rect.moveTo(right, rect.top());
}

  

 
  



void Coin::setDestroyed(bool destr)
{
  destroyed = destr;
}

int Coin::getX()
{
  return x;
}
int Coin::getY()
{
  return y;
}
