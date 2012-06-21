 #include <QtGui>

 #include "multboard.h"
#include <QPainter>
#include <QApplication>
#include <QMainWindow>

#include <QLCDNumber>
#include <QTimer>
#include <QTime>

bool levelUp;
bool gTest = FALSE;

int anti_hard = 0;


 MultBoard::MultBoard(QWidget *parent)
     : QFrame(parent)
 {

     setStyleSheet("QWidget { background-image: url(imgs/background0.gif); }");
     setFrameStyle(QFrame::Panel | QFrame::Sunken);
     setFocusPolicy(Qt::StrongFocus);
     isStarted = false;
     isPaused = false;
    
      //Declaration of all types/variables
      inglip = new Inglip();
      
      gropaga = new Gropaga(1,1);
    
     
      buck = new Buck(1,1);
    
      
      sman = new Sman (0,1);
   
      kittens[0] = new Kitten(30,170, 1, -1, "imgs/heart1.png");
      kittens[1]= new Kitten (400, 60, -1, 1, "imgs/heart2.png");
      kittens[2]= new Kitten (120, 440, 1, -1, "imgs/heart3.png");
      kittens[3]= new Kitten (300, 300, -1, -1, "imgs/heart4.png");
      kittens[4]= new Kitten (200, 200, 1, 1, "imgs/heart5.png");
     rains[0] = new Rain(30,170, 0, 1, "imgs/kite1.gif");
      rains[1]= new Rain (400, 60, 0, 1, "imgs/kite2.gif");
      rains[2]= new Rain (120, 440, 0, 1, "imgs/kite3.gif");
      rains[3]= new Rain (300, 300, 0, 1, "imgs/kite4.gif");
      rains[4]= new Rain (200, 200, 0, 1, "imgs/kite5.gif");

      sballs[0] = new Sball(30,170, 1, 1, "imgs/ball.png");
      sballs[1]= new Sball (400, 60, 1, 1, "imgs/ball.png");
      sballs[2]= new Sball (120, 440, 1, 1, "imgs/ball.png");
      sballs[3]= new Sball (300, 300, 1, 1, "imgs/ball.png");
      sballs[4]= new Sball (200, 200, 1, 1, "imgs/ball.png");
      sballs[5] = new Sball(30,170, 1, 1, "imgs/ball.png");
      sballs[6]= new Sball (460, 60, 1, 1, "imgs/ball.png");
      sballs[7]= new Sball (190, 440, 1, 1, "imgs/ball.png");
      sballs[8]= new Sball (350, 300, 1, 1, "imgs/ball.png");
      sballs[9]= new Sball (230, 200, 1, 1, "imgs/ball.png");

     sled[0] = new Sled(30,170, 1, 0, "imgs/sled1.png");
      sled[1]= new Sled (460, 60, 1, 0, "imgs/sled2.png");
      sled[2]=new Sled (190, 440, 1, 0, "imgs/sled3.png");
      sled[3]= new Sled (350, 300, 1, 0, "imgs/sled4.png");
      sled[4]= new Sled (230, 200, 1, 0, "imgs/sled5.png");
    

    present[0] = new Present(1,0,0,1, "imgs/present.png");
    present[1] = new Present(1,0,0,1, "imgs/present.png");
    present[2] = new Present(1,0,0,1, "imgs/present.png");


    coin[0] = new Coin(1,0,0,1, "imgs/coin.gif");
    coin[1] = new Coin(1,0,0,1, "imgs/coin.gif");
    coin[2] = new Coin(1,0,0,1, "imgs/coin.gif");

    tree = new Tree (20, 550, 0, 0,"imgs/tree.gif"); 
    
  bush = new Tree (550, 570, 0, 0, "imgs/bush.png");
    

    
     
 }


// Size of playing board
 QSize MultBoard::sizeHint() const
 {
     return QSize(BoardWidth * 15 + frameWidth() * 2,
                 BoardHeight * 15 + frameWidth() * 2);
 }

 QSize MultBoard::minimumSizeHint() const
 {
     return QSize(BoardWidth * 1 + frameWidth() * 1,
                  BoardHeight * 1 + frameWidth() * 1);
 }

 void MultBoard::start()
 {
    

     isStarted = true;
  
     score = 0;
     level = 1;
     

     
     emit scoreChanged(score);
     emit levelChanged(level);

   
     timer.start(timeoutTime(), this);
 }

