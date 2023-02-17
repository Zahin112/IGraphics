#define _CRT_SECURE_NO_WARNINGS
# include "iGraphics.h"
#include<math.h>
int x = 300, y = 300;
double r = 20,hr,mn,sec;
double rsec=170 ,rmin=140 ,rhour=110 ;
double asec=1.573 ,amin=1.573,ahour=1.573;
char lastKey = 0;
//double xmin=300,ymin=440,xhour=410,yhour=300,xsec=300,ysec=470;
/*
	function iDraw() is called again and again by the system.

	*/
void iDraw() {
	//place your drawing codes here
	iClear();
	iSetColor(255,r,0);
	iLine(300,300,300+140*cos(-amin),300+140*sin(-amin));//minyte
	iLine(300,300,300+110*cos(-ahour),300+110*sin(-ahour));//hour
	iLine(300,300,300+170*cos(-asec),300+170*sin(-asec));//second
	iFilledCircle(300,300,5);

	iSetColor(200, 200, 200);
	iCircle(300, 300, 200);
	iText(300+92, 300+160, "1");
    iText(300+160, 300+92, "2");
	iText(485, 299, "3");
	iText(300+160, 300-92, "4");
	iText(300+92, 300-160, "5");
	iText(294.5, 110, "6");
	iText(300-92, 300-160, "7");
	iText(300-160, 300-92, "8");
	iText(110, 299, "9");
	iText(300-160, 300+92, "10");
	iText(300-92, 300+160, "11");
	iText(290, 480, "12");

	//iSetColor(20, 200, 0);
	//iText(40, 40, "Hi, I am iGraphics");
}


	/*function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouseMove(int mx, int my) {
	//	printf("x = %d, y= %d\n",mx,my);
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouse(int button, int state, int mx, int my) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		//place your codes here
		//	printf("x = %d, y= %d\n",mx,my);
		x += 10;
		y += 10;
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		//place your codes here
		x -= 10;
		y -= 10;
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key) {
	static int c=0;
	if (key == 'q') {
		exit(0);
	}
	else if(lastKey == key){
            c++;
	}
	else{
        printf("lastKey:%c  %d times\n",lastKey,c);
        c = 0;
        lastKey = key;
	}

        //printf("%c\n",key);
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
void iSpecialKeyboard(unsigned char key) {

	if (key == GLUT_KEY_END) {
		exit(0);
	}
	//place your codes for other keys here
}
void hour(){
ahour+=3.1416/3600;
}
void minute(){
amin+=3.1416/1800;
}
void second(){
asec+=3.1416/30;
}

int main() {
    iClear();
 double h,m,s;
 int a;
 printf("1 for input time, 2 for system time ");
 scanf("%d",&a);
 if(a==1){

    printf("Input hour, minute and second");
    scanf("%lf %lf %lf",&hr, &mn ,&sec);
 }

 if(a==2){
    time_t t;
    time(&t);
    struct tm*time=localtime(&t);
    hr=time->tm_hour;
    mn=time->tm_min;
    sec=time->tm_sec;
 }
 h=hr+mn/60+sec/3600;
 m=mn+sec/60;
 s=sec;

 ahour=(h-3)*3.1416/6;
 amin=(m-15)*3.1416/30;
 asec=(s-15)*3.1416/30;


    iSetTimer(1000,second);
	iSetTimer(1000,minute);
	iSetTimer(60000,hour);
	iInitialize(600, 600, "Clock");

	return 0;
}
