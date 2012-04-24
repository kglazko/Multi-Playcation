 #ifndef MULTWINDOW_H
 #define MULTWINDOW_H

 #include <QFrame>
 #include <QWidget>
 #include "multboard.h"

 class QLCDNumber;
 class QLabel;
 class QPushButton;

 class MultWindow;

 class MultWindow : public QWidget
 {
     Q_OBJECT

 public:
     MultWindow();

 private:
     QLabel *createLabel(const QString &text);

     MultBoard *board;
     QLabel *nextPieceLabel;
     QLCDNumber *scoreLcd;
     QLCDNumber *levelLcd;
     QLCDNumber *linesLcd;
     QPushButton *startButton;
     QPushButton *quitButton;
     QPushButton *pauseButton;
 };

 #endif