void MultBoard::pause()
{
   if (!isStarted)
        return;

     isPaused = !isPaused;
    if (isPaused) {
       timer.stop();
   } else {
        timer.start(timeoutTime(), this);
    }
     update();
 }

 void MultBoard::paintEvent(QPaintEvent *event)
 {

    
     QFrame::paintEvent(event);

     QPainter painter(this);
     QRect rect = contentsRect();

     if (isPaused) {
         painter.drawText(rect, Qt::AlignCenter, tr("Pause"));
        return;
     }

     painter.drawImage(inglip->getRect(), 
     inglip->getImage());
     if (level == 1)
	{	
      painter.drawImage(gropaga->getRect(), 
        gropaga->getImage());

      painter.drawImage(tree->getRect(), 
        tree->getImage());

     painter.drawImage(bush->getRect(), 
        bush->getImage());

	for (int k =0; k<3; k++)
    {
      painter.drawImage(coin[k]->getRect(), 
        coin[k]->getImage());
        
    }
    
    for (int i =0; i<5; i++)
    {
    if (kittens[i]->isDestroyed()&&i!=1)
    {
	kittens[i]->imageChange("imgs/wrong.gif");
        
    }

  
    
    painter.drawImage(kittens[i]->getRect(), 
        kittens[i]->getImage());
   

    
  }

}

   if (level == 2)
	{	
      painter.drawImage(buck->getRect(), 
        buck->getImage());

     
     kittens[0]->imageChange("imgs/rain.gif");
     painter.drawImage(kittens[0]->getRect(), 
        kittens[0]->getImage());
        

    kittens[1]->imageChange("imgs/rain.gif");
    painter.drawImage(kittens[1]->getRect(), 
        kittens[1]->getImage());
   
    kittens[2]->imageChange("imgs/rain.gif");
    painter.drawImage(kittens[2]->getRect(), 
        kittens[2]->getImage());

    
    
    kittens[3]->imageChange("imgs/rain.gif");
    painter.drawImage(kittens[3]->getRect(), 
        kittens[3]->getImage());

    kittens[4]->imageChange("imgs/rain.gif");
    painter.drawImage(kittens[4]->getRect(), 
        kittens[4]->getImage());
	
      for (int i =0; i<5; i++)
    {
    if (rains[i]->isDestroyed()&&i!=1)
    {
	rains[i]->imageChange("imgs/wrong.gif");
        
    }

  
    
    painter.drawImage(rains[i]->getRect(), 
        rains[i]->getImage());
   

    
  }

                          
         
     }

     if (level == 3)
        {
	painter.drawImage(sman->getRect(), 
        sman->getImage());

         for (int i =0; i<10; i++)
    {
   

  
    
    painter.drawImage(sballs[i]->getRect(), 
        sballs[i]->getImage());
   

    
  }


        for (int i =0; i<5; i++)
    	{
   
	painter.drawImage(sled[i]->getRect(), 
        sled[i]->getImage());
   
	}


        for (int i =0; i<3; i++)
    	{
   
	painter.drawImage(present[i]->getRect(), 
        present[i]->getImage());
   
	}


	}

   } 
 
 //Key press event for main character
 void MultBoard::keyPressEvent(QKeyEvent *event)
 {
     if (!isStarted || isPaused) {
         QFrame::keyPressEvent(event);
         return;
     }

     switch (event->key()) {
     case Qt::Key_Left:
       {  
         int x = inglip->getRect().x();
        for (int i=1; i<=5; i++)
          {
          inglip->moveLeft(x--);
          }
        for (int j =0; j<3; j++)
        {
        coin[j]->moveLeft(x--);
       
        }
        if (level==3)
        {
        for (int i =0; i<3; i++)
        {
        present[i]->moveLeft(x--);
       
        }
        sman->moveLeft(x--);
        }
        break;
       }
    case Qt::Key_Right:
        { 
          int x = inglip->getRect().x();
          for (int i=1; i<=5; i++)
            {
            inglip->moveRight(x++);
            }
          if (level ==1)
          {
          for (int j =0; j<3; j++)
        {
        coin[j]->moveRight(x++);
       
        }
          }
          if (level ==3)
          {
          for (int i =0; i<3; i++)
        {
        present[i]->moveRight(x++);
       
        }
        sman->moveRight(x++);
        
      }
        break;
       }
        case Qt::Key_Up:
        { 
          int y = inglip->getRect().y();
          int fuck;
          for (int i=1; i<=5; i++)
            {
            
            fuck = y-10;
            }
            inglip->moveUp(fuck--);
            sman->moveUp(fuck--);
          
        }
        break;
       case Qt::Key_Down:
        { 
          int y = inglip->getRect().y();
          for (int i=1; i<=5; i++)
            inglip->moveDown(y++);
            sman->moveDown(y--);
            
        }
        
        break;
  
    default:
       QWidget::keyPressEvent(event);
   
        
    }
 }

 void MultBoard::timerEvent(QTimerEvent *event)
 {
      
	if (gTest == FALSE)
	gropaga->autoMove();
        
        for (int i=0; i<3; i++)
            {
            coin[i]->autoMove(inglip->getXDir(), inglip->getYDir());
            }


      
	  if (level == 2)
            {
            	
            buck->followMove(inglip->getRect().right(),inglip->getRect().top());
          
		for (int i=0; i<5; i++)
      {
	rains[i]->autoMove();
      }
            


            }


     if (level ==3)
        {
         sman->followMove(inglip->getXDir(), inglip->getYDir());


        for (int i=0; i<10; i++)
      {
	sballs[i]->autoMove(inglip->getXDir(), inglip->getYDir());
      }
           

       for (int i=0; i<5; i++)
      {
	sled[i]->autoMove();
      }
         
        for (int i =0; i<3; i++)
    	{
        
	present[i]->autoMove(inglip->getXDir(), inglip->getYDir());
        
   
	}
          
         
	}


      
      for (int i=0; i<5; i++)
      {
	kittens[i]->autoMove();
      }

    

      
   
      checkCollision();
      repaint();
 }



