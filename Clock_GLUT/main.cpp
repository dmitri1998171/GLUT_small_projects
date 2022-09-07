
#include <iostream>
#include <stdio.h>
#include <ctime>
#include <GLUT/glut.h>

#define DEGREES_PER_MINUTE 6
#define DEGREES_PER_HOUR 30

using namespace std;

int timer_var = 1000;
struct tm *t_m;

void drawMinuteArrow() {
	glPushMatrix();
	glLoadIdentity();

	glRotatef(DEGREES_PER_MINUTE * t_m->tm_min, 0.0, 0.0, -1.0);
	glRectf(-0.025, 0.6, 0.025, 0.0);
	
	glPopMatrix();	
}

void drawNumbers() {
	glPushMatrix();

	glLoadIdentity();
	glColor3f(1.0, 1.0, 1.0);

	glRectf(0.025,0.75,-0.025,0.6);		// 12

	glRotatef(30.0,0.0,0.0,-1.0);
	glRectf(0.025,0.75,-0.025,0.6);		// 1
	glLoadIdentity();

	glRotatef(60.0,0.0,0.0,-1.0);
	glRectf(0.025,0.75,-0.025,0.6);		// 2
	glLoadIdentity();

	glRectf(-0.75,0.025,-0.6,-0.025);	// 3

	glRotatef(120.0,0.0,0.0,-1.0);
	glRectf(0.025,0.75,-0.025,0.6);		// 4
	glLoadIdentity();

	glRotatef(150.0,0.0,0.0,-1.0);
	glRectf(0.025,0.75,-0.025,0.6);		// 5
	glLoadIdentity();  

	glRectf(0.025,-0.75,-0.025,-0.6);	// 6

	glRotatef(210.0,0.0,0.0,-1.0);
	glRectf(0.025,0.75,-0.025,0.6);		// 7
	glLoadIdentity();

	glRotatef(240.0,0.0,0.0,-1.0);
	glRectf(0.025,0.75,-0.025,0.6);		// 8
	glLoadIdentity();

	glRectf(0.75,0.025,0.6,-0.025);		// 9

	glRotatef(-60.0,0.0,0.0,-1.0);
	glRectf(0.025,0.75,-0.025,0.6);		// 10
	glLoadIdentity();

	glRotatef(-30.0,0.0,0.0,-1.0);
	glRectf(0.025,0.75,-0.025,0.6);		// 11
	glLoadIdentity();

	glPopMatrix();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0, 0.0, 0.0);
	drawMinuteArrow();

	// Hour Arrow
	glColor3f(0.5, 0.5, 0.5);
	glRotatef(DEGREES_PER_HOUR * t_m->tm_hour, 0.0, 0.0, -1.0);
	glRectf(-0.025, 0.375, 0.025, 0.0);

	drawNumbers();
	glFlush();
}

void ProcessNormalKeys(unsigned char key, int x, int y) {
	if(key == 27) exit(0);
}

void About_a_time() {
	time_t t = time(NULL);
	t_m = localtime(&t);

	cout << "Local time is: " << t_m->tm_hour << ":" << t_m->tm_min << ":" << t_m->tm_sec << endl;
}

void Timer(int) {
	glutPostRedisplay();
	glutTimerFunc(timer_var, Timer, 0);
}

void Init() {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glutKeyboardFunc(ProcessNormalKeys); 
	glutTimerFunc(timer_var, Timer, 0);
	About_a_time();
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(400, 400);
	glutCreateWindow("Clock_GLUT");

	Init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
