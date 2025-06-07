#include <GL/freeglut.h>
#include <stdio.h>
#define _CRT_NO_SECURE_WARNINGS
#pragma warning(disable:4996)

int WIDTH = 400; int HEIGHT = 400;
int moveX = 0; int moveY = 0;

void Init() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.0, 2.0, -2.0, 2.0, 0.5, 5.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void DrawElement() {
	glColor3f(0.7, 0.7, 0.7);
	glBegin(GL_QUADS);
	glVertex3f(1.0, 0.0, 1.0);
	glVertex3f(1.0, 0.0, -1.0);
	glVertex3f(-1.0, 0.0, -1.0);
	glVertex3f(-1.0, 0.0, 1.0);
	glEnd();

	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(1.0, 0.0, 0.0);
	glVertex3f(-1.0, 0.0, 0.0);
	glEnd();

	glColor3f(1.0, 0.0, 0.0);
	glutSolidSphere(0.3, 20, 16);
	glPushMatrix();
	glColor3f(0.0, 0.0, 1.0);
	glTranslatef(0.5, 0.0, 0.3);
	glutSolidSphere(0.2, 10, 8);
	glPopMatrix();
}

void myDisplay() {
	glColor3f(1.0, 0.0, 0.0);
	glViewport(0, HEIGHT / 2, WIDTH/2, HEIGHT / 2);
	glPushMatrix();
	gluLookAt(0.0, 0.0, 1.0, 0.0, 0.0, -1.0, 0.0, 1.0, 0.0);
	DrawElement();
	glPopMatrix();

	glViewport(WIDTH/2, HEIGHT / 2, WIDTH/2, HEIGHT / 2);
	glPushMatrix();
	gluLookAt(0.0, 2.0, 0.0, 0.0, -1.0, 0.0, 0.0, 0.0, 1.0);
	DrawElement();
	glPopMatrix();

	glViewport(0, 0, WIDTH / 2, HEIGHT / 2);
	glPushMatrix();
	gluLookAt(0.0, 2.0, 0.0, 0.0, -1.0, 0.0, 1.0, 0.0, 0.0);
	DrawElement();
	glPopMatrix();

	glViewport(WIDTH / 2, 0, WIDTH / 2, HEIGHT / 2);
	glPushMatrix();
	gluLookAt(4.0, 0.0, 0.0, -1.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	DrawElement();
	glPopMatrix();

	glFlush();
}

void myKeyboard(unsigned char key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP:
		moveX++;
		glutPostRedisplay();
		break;
	case GLUT_KEY_DOWN:
		moveY++;
		glutPostRedisplay();
		break;
	case GLUT_KEY_LEFT:
		glutPostRedisplay();
		break;
	case GLUT_KEY_RIGHT:
		glutPostRedisplay();
		break;
	case 'w':
		glutPostRedisplay();
		break;
	case 'x':
		glutPostRedisplay();
		break;
	case 'q':
		glutPostRedisplay();
		break;
	case 'z':
		glutPostRedisplay();
		break;
	case 27:
		exit(0);
	}
}

void myReshape(int x, int y) {
	WIDTH = x; HEIGHT = y;
}


void main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Graphic Practice");
	Init();
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(myReshape);
	glutMainLoop();
	return;
}