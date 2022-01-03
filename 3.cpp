#include<GL/glut.h>
#include<iostream>
using namespace std;
float xc=50,yc=50,r=50;

void init()
{	glClearColor(1,1,1,1);
	gluOrtho2D(0,500,0,500);
}

void plotall(float x, float y,float xc, float yc)
{	glVertex2d(x + xc , y + yc);
	glVertex2d(-x + xc , y + yc);
	glVertex2d(x + xc , -y + yc);
	glVertex2d(-x + xc , -y + yc);
	glVertex2d(y + xc , x + yc);
	glVertex2d(-y + xc , x + yc);
	glVertex2d(y + xc , -x + yc);
	glVertex2d(-y + xc , -x + yc);
}
void display()
{	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0,0,0);
	float x=r, y=0,p=1-r;
	glBegin(GL_POINTS);
	while(x>y)
	{	y++;
		if(p<0)
		{	p+=2*y-1;
		}
		else
		{	p+=2*y-2*x-1;
			x--;
		}
		plotall(x,y,xc,yc);
	}
	
	glEnd();
	glFlush();
}

int main(int argc, char* argv[])
{		
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutCreateWindow("a");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
	return 1;
}
