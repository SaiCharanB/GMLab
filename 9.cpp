#include<GL/glut.h>
int a=0;
void init()
{	glClearColor(1,1,1,1);
}

void display()
{	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	
	gluPerspective(120,1,0.1,50);
	gluLookAt(0,0,1,0,0,0,0,1,0);
	glColor3f(0,0,0);
	glRotatef(a,1,0,0);
	glutSolidTeapot(0.1);
	
	glPopMatrix();
	glFlush();
}

void timer(int x)
{	a+=50;
	glutPostRedisplay();
	glutTimerFunc(1000,timer,0);
}
int main(int argc,char*argv[])
{	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(1000,1000);
	glutCreateWindow("a");
	glutDisplayFunc(display);
	timer(0);
	init();
	glutMainLoop();
	return 1;
}