//Check collision- main function
 void MultBoard::checkCollision()
{

      if (level == 2 && !isPaused )
          {

		
          
         gTest = TRUE;
         

          }
      
  
      levelUp = FALSE;
      int gLeft = gropaga->getRect().left();  
      int gHeight = gropaga->getRect().height(); 
      int gWidth = gropaga->getRect().width();
      int gTop = gropaga->getRect().top();
      int gBottom = gropaga->getRect().bottom();
      int gRight = gropaga->getRect().right();  

        QPoint pointRight(gLeft + gWidth + 1, gTop);
        QPoint pointLeft(gLeft - 1, gTop);  
        QPoint pointTop(gLeft, gTop -1);
        QPoint pointBottom(gLeft, gTop + gHeight + 1); 
       

      
    int iLeft = inglip->getRect().left();  
    int iHeight = inglip->getRect().height(); 
    int iWidth = inglip->getRect().width();
    int iTop = inglip->getRect().top();
    int iBottom = inglip->getRect().bottom();
    int iRight = inglip->getRect().right();

      
    if(gLeft ==10) {
        gropaga->setXDir(10);
   } 

      else if(gLeft==470) {
        gropaga->setXDir(-1);
       } 

      if(gTop == 10) {
         gropaga->setYDir(1);
           
       } 

      else if(gTop ==400) {
          gropaga->setYDir(-1);
         
        } 
	
if (level ==1)
{
    if (((iTop >=( gTop))&&iBottom<=(gBottom)) && iLeft >=(gLeft)&&iRight<=(gRight))
        {
		score= score-1; 
                emit scoreChanged(score);

          }
     if (((iTop >=( kittens[0]->getRect().top()))&&iBottom<=(kittens[0]->getRect().bottom())) && iLeft >=(kittens[0]->getRect().left())&&iRight<=(kittens[0]->getRect().right()))
    
     {
    
      
      kittens[0]->setDestroyed(TRUE);
      score= score-1; 
      emit scoreChanged(score);
      
     
     
     
     }
	
	
        if (((iTop >=( kittens[1]->getRect().top()))&&iBottom<=(kittens[1]->getRect().bottom())) && iLeft >=(kittens[1]->getRect().left())&&iRight<=(kittens[1]->getRect().right()))
     {
      
      
    kittens[1]->setDestroyed(TRUE);
    score= score+15; 
    emit scoreChanged(score);
    inglip->resetState();
    update();
   

    }

	 if (((iTop >=( kittens[2]->getRect().top()))&&iBottom<=(kittens[2]->getRect().bottom())) && iLeft >=(kittens[2]->getRect().left())&&iRight<=(kittens[2]->getRect().right()))
    
     {
    
      
      kittens[2]->setDestroyed(TRUE);
      score= score-1; 
      emit scoreChanged(score);
     
     
     
     }

   if (((iTop >=( kittens[3]->getRect().top()))&&iBottom<=(kittens[3]->getRect().bottom())) && iLeft >=(kittens[3]->getRect().left())&&iRight<=(kittens[3]->getRect().right()))
    
     {
    
      
      kittens[3]->setDestroyed(TRUE);
      score= score-1; 
      emit scoreChanged(score);
     
     
     
     }

 if (((iTop >=( kittens[4]->getRect().top()))&&iBottom<=(kittens[4]->getRect().bottom())) && iLeft >=(kittens[4]->getRect().left())&&iRight<=(kittens[4]->getRect().right()))
    
     {
    
      
      kittens[4]->setDestroyed(TRUE);
      score= score-1; 
      emit scoreChanged(score);
     
     
     
     }
	
    update();
	
    if (score <=15 && score > 0)
    {
    setStyleSheet("QWidget { background-image: url(imgs/background1.gif); }");
    kittens[0]->imageChange("imgs/fly1.png");

        kittens[0]->getImage();

    kittens[1]->imageChange("imgs/fly2.png");
   
        kittens[1]->getImage();
   
    kittens[2]->imageChange("imgs/fly3.png");
   
        kittens[2]->getImage();
    kittens[3]->imageChange("imgs/fly4.png");
   
        kittens[3]->getImage();
    kittens[4]->imageChange("imgs/fly5.png");
 
        kittens[4]->getImage();
    
    }

    else if (score >= 15 && score <35)
    {
    setStyleSheet("QWidget { background-image: url(imgs/background2.gif); }");
     kittens[0]->setDestroyed(FALSE);
     kittens[0]->imageChange("imgs/angel1.png");

        kittens[0]->getImage();

    kittens[1]->imageChange("imgs/angel5.png");
   
        kittens[1]->getImage();
    kittens[2]->setDestroyed(FALSE);
    kittens[2]->imageChange("imgs/angel3.png");
   
        kittens[2]->getImage();
    kittens[3]->setDestroyed(FALSE);
    kittens[3]->imageChange("imgs/angel4.png");
   
        kittens[3]->getImage();
    kittens[4]->setDestroyed(FALSE);
    kittens[4]->imageChange("imgs/angel2.png");
 
        kittens[4]->getImage();
  
      update();

    
    }

    
    else if (score >= 35)
       {
        level =2;
         emit levelChanged(level);
         pause();
         setStyleSheet("QWidget { background-image: url(imgs/levelup.png); }");
        levelUp = TRUE;
        update();
       
       
      }

       

      

   }


else if (level ==2)
{





if (anti_hard == 0)
{
setStyleSheet("QWidget { background-image: url(imgs/blevel20.gif); }");
}
int bLeft = buck->getRect().left();  
      int bHeight = buck->getRect().height(); 
      int bWidth = buck->getRect().width();
      int bTop = buck->getRect().top();
      int bBottom = buck->getRect().bottom();
      int bRight = buck->getRect().right();  


       

      
    int iLeft = inglip->getRect().left();  
    int iHeight = inglip->getRect().height(); 
    int iWidth = inglip->getRect().width();
    int iTop = inglip->getRect().top();
    int iBottom = inglip->getRect().bottom();
    int iRight = inglip->getRect().right();

      
  

    if (((iTop >=( bTop))&&iBottom<=(bBottom)) && iLeft >=(bLeft)&&iRight<=(bRight))
        {
		score= score-1; 
                emit scoreChanged(score);

          }
     if (((iTop >=( kittens[0]->getRect().top()))&&iBottom<=(kittens[0]->getRect().bottom())) && iLeft >=(kittens[0]->getRect().left())&&iRight<=(kittens[0]->getRect().right()))
    
     {
    
      
     
      score= score-1; 
      emit scoreChanged(score);
     
     
     
     
     }
	
	
        if (((iTop >=( kittens[1]->getRect().top()))&&iBottom<=(kittens[1]->getRect().bottom())) && iLeft >=(kittens[1]->getRect().left())&&iRight<=(kittens[1]->getRect().right()))
     {
      
      
  
    score= score-1; 
    emit scoreChanged(score);
    

     }


    if (((iTop >=( kittens[2]->getRect().top()))&&iBottom<=(kittens[1]->getRect().bottom())) && iLeft >=(kittens[2]->getRect().left())&&iRight<=(kittens[2]->getRect().right()))
     {
      
      
  
    score= score-1; 
    emit scoreChanged(score);

     }
if (((iTop >=( kittens[3]->getRect().top()))&&iBottom<=(kittens[3]->getRect().bottom())) && iLeft >=(kittens[3]->getRect().left())&&iRight<=(kittens[3]->getRect().right()))
     {
      
      
  
    score= score-1; 
    emit scoreChanged(score);

     }

if (((iTop >=( kittens[4]->getRect().top()))&&iBottom<=(kittens[4]->getRect().bottom())) && iLeft >=(kittens[4]->getRect().left())&&iRight<=(kittens[4]->getRect().right()))
     {
      
      
  
    score= score-1; 
    emit scoreChanged(score);

     }

if (((iTop >=( rains[0]->getRect().top()))&&iBottom<=(rains[0]->getRect().bottom())) && iLeft >=(rains[0]->getRect().left())&&iRight<=(rains[0]->getRect().right()))
    
     {
    
      
      rains[0]->setDestroyed(TRUE);
      score= score-1; 
      emit scoreChanged(score);
     
     
     
     }
	
	
        if (((iTop >=( rains[1]->getRect().top()))&&iBottom<=(rains[1]->getRect().bottom())) && iLeft >=(rains[1]->getRect().left())&&iRight<=(rains[1]->getRect().right()))
     {
      
      
   rains[1]->setDestroyed(TRUE);
    score= score+15; 
    emit scoreChanged(score);
    inglip->resetState();
   anti_hard = anti_hard +1;
    
    update();

    }

	 if (((iTop >=( rains[2]->getRect().top()))&&iBottom<=(rains[2]->getRect().bottom())) && iLeft >=(rains[2]->getRect().left())&&iRight<=(rains[2]->getRect().right()))
    
     {
    
      
      rains[2]->setDestroyed(TRUE);
      score= score-1; 
      emit scoreChanged(score);
     
     
     
     }

   if (((iTop >=( rains[3]->getRect().top()))&&iBottom<=(rains[3]->getRect().bottom())) && iLeft >=(rains[3]->getRect().left())&&iRight<=(rains[3]->getRect().right()))
    
     {
    
      
      rains[3]->setDestroyed(TRUE);
      score= score-1; 
      emit scoreChanged(score);
     
     
     
     }

 if (((iTop >=( rains[4]->getRect().top()))&&iBottom<=(rains[4]->getRect().bottom())) && iLeft >=(rains[4]->getRect().left())&&iRight<=(rains[4]->getRect().right()))
    
     {
    
      
     rains[4]->setDestroyed(TRUE);
      score= score-1; 
      emit scoreChanged(score);
     
     
     
     }


    if (anti_hard== 1)
        {




	setStyleSheet("QWidget { background-image: url(imgs/blevel21.gif); }");
     rains[0]->setDestroyed(FALSE);
     rains[0]->imageChange("imgs/umbrella1.png");

        rains[0]->getImage();

    rains[1]->imageChange("imgs/umbrella2.png");
   
       rains[1]->getImage();
    rains[2]->setDestroyed(FALSE);
    rains[2]->imageChange("imgs/umbrella3.png");
   
        rains[2]->getImage();
    rains[3]->setDestroyed(FALSE);
    rains[3]->imageChange("imgs/umbrella4.png");
   
        rains[3]->getImage();
    rains[4]->setDestroyed(FALSE);
    rains[4]->imageChange("imgs/umbrella5.png");
 
        rains[4]->getImage();
         
  
       update();
       
       


}

if (anti_hard == 2)
 {


	
	setStyleSheet("QWidget { background-image: url(imgs/blevel22.gif); }");
     rains[0]->setDestroyed(FALSE);
     rains[0]->imageChange("imgs/parka1.gif");

        rains[0]->getImage();

    rains[1]->imageChange("imgs/parka2.gif");
   
       rains[1]->getImage();
    rains[2]->setDestroyed(FALSE);
    rains[2]->imageChange("imgs/parka3.gif");
   
        rains[2]->getImage();
    rains[3]->setDestroyed(FALSE);
    rains[3]->imageChange("imgs/parka4.gif");
   
        rains[3]->getImage();
    rains[4]->setDestroyed(FALSE);
    rains[4]->imageChange("imgs/parka5.gif");
 
        rains[4]->getImage();
        
  
       update();
}

if (anti_hard ==3)
{

level =3;
         emit levelChanged(level);
         pause();
         setStyleSheet("QWidget { background-image: url(imgs/levelup.png); }");
        levelUp = TRUE;
        update();


}

update();


}


if (level ==3 && !isPaused)
{
setStyleSheet("QWidget { background-image: url(imgs/b31.gif); }");

if (((iTop >=( sballs[0]->getRect().top()))&&iBottom<=(sballs[0]->getRect().bottom())) && iLeft >=(sballs[0]->getRect().left())&&iRight<=(sballs[0]->getRect().right()))
    
     {
    
      
     
      score= score-1; 
      emit scoreChanged(score);
     
     
     
     
     }
	
	
        if (((iTop >=( sballs[1]->getRect().top()))&&iBottom<=(sballs[1]->getRect().bottom())) && iLeft >=(sballs[1]->getRect().left())&&iRight<=(sballs[1]->getRect().right()))
     {
      
      
  
    score= score-1; 
    emit scoreChanged(score);
    

     }


    if (((iTop >=( sballs[2]->getRect().top()))&&iBottom<=(sballs[2]->getRect().bottom())) && iLeft >=(sballs[2]->getRect().left())&&iRight<=(sballs[2]->getRect().right()))
     {
      
      
  
    score= score-1; 
    emit scoreChanged(score);

     }
if (((iTop >=( sballs[3]->getRect().top()))&&iBottom<=(sballs[3]->getRect().bottom())) && iLeft >=(sballs[3]->getRect().left())&&iRight<=(sballs[3]->getRect().right()))
     {
      
      
  
    score= score-1; 
    emit scoreChanged(score);

     }

if (((iTop >=( sballs[4]->getRect().top()))&&iBottom<=(sballs[4]->getRect().bottom())) && iLeft >=(sballs[4]->getRect().left())&&iRight<=(sballs[4]->getRect().right()))
     {
      
      
  
    score= score-1; 
    emit scoreChanged(score);

     }








if (((iTop >=( sled[0]->getRect().top()))&&iBottom<=(sled[0]->getRect().bottom())) && iLeft >=(sled[0]->getRect().left())&&iRight<=(sled[0]->getRect().right()))
    
     {
    
      
      sled[0]->setDestroyed(TRUE);
      score= score-1; 
      emit scoreChanged(score);
     
     
     
     }
	
	
        if (((iTop >=( sled[1]->getRect().top()))&&iBottom<=(sled[1]->getRect().bottom())) && iLeft >=(sled[1]->getRect().left())&&iRight<=(sled[1]->getRect().right()))
     {
      
      
   sled[1]->setDestroyed(TRUE);
    score= score+15; 
    emit scoreChanged(score);
    inglip->resetState();
   anti_hard = anti_hard +1;
    
    update();

    }

	 if (((iTop >=( sled[2]->getRect().top()))&&iBottom<=(sled[2]->getRect().bottom())) && iLeft >=(sled[2]->getRect().left())&&iRight<=(sled[2]->getRect().right()))
    
     {
    
      
      sled[2]->setDestroyed(TRUE);
      score= score-1; 
      emit scoreChanged(score);
     
     
     
     }

   if (((iTop >=( sled[3]->getRect().top()))&&iBottom<=(sled[3]->getRect().bottom())) && iLeft >=(sled[3]->getRect().left())&&iRight<=(sled[3]->getRect().right()))
    
     {
    
      
      sled[3]->setDestroyed(TRUE);
      score= score-1; 
      emit scoreChanged(score);
     
     
     
     }

 if (((iTop >=( sled[4]->getRect().top()))&&iBottom<=(sled[4]->getRect().bottom())) && iLeft >=(sled[4]->getRect().left())&&iRight<=(sled[4]->getRect().right()))
    
     {
    
      
     sled[4]->setDestroyed(TRUE);
      score= score-1; 
      emit scoreChanged(score);
     
     
     
     }


  if (anti_hard >=4 )
     {
      
      setStyleSheet("QWidget { background-image: url(imgs/victory.gif); }");
     
     update();
      pause();


      }

if (anti_hard >= 4 and !isPaused)
    {
     level =1;
     score = 1;
     start();
    }





}

  
     


     
      
  }
  
 
