#define _CRT_SECURE_NO_WARNINGS
# include "iGraphics.h"
#define totalbricks 98
int x = 300+40, y = 70, r ,bx=300,by=50 ,boardx=75,dx=5,dy=5;
// int r=10;
    int g,life=10;
    int b;
    int a=50;
bool start = false;
char lastKey = 0;
void ballchange();
void definebricks();
struct brickstructure
{
    int x;
    int y;
    int dx=35;
    int dy=15;
    int r;
    int g;
    int b;
    //int Life;
    bool show=true;
};

brickstructure bricks[totalbricks];

void iDraw() {
	int i;

	iClear();
	iSetColor(20, 200, 200);
	iFilledRectangle(bx,by,boardx,10);
	iFilledCircle(x, y, 6,100);
	iSetColor(20, 200, 0);
    iText(10,10,"Life:");
    iText(550,10,"Score:");
	for(i=0;i<totalbricks;i++)
    {
        if(bricks[i].show)
        {
            iSetColor(bricks[i].r,bricks[i].g,bricks[i].b);
            iFilledRectangle(bricks[i].x,bricks[i].y,bricks[i].dx,bricks[i].dy);
        }
    }
	}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
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

		//y += 10;
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		//place your codes here

		//y -= 10;
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key) {
	static int c=0;
	if(bx>=0){
	 if(key == 'a')
    {bx-=10;
     if(start==false)
        x-=10;
        }
        }
        if(bx<=725){
    if (key == 'd') {
		bx+=10;
    if(start==false)
        x+=10;
	}
	if(key == ' ')
    {
      if(!start){
        start=true;}
    }

	}
	if (key == 'q') {
		exit(0);
	}
	/*else if(lastKey == key){
            c++;
	}
	else{
        printf("lastKey:%c  %d times\n",lastKey,c);
        c = 0;
        lastKey = key;
	}*/
if(key == ' ')
    {
      if(!start){
        start = true;}
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
void restart(){
bx=300;
x = 300+40;
y = 70;
start = false;
}

void ballchange(){
    if(start==true){
x+=dx;
y+=dy;
if(y>=600||y<=0)
{
   dy*=(-1);
}
if(x>=800||x<=0)
{
    dx*=(-1);
}
if(y<70 && x>=bx && x<=bx+boardx)
    { dy*=(-1);
}
if(y<=60 && x<=bx+boardx && x>=bx+boardx&& y>=by&&y<=60)
    { dy*=(-1);
}
else{
    if(y<by)
        restart();
}
}
for(int i=0;i<totalbricks;i++)
{
    if(bricks[i].show)
    {

        if((y+4)>=bricks[i].y&& (y+4)<=bricks[i].y+bricks[i].dy){
            if((x+4)>=bricks[i].x&&(x+4)<=bricks[i].x+bricks[i].dx){
                    dy*=-1;
                bricks[i].show=false;
    }
        }
        else if(x+4>=bricks[i].x&&x+4<=bricks[i].x+bricks[i].dx){
            if(y+4>=bricks[i].y&& y+4<=bricks[i].y+bricks[i].dy){
                dx*=-1;
                bricks[i].show=false;
            }
        }

}
}
}


void definebricks(){
int sumx=50;
int sumy=400;
for(int i=0;i<totalbricks;i++)
    {
        bricks[i].r=rand()%255;
        bricks[i].g=rand()%255;
        bricks[i].b=rand()%255;
        bricks[i].x=sumx;
        bricks[i].y=sumy;
        sumx+=50;
        if(sumx>700){
            sumx=50;
            sumy+=20;
        }}
/*for(int i=0;i<totalbricks;i++)
    {  if(i%2){
        bricks[i].r=rand()%255;
        bricks[i].g=rand()%255;
        bricks[i].b=rand()%255;
        bricks[i].x=sumx;
        bricks[i].y=sumy;
        sumx+=50;
        if(sumx>700){
            sumx=50;
            sumy+=20;
        }
    }
    else sumx+=50;

}*/
}

int main() {
    definebricks();
    iSetTimer(50,ballchange);
	//place your own initialization codes here.
	iInitialize(800, 600, "demooo");
	return 0;
}
