 #include <QtGui>


 #include "multwindow.h"

 MultWindow::MultWindow()
 {
     board = new MultBoard;

     nextPieceLabel = new QLabel;
     nextPieceLabel->setFrameStyle(QFrame::Box | QFrame::Raised);
     nextPieceLabel->setAlignment(Qt::AlignCenter);
     

     setStyleSheet("background-color: pink");
     scoreLcd = new QLCDNumber(3);
     scoreLcd->setSegmentStyle(QLCDNumber::Filled);
     levelLcd = new QLCDNumber(3);
     levelLcd->setSegmentStyle(QLCDNumber::Filled);


     startButton = new QPushButton(tr("&Start"));
     startButton->setFocusPolicy(Qt::NoFocus);
     quitButton = new QPushButton(tr("&Quit"));
     quitButton->setFocusPolicy(Qt::NoFocus);
     pauseButton = new QPushButton(tr("&Pause"));
     pauseButton->setFocusPolicy(Qt::NoFocus);

     connect(startButton, SIGNAL(clicked()), board, SLOT(start()));
     connect(quitButton , SIGNAL(clicked()), qApp, SLOT(quit()));
     connect(pauseButton, SIGNAL(clicked()), board, SLOT(pause()));
     connect(board, SIGNAL(scoreChanged(int)), scoreLcd, SLOT(display(int)));
     connect(board, SIGNAL(levelChanged(int)), levelLcd, SLOT(display(int)));
     

     QGridLayout *layout = new QGridLayout;
     
     layout->addWidget(createLabel(tr("LEVEL")), 0, 0);
     layout->addWidget(levelLcd, 1, 0);
     layout->addWidget(startButton, 4, 0);
     layout->addWidget(board, 0, 1, 6, 1);
     layout->addWidget(createLabel(tr("SCORE")), 0, 2);
     layout->addWidget(scoreLcd, 1, 2);
     layout->addWidget(quitButton, 4, 2);
     layout->addWidget(pauseButton, 5, 2);
     setLayout(layout);

      

     setWindowTitle(tr("Multi-Playcation"));
     resize(550, 370);
 }

 QLabel *MultWindow::createLabel(const QString &text)
 {
     QLabel *lbl = new QLabel(text);
     lbl->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
     return lbl;
 }
