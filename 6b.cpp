#include<GL/glut.h>
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int WXmin = 10, WXmax=410, WYmin=10, WYmax=370, VXmin=420, VXmax=620, VYmin=10, VYmax=190;
int a1[2],b1[2],c1[2],a[2]={40,240},b[2]={40,40},c[2]={330,150};

void init()
{	glClearColor(1,1,1,1);
	gluOrtho2D(-500,500,-500,500);
}

void init2()
{	glClearColor(1,1,1,1);
	gluOrtho2D(0,800,0,800);
}

void draw1()
{	glBegin(GL_LINE_LOOP);
	glVertex2d(WXmin, WYmin);
	glVertex2d(WXmax,WYmin);
	glVertex2d(WXmax,WYmax);
	glVertex2d(WXmin,WYmax);
	glEnd();
}

void draw2()
{	glBegin(GL_LINE_LOOP);
	glVertex2d(VXmin,VYmin);
	glVertex2d(VXmax,VYmin);
	glVertex2d(VXmax,VYmax);
	glVertex2d(VXmin,VYmax);
	glEnd();
}

void tri(int a[2],int b[2], int c[2])
{	glBegin(GL_TRIANGLES);
	glColor3f(0,0,0);
	glVertex2d(a[0],a[1]);
	glVertex2d(b[0],b[1]);
	glVertex2d(c[0],c[1]);
	glEnd();
}
void display()
{	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0,0,0);
	draw1();
	tri(a,b,c);
	glFlush();
}

void con()
{	int VXrange=VXmax-VXmin, VYrange=VYmax-VYmin, WXrange=WXmax-WXmin, WYrange=WYmax-WYmin;
	a1[0]=VXmin + VXrange * (a[0] - WXmin) / WXrange;
	b1[0]=VXmin + VXrange * (b[0] - WXmin) / WXrange;
	c1[0]=VXmin + VXrange * (c[0] - WXmin) / WXrange;
	a1[1]=VYmin + VYrange * (a[1] - WYmin) / WYrange;
	b1[1]=VYmin + VYrange * (b[1] - WYmin) / WYrange;
	c1[1]=VYmin + VYrange * (c[1] - WYmin) / WYrange;
	
}
void display2()
{	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0,0,0);
	draw2();
	con();
	tri(a1,b1,c1);
	glFlush();
}

int main(int argc, char* argv[])
{	GLint id1,id2;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1000,1000);
	id1=glutCreateWindow("a");
	glutDisplayFunc(display);
	init();
	glutInitWindowSize(800,800);
	id2=glutCreateWindow("b");
	glutDisplayFunc(display2);
	init2();
	glutMainLoop();
	return 1;
}
