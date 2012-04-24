#ifndef SMAN_H
#define SMAN_H

#include <QImage>
#include <QRect>

class Sman
{

  public:
    Sman(int, int);
    ~Sman();

  public:
    void resetState();
    void moveBottom(int);
    void moveTop(int);
    void moveLeft(int);
    void moveRight(int);
    void moveUp(int);
    void moveDown(int);
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
