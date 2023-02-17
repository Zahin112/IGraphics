#include "iGraphics.h"
#define pi 3.1416
#include<time.h>
#include<math.h>



#define totalBricks 1
#define screenHight 650
#define screenWide 1200
#define yAxisMergin 50
#define tetadefine 90
#define pi 3.1416




static int score=0;
int level2;
int help;
int home;
static int c=0;
static char sc[10];
static char s[10];
static char ch;
static int life =  0;
static int l = 4;

int x,y;
char str[106]="S";
int bcindex=0;
int red=0,blue=250,green=0;
int xball=(int)screenWide/2;
int yball= yAxisMergin;
int radiuscircle=10;

bool musicon =true;
int xboard=xball-50;
int yboard=yball-20;
int dxboard=100;
int dyboard=10;
bool isstated =false;
int mode=0;

int v=10;
int teta =tetadefine;
float  dx =(float)v*cos(teta*pi/180);
float  dy =(float)v*sin(teta*pi/180);



struct buttoncoordinate
{
    int x;
    int y;
};






struct brickstructure
{
    int x;
    int y;
    int dx=25;
    int dy=25;
    bool show = true;
    int red;
    int green;
    int blue;
};

brickstructure Bricks[totalBricks];
//int teta =45;
//int velocity=10;
//dx=velocity*cos(teta);
//dy=velocity*sin(teta);



void ballchange();
void restartball();
void definebricks();
char *int_to_string(int n,char *s);


