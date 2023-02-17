# include "iGraphics.h"

char str[100], str2[100];
int len;
int mode,x=50,l=0,r=200;

void drawTextBox()
{
	iSetColor(150, 150, 150);
	iRectangle(75, 450, 450, 40);
}


void A(int a){

iLine(a,70,a,120);
iLine(a+25,70,a+25,120);
iLine(a,120,a+25,120);
iLine(a,100,a+25,100);}

void b(int a){

iRectangle(a,70,25,20);
iLine(a,70,a,120);
 }

void C(int a){

iLine(a,70,a,120);
iLine(a,70,a+25,70);
iLine(a,120,a+25,120);
 }

void D(int a){

iRectangle(a,70,25,50);
}

void E(int a){

iLine(a,70,a,120);
iLine(a,70,a+25,70);
iLine(a,95,a+25,95);
iLine(a,120,a+25,120);}

void F(int a){

iLine(a,70,a,120);
iLine(a,100,a+25,100);
iLine(a,120,a+25,120);}

void f0(int a){
iRectangle(a,70,25,50);
}

void f1(int a){
iLine(a,70,a,120);
}

void f2(int a){
iLine(a,70,a+25,70);
iLine(a,70,a,95);
iLine(a,95,a+25,95);
iLine(a+25,95,a+25,120);
iLine(a,120,a+25,120);
}

void f3(int a){iLine(a+25,70,a+25,120);
iLine(a,70,a+25,70);
iLine(a,95,a+25,95);
iLine(a,120,a+25,120);
}

void f4(int a){
iLine(a+25,70,a+25,120);
iLine(a,120,a,95);
iLine(a,95,a+25,95);
}

void f5(int a){
iLine(a,70,a+25,70);
iLine(a+25,70,a+25,95);
iLine(a,95,a,120);
iLine(a,95,a+25,95);
iLine(a,120,a+25,120);
}

void f6(int a){
iLine(a,70,a,120);
iRectangle(a,70,25,25);
iLine(a,120,a+25,120);
}

void f7(int a){
iLine(a+25,70,a+25,120);
iLine(a,120,a+25,120);
}

void f8(int a){
iRectangle(a,70,25,50);
iLine(a,95,a+25,95);
}

void f9(int a){
iLine(a,70,a+25,70);
iRectangle(a,95,25,25);
iLine(a+25,70,a+25,120);
}

void iDraw()
{
	//place your drawing codes here
int a,i;
	iClear();


	drawTextBox();
	if(mode == 1)
	{
		iSetColor(255, 255, 255);
		iText(90, 465, str);
	}
	iText(30, 10, "Click to activate the box, enter to finish.");

//a=x;
iSetColor(r, r+3, 100);

for(i=0,a=x;str2[i]!=0;i++,a+=30)
{
    switch(str2[i]){
    case 'A': {A(a);}
    break;
     case 'b': {b(a);}
    break;
    case 'C':{C(a);}
    break;
    case 'D': D(a);
    break;
    case 'E': E(a);
    break;
    case 'F': F(a);
    break;
    case '0': f0(a);
    break;
    case '1': f1(a);
    break;
    case '2': f2(a);
    break;
    case '3': f3(a);
    break;
   case '4': f4(a);
    break;
   case '5': f5(a);
    break;
   case '6': f6(a);
    break;
   case '7': f7(a);
    break;
   case '8': f8(a);
    break;
   case '9': f9(a);
    break;

   }

}

}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here

}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{

	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
		if(mx >= 70 && mx <= 530 && my >= 420 && my <= 500 && mode == 0)
		{
			mode = 1;
		}
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	int i;
	if(mode == 1)
	{

        if(key == '\r')
		{
			mode = 0;
			x=50;
			strcpy(str2, str);
			printf("%s\n", str2);
			for(i = 0; i < len; i++)
				str[i] = 0;
			len = 0;
		}
		else
		{
			str[len] = key;
			len++;
            l=len;
		}
	}

	if(key == 'x')
	{
		//do something with 'x'
		exit(0);
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

	if(key == GLUT_KEY_END)
	{
		exit(0);
	}

	//place your codes for other keys here
}
void start(){
    int p;
    if(r<0||r>255)
        r=20;
    r+=5;
p=5-l*30;
 x-=2;
if(x<p) x=600;

}
int main()
{
	//place your own initialization codes here.
	len = 0;
	mode = 0;
	str[0]= 0;
    iSetTimer(100,start);
    //iSetTimer(100,color);
	iInitialize(600, 600, "Letter Board");
	return 0;
}
