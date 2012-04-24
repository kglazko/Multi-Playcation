#ifndef COIN_H
#define COIN_H
#include <cstdlib>
#include <QImage>
#include <QRect>
#include <cstring>

class Coin
{

  public:
    Coin(int, int,int,int, char*);
    ~Coin();

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
