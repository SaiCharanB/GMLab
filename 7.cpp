#include<GL/glut.h>



int x1=10,y1=10,x2=200,y2=200;
int xmin=20,ymin=20,xmax=100,ymax=100;

void init()
{	glClearColor(1,1,1,1);
	gluOrtho2D(-500,500,-500,500);
}

int region(int x, int y)
{	int c=0;
	if(y>ymax)
		c=8;
	if(y<ymin)
		c=4;
	if(x>xmax)
		c+=2;
	if(x<xmin)
		c+=1;
	return c;
}

void cohen()
{	int c1=region(x1,y1);
	int c2=region(x2,y2);
	if((c1|c2)>0)
	{	if((c1&c2)>0)
			return;
		int xi=x1,yi=y1,c=c1;
		float m=(y2-y1)/(x2-x1);
		if(c==0)
		{	c=c2;
			xi=x2;
			yi=y2;
		}
		int x,y;
		if((c&8)>0)
		{	y=ymax;
			x=xi+(1/m)*(ymax-yi);
		}
		if((c&4)>0)
		{	y=ymin;
			x=xi+(1/m)*(ymin-yi);
		}
		if((c&2)>0)
		{	x=xmax;
			y=yi+m*(xmax-xi);
		}
		if((c&1)>0)
		{	x=xmin;
			y=yi+m*(xmin-xi);
		}
		if(c==c1)
		{	x1=x;
			y1=y;
			c1=region(x1,y1);
		}
		if(c==c2)
		{	x2=x;
			y2=y;
			c2=region(x2,y2);
		}
	}
}

void display()
{	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0,0,0);
	glBegin(GL_LINES);
	glVertex2d(x1,y1);
	glVertex2d(x2,y2);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex2d(xmin,ymin);
	glVertex2d(xmin,ymax);
	glVertex2d(xmax,ymax);
	glVertex2d(xmax,ymin);
	glEnd();
	glFlush();
}

void clip( unsigned char k, int a, int b)
{	if(k=='c')
	{	cohen();
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0,0,0);
	glBegin(GL_LINES);
	glVertex2d(x1,y1);
	glVertex2d(x2,y2);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex2d(xmin,ymin);
	glVertex2d(xmin,ymax);
	glVertex2d(xmax,ymax);
	glVertex2d(xmax,ymin);
	glEnd();
	glFlush();
	}
}
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1000,1000);
	glutCreateWindow("a");
	glutDisplayFunc(display);
	glutKeyboardFunc(clip);
	init();
	glutMainLoop();
	return 1;
}
