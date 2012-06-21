#include "inglip.h"
#include <iostream>

Inglip::Inglip()
{
  xdir = 0;
  ydir = -1;
  image.load("imgs/CupcakeMoTransparent.gif");

  rect = image.rect();
  resetState();
}

Inglip::~Inglip()
{
 
}

void Inglip::moveLeft(int left)
{
  if (rect.left() >= 2)
    rect.moveTo(left, rect.top());
}

void Inglip::moveRight(int right)
{
  if (rect.right() <= 690)
    rect.moveTo(right, rect.top());
}

void Inglip::moveUp(int up)
{
  if (rect.top() >= 2)
    {
   
    rect.moveTo(rect.left(),up);
   }
}

void Inglip::moveDown(int down)
{
  if (rect.bottom() <= 690)
    rect.moveTo(rect.left(), down);
}

void Inglip::autoMove()
{
  rect.translate(xdir, ydir);

  if (rect.left() <= 0) {
    xdir = 2;
  }

  if (rect.right() >= 690) {
    xdir = -2;
  }

  if (rect.top() <= 100) {
    ydir = 2;
  }
 

  if (rect.top() >= 690) {
    ydir = -2;
  }
}

void Inglip::resetState()
{
  rect.moveTo(650, 550);
}

QRect Inglip::getRect()
{
  return rect;
}

QImage & Inglip::getImage()
{
  return image;
}

int Inglip::getXDir()
{
  return xdir;
}

int Inglip::getYDir()
{
  return ydir;
}

