 #ifndef MULTBOARD_H
 #define MULTBOARD_H

 #include <QBasicTimer>
 #include <QtGui>
 #include <QFrame>
 #include <QPointer>
 #include "gropaga.h"
 #include "inglip.h"
 #include "kitten.h"
 #include "buck.h"
#include "rain.h"
#include "sman.h"
#include "sball.h"
#include "sled.h"
#include "present.h"
#include "coin.h"
#include "tree.h"
#include "bush.h"



 class QLabel;

 class MultBoard : public QFrame
 {
     Q_OBJECT

 public:
     MultBoard(QWidget *parent = 0);
     MultBoard(QPainter& painter);
     QSize sizeHint() const;
     QSize minimumSizeHint() const;

 public slots:
     void start();
     void pause();

 signals:
     void scoreChanged(int score);
     void levelChanged(int level);
     void linesRemovedChanged(int numLines);

 protected:
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);
     void timerEvent(QTimerEvent *event);
    void checkCollision();

 private:
     enum { BoardWidth = 700, BoardHeight = 700 };

     int timeoutTime() { return 100 / (1 + level); }
     void clearBoard();
     QBasicTimer timer;
     bool isStarted;
     bool isPaused;
     int score;
     int level;
     
     int x;
     int timerId;
     Gropaga *gropaga;
     Inglip *inglip;
     Kitten *kittens[5];
     Buck *buck;
     Rain *rains[5];
     Sman *sman;
     Sball *sballs[10];
     Sled *sled[5];
     Present *present[3];
     Coin *coin[3];
     Tree *tree;
     Tree *bush;
    

 };

 #endif
