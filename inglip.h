#ifndef INGLIP_H
#define INGLIP_H

#include <QImage>
#include <QRect>

class Inglip
{

  public:
    Inglip();
    ~Inglip();

  public:
    int getXDir();
    int getYDir();
    void resetState();
    void moveLeft(int);
    void moveRight(int);
    void moveUp(int);
    void moveDown(int);
    void autoMove();
    QRect getRect();
   
    QImage & getImage();

  private:
    QImage image;
    QRect rect;
     int xdir;
    int ydir;

};

#endif
