#include<GL/glut.h>
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
float x[4]={0,0,100,100};
float y[4]={0,100,100,0};
float res[3][1]={0};
float ori[3][3]={{-1,0,0},{0,1,0},{0,0,1}};
float shx[3][3]={{1,0.2,0},{0,1,0},{0,0,1}};

void init()
{	glClearColor(1,1,1,1);
	gluOrtho2D(-500,500,-500,500);
}

void mul(float m[3][3],float n[3][1])
{	memset(res,0,3*1*sizeof(float));
	for(int i=0;i<3;i++)
		for(int j=0;j<1;j++)
			for(int k=0;k<3;k++)
				res[i][j]+=m[i][k]*n[k][j];
}

void ref()
{	glBegin(GL_LINE_LOOP);
	for(int i=0;i<4;i++)
	{	float arr[3][1]={{x[i]},{y[i]},{1}};
		mul(ori,arr);
		glVertex2d(res[0][0],res[1][0]);
	}
	glEnd();
}

void sh()
{	glBegin(GL_LINE_LOOP);
	for(int i=0;i<4;i++)
	{	float arr[3][1]={{x[i]},{y[i]},{1}};
		mul(shx,arr);
		glVertex2d(res[0][0],res[1][0]);
	}
	glEnd();
}

void n()
{	glBegin(GL_LINE_LOOP);
	for(int i=0;i<4;i++)
	{	glVertex2d(x[i],y[i]);
	}
	glEnd();
}

void t()
{	glBegin(GL_LINE_LOOP);
	for(int i=0;i<4;i++)
	{	glVertex2d(x[i]+50,y[i]+50);
	}
	glEnd();
}

void r()
{	glBegin(GL_LINE_LOOP);
	for(int i=0;i<4;i++)
	{	glVertex2d(x[i]*cos(0.1)-y[i]*sin(0.1),x[i]*sin(0.1)+y[i]*cos(0.1));
	}
	glEnd();
}
void display()
{	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0,0,0);
	n();
	ref();
	//sh();
	//t();
	//r();
	glFlush();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1000,1000);
	glutCreateWindow("a");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
	return 1;
}
