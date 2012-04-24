#ifndef PRESENT_H
#define PRESENT_H
#include <cstdlib>
#include <QImage>
#include <QRect>
#include <cstring>

class Present
{

  public:
    Present(int, int,int,int, char*);
    ~Present();

  public:
    void resetState();
    void autoMove(int, int);
    bool isDestroyed();
    void setDestroyed(bool);
    void imageChange(char *);
    void imageChangeright(char *);
    QRect getRect();
    void setRect(QRect);
    QImage & getImage();
    int getX();
    int getY();
    void moveLeft(int);
    void moveRight(int);

  private:
    QImage image;
    QRect rect;
    int position;
    bool destroyed;
    int x;
    int y;
    int xdir;
    int ydir;
    char* pic;
};

#endif
