#include<GL/glut.h>
float x1=10,x2=200,y1=10,y2=100;
void init()
{	glClearColor(1,1,1,1);
	gluOrtho2D(0,500,0,500);
}

void display()
{	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0,0,0);
	float dx,dy,step,xin,yin;
	dx=x2-x1;
	dy=y2-y1;
	if(abs(dx)>abs(dy))
		step=dx;
	else
		step=dy;
	xin=dx/step;
	yin=dy/step;
	glBegin(GL_POINTS);
	glVertex2d(x1,y1);
	while(x1<x2)
	{	x1+=xin;
		y1+=yin;
		glVertex2d(x1,y1);
	}
	glEnd();
	glFlush();
}

int main(int argc, char*argv[])
{	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(500,500);
	glutCreateWindow("a");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
	return 1;
}
