 #include <QtGui>

 #include <stdlib.h>

 #include "multwindow.h"

 int main(int argc, char *argv[])
 {
     QApplication app(argc, argv);
     MultWindow window;
 //#if defined(Q_OS_SYMBIAN)
    // window.showMaximized();
 //#else
     window.show();
//#endif
    // qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
     return app.exec();
 }