void iDraw()
{
    iClear();



    if(mode==0)
    {
        iShowBMP(0,0,"bin\\7.bmp");

        //   iShowBMP2(50,100,menu,255);
        iSetColor(250,250,250);
        iFilledRectangle(480,500,240,50);
        iSetColor(0,0,0);
        iText(530,520,"PLAY GAME",GLUT_BITMAP_TIMES_ROMAN_24);
        //iText(600,400,st);
        iSetColor(250,250,250);
        iFilledRectangle(480,400,240,50);
        iSetColor(0,0,0);
        iText(530,420,"HIGH SCORE",GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(250,250,250);
        iFilledRectangle(480,300,240,50);
        iSetColor(0,0,0);
        iText(560,320,"HELP",GLUT_BITMAP_TIMES_ROMAN_24);





        if(help==1)
        {
            iClear();
            iShowBMP(0,0,"bin\\10.bmp");
            iRectangle(1100,4,80,20);
            iText(1105,5,"BACK",GLUT_BITMAP_TIMES_ROMAN_24);



            if(home==1)
            {

                iShowBMP(0,0,"bin\\7.bmp");

                //   iShowBMP2(50,100,menu,255);
                iSetColor(250,250,250);
                iFilledRectangle(480,500,240,50);
                iSetColor(0,0,0);
                iText(530,520,"PLAY GAME",GLUT_BITMAP_TIMES_ROMAN_24);
                //iText(600,400,st);
                iSetColor(250,250,250);
                iFilledRectangle(480,400,240,50);
                iSetColor(0,0,0);
                iText(530,420,"HIGH SCORE",GLUT_BITMAP_TIMES_ROMAN_24);
                iSetColor(250,250,250);
                iFilledRectangle(480,300,240,50);
                iSetColor(0,0,0);
                iText(560,320,"HELP",GLUT_BITMAP_TIMES_ROMAN_24);



            }

        }
    }







    if(mode==1)
    {

        //iShowBMP(0,0,"bin\\4.bmp");
        iSetColor(red,green,blue);
        iFilledCircle(xball,yball,radiuscircle,1000);
        iSetColor(0,0,250);
        iFilledRectangle(xboard,yboard,dxboard,dyboard);
        iRectangle(1100,4,80,20);
        iText(1105,5,"BACK",GLUT_BITMAP_TIMES_ROMAN_24);


        //place your drawing codes her
        for(int i=0; i<totalBricks; i++)
        {
            if(Bricks[i].show)
            {

                iSetColor(Bricks[i].red,Bricks[i].green,Bricks[i].blue);



                iFilledRectangle(Bricks[i].x,Bricks[i].y,Bricks[i].dx,Bricks[i].dy );
                //SetColor(0,250,0);
                //iText(Bricks[i].x +25,Bricks[i].y+15,str);
            }
        }


        int_to_string(score,sc);
        iText( 6,10,"SCORE :",GLUT_BITMAP_TIMES_ROMAN_24);
        iText( 100,10,sc,GLUT_BITMAP_TIMES_ROMAN_24);


        int_to_string(l,s);
        iText( 600,10,"LIFE :",GLUT_BITMAP_TIMES_ROMAN_24);

        iText( 700,10,s,GLUT_BITMAP_TIMES_ROMAN_24);



        if(c==totalBricks)

        {
            iShowBMP(0,0,"bin\\8.bmp");



            if(level2==2)
            {
                iClear();
                iSetColor(red,green,blue);
                iFilledCircle(xball,yball,radiuscircle,1000);
                iSetColor(0,0,250);
                iFilledRectangle(xboard,yboard,dxboard,dyboard);
                iRectangle(1100,4,80,20);
                iText(1105,5,"BACK",GLUT_BITMAP_TIMES_ROMAN_24);


                //place your drawing codes her
                for(int i=0; i<totalBricks; i++)
                {
                    if(Bricks[i].show)
                    {

                        iSetColor(Bricks[i].red,Bricks[i].green,Bricks[i].blue);



                        iFilledRectangle(Bricks[i].x,Bricks[i].y,Bricks[i].dx,Bricks[i].dy );
                        //SetColor(0,250,0);
                        //iText(Bricks[i].x +25,Bricks[i].y+15,str);
                    }
                }

                // iRectangle(5,10,100,20);
                int_to_string(score,sc);
                iText( 6,10,"SCORE :",GLUT_BITMAP_TIMES_ROMAN_24);
                //ballchange();
                iText( 100,10,sc,GLUT_BITMAP_TIMES_ROMAN_24);


                int_to_string(l,s);
                iText( 600,10,"LIFE :",GLUT_BITMAP_TIMES_ROMAN_24);
                //ballchange();
                iText( 700,10,s,GLUT_BITMAP_TIMES_ROMAN_24);




                if(life==4)

                {
                    iShowBMP(0,0,"bin\\9.bmp");
                }


            }


        }

        if(life==4)

        {
            iShowBMP(0,0,"bin\\9.bmp");
        }
    }

}











void definebricks()
{

    int sumx = 100;
    int sumy = 450;
    for(int i=0; i<totalBricks; i++)
    {
        Bricks[i].red = rand() %255;
        Bricks[i].green= rand() %255;
        Bricks[i].blue= rand() %255;
        Bricks[i].x =sumx;
        Bricks[i].y =sumy;
        sumx+=120;
        if(sumx>1120)
        {
            sumx=150;
            sumy+=50;
        }
    }

}




char *int_to_string(int n,char *s)
{
    if(n<10)
    {
        *s='0'+n;
        *++s=0;
        return s;
    }
    s=int_to_string(n/10,s);
    *s='0'+n%10;
    *++s=0;
    return s;
}




void ballchange()
{
    if(isstated)
    {
        xball+=dx;
        yball+=dy;
        if(xball>=screenWide-10)
        {
            dx*=(-1);
        }
        if(xball<10)
        {
            dx+=10;
        }


        if(yball>=screenHight -20 )
        {
            dy*=(-1);

        }

        for(int i=0; i<totalBricks; i++)
        {
            if(Bricks[i].show)
            {

                if(xball >= Bricks[i].x -10 && xball <= Bricks[i].x + Bricks[i].dx +10 )
                {
                    if(yball >= Bricks[i].y  -10  &&  yball <= Bricks[i].y + Bricks[i].dy +10)
                    {
                        dy*=(-1);
                        Bricks[i].show =false;
                        score++;
                        c++;

                    }
                }
                else if(yball >= Bricks[i].y-10&& yball <= Bricks[i].y + Bricks[i].dy +10)

                {

                    if(xball >= Bricks[i].x -10 && xball <= Bricks[i].x + Bricks[i].dx+10)
                    {
                        dx*=(-1);
                        Bricks[i].show =false;
                        score++;
                        c++;

                    }
                }

            }

        }




        if(xball>=xboard-10 && xball<= xboard + dxboard +10 && yball >= yboard +10&& yball<=yboard +dyboard +10)
        {
            teta=dxboard +xboard +40-xball;
            dx=v*cos(teta*pi /180);
            dy=v*sin(teta*pi /180);
        }

        else
        {
            if(yball<yboard)
            {

                bool isstated=false;
                restartball();


            }
        }
    }

}


void restartball()
{

    life++;

    l--;


    xball=(int)screenWide/2;
    yball= yAxisMergin;

    //dx=7;
    //dy=5;
    xboard=xball -50;
    yboard=yball -20;
    isstated=false;


}



/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/

void iMouseMove(int mx, int my)
{
    printf("x = %d, y= %d\n",mx,my);
    //place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouse(int button, int state, int mx, int my)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {

        if(mx>=480 && my>=500 && mx<=720 && my<=550 && mode==0)
        {
            mode=1;
        }


        if(mx>=480 && my>=300 && mx<=720 && my<=350 && mode==0)
        {
            help=1;
        }


        if(mx>=1100 && my>=4 && mx<=1180 && my<=24 && mode==1)
        {
            mode=0;
        }

        if(mx>=1100 && my>=4 && mx<=1180 && my<=24 &&  ( mode==0 || mode== 1) && help==1)
        {
            home=1;
        }


        if(mx>=0 && my>=0 && mx<=1200 && my<=650 && mode==1  && c==totalBricks)
        {
            level2 = 2;
        }


        //place your codes here
        //	printf("x = %d, y= %d\n",mx,my);
        x += 10;
        y += 10;
    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {

        //place your codes here
        x -= 10;
        y -= 10;
    }
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/


void iKeyboard(unsigned char key)
{
    if (key == 'q')
    {
        exit(0);
    }

    else if (key == ' ' || key== 's')
    {

        {
            if(!isstated)
            {
                isstated=true;
            }
        }
    }

    else if (key == 's')
    {

        {
            // start=1;
        }

    }
    else if (key == 'b')
    {

        {
            //start=0;
        }

    }
    //place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
	*/

void iSpecialKeyboard(unsigned char key)
{

    if (key == GLUT_KEY_END)
    {
        exit(0);
    }
    if (key == GLUT_KEY_LEFT)
    {
        if(xboard>0)
        {
            xboard-=50;
            if(!isstated)
            {
                xball -=50;
            }
        }
    }
    if (key == GLUT_KEY_RIGHT)
    {
        if(xboard<screenWide-dxboard)
        {
            xboard+=50;
            if(!isstated)
            {
                xball+=50;
            }
        }
    }

    //place your codes for other keys here
}


int main()

{
    definebricks();
    iSetTimer(25,ballchange );

    iInitialize(screenWide,screenHight,"DX BALL GAME");


    return 0;
}

