#include "sman.h"
#include <iostream>


Sman::Sman(int x, int y)
{

 
  xdir = x;

  ydir = y;

  image.load("imgs/sman.png"); 

  rect = image.rect();
  resetState();

}

Sman::~Sman() {
  
}


void Sman :: followMove(int x, int y)
{

 rect.translate(xdir,ydir);


  //if (rect.top() <= 20) {
  //  ydir =y+5;
 // }

//  if (rect.bottom() >= 695) {
 //   ydir = -y-5;
//  }



 
}

void Sman::resetState() 
{
  rect.moveTo(620, 350);
}

void Sman::moveBottom(int bottom)
{
  rect.moveBottom(bottom);
}

void Sman::moveTop(int top)
{
  rect.moveTop(top);
}

void Sman::moveLeft(int left)
{
  rect.moveLeft(left);
}

void Sman::moveRight(int right)
{
  rect.moveRight(right);
}

void Sman::setXDir(int x)
{
  xdir = x;
}

void Sman::setYDir(int y)
{
  ydir = y;
}

int Sman::getXDir()
{
  return xdir;
}

int Sman::getYDir()
{
  return ydir;
}

QRect Sman::getRect()
{
  return rect;
}

QImage & Sman::getImage()
{
  return image;
}


void Sman::moveUp(int up)
{
  if (rect.top() >= 2)
    {
   
    rect.moveTo(rect.left(),up);
   }
}

void Sman::moveDown(int down)
{
  if (rect.bottom() <= 690)
    rect.moveTo(rect.left(), down);
}
