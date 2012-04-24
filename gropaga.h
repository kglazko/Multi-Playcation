#ifndef GROPAGA_H
#define GROPAGA_H

#include <QImage>
#include <QRect>

class Gropaga
{

  public:
    Gropaga(int, int);
    ~Gropaga();

  public:
    void resetState();
    void moveBottom(int);
    void moveTop(int);
    void moveLeft(int);
    void moveRight(int);
    void autoMove();
    void followMove(int, int);
    void setXDir(int);
    void setYDir(int);
    int getXDir();
    int getYDir();
    QRect getRect();
    QImage & getImage();

  private:
    int angle;
    int speed;
    int xdir;
    int ydir;
    bool stuck;
    QImage image;
    QRect rect;

};

#endif
