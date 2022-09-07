
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <stdlib.h>

int W = 400;
int H = 550;

#define INT_GLUT_BITMAP_HELVETICA_10

void *font=GLUT_BITMAP_HELVETICA_10;



void mouseButton(int button, int state, int x, int y)
   {
	if(button==GLUT_LEFT_BUTTON)
		{
			if(state==GLUT_UP)
				{
					if(x<75 && x>25 && y<400 && y>350){ exit(0); }//1
					if(x<150 && x>100 && y<400 && y>350){ exit(0); }//2
					if(x<225 && x>175 && y<400 && y>350){ exit(0); }//3

					if(x<75 && x>25 && y<300 && y>250){ exit(0); }//4
					if(x<150 && x>100 && y<300 && y>250){ exit(0); }//5
					if(x<225 && x>175 && y<300 && y>250){ exit(0); }//6

					if(x<75 && x>25 && y<200 && y>150){ exit(0); }//7
					if(x<150 && x>100 && y<200 && y>150){ exit(0); }//8
					if(x<225 && x>175 && y<200 && y>150){ exit(0); }//9
					if(x<75 && x>25 && y<500 && y>450){ exit(0); }//0/
				}
		}
   }

void Buttons()
	{
////////////////////////////////////////////////
		glColor3f(0.5f, 0.0f, 0.0f);

		glBegin(GL_QUADS);//0
			glVertex2f(-0.875,-0.625);
			glVertex2f(-0.62,-0.625);
			glVertex2f(-0.62,-0.875);
			glVertex2f(-0.875,-0.875);
		glEnd();

		glBegin(GL_QUADS);//1
			glVertex2f(-0.875,-0.25);
			glVertex2f(-0.62,-0.25);
			glVertex2f(-0.62,-0.5);
			glVertex2f(-0.875,-0.5);
		glEnd();
		
		glBegin(GL_QUADS);//4
			glVertex2f(-0.875,0.125);
			glVertex2f(-0.62,0.125);
			glVertex2f(-0.62,-0.125);
			glVertex2f(-0.875,-0.125);
		glEnd();

		glBegin(GL_QUADS);//7
			glVertex2f(-0.875,0.25);
			glVertex2f(-0.62,0.25);
			glVertex2f(-0.62,0.5);
			glVertex2f(-0.875,0.5);
		glEnd();
////////////////////////////////////////////////
		glBegin(GL_QUADS);//2
			glVertex2f(-0.5,-0.25);
			glVertex2f(-0.25,-0.25);
			glVertex2f(-0.25,-0.5);
			glVertex2f(-0.5,-0.5);
		glEnd();

		glBegin(GL_QUADS);//5
			glVertex2f(-0.5,0.125);
			glVertex2f(-0.25,0.125);
			glVertex2f(-0.25,-0.125);
			glVertex2f(-0.5,-0.125);
		glEnd();

		glBegin(GL_QUADS);//8
			glVertex2f(-0.5,0.25);
			glVertex2f(-0.25,0.25);
			glVertex2f(-0.25,0.5);
			glVertex2f(-0.5,0.5);
		glEnd();
////////////////////////////////////////////////
		glBegin(GL_QUADS);//3
			glVertex2f(-0.125,-0.5);
			glVertex2f(-0.125,-0.25);
			glVertex2f(0.125,-0.25);
			glVertex2f(0.125,-0.5);
		glEnd();

		glBegin(GL_QUADS);//6
			glVertex2f(-0.125,-0.125);
			glVertex2f(-0.125,0.125);
			glVertex2f(0.125,0.125);
			glVertex2f(0.125,-0.125);
		glEnd();

		glBegin(GL_QUADS);//9
			glVertex2f(-0.125,0.25);
			glVertex2f(-0.125,0.5);
			glVertex2f(0.125,0.5);
			glVertex2f(0.125,0.25);
		glEnd();
////////////////////////////////////////////////
	}

void Line()
   {
	glColor3f(0.5,0.5,0.5);
 	glBegin(GL_QUADS);
	glVertex2f(-0.875,0.875);
	glVertex2f(-0.875,0.75);
	glVertex2f(0.875,0.75);
	glVertex2f(0.875,0.875);
	glEnd();
   }

renderBitmapString(int x, int y, void *font, char *string)
   {
	char *c;
	for(c=string; *C!='\0'; c++)
		{
		glutBitmapCharacter(font,*c);
   		}
   }

void display()
   {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glColor3f(1.0f, 0.0f, 0.0f);
        Buttons();
	Line();
	renderBitmapString(5,30,GLUT_BITMAP_HELVETICA_18,"HELLO WORLD");
	glFlush();
   }

void ProcessNormalKeys(unsigned char key, int x, int y)
	{
		if(key==27)
		exit(0);
	}


/*void ChangeSize(int w, int h)
   {
	if(h==0) h=1;
	float ratio=1.0*w/h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0,0,w,h);
	gluPerspective(45,ratio,1,1000);
	glMatrixMode(GL_MODELVIEW);
   }*/

void Init()
   {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glutKeyboardFunc(ProcessNormalKeys);
 	//glutReshapeFunc(ChangeSize);
	glutMouseFunc(mouseButton);	
   }

int main(int argc, char *argv[])
  {
     glutInit(&argc, argv);
     glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_SINGLE);
     glutInitWindowSize(W,H);
     glutCreateWindow("Graphical_calc");

     Init();
     glutDisplayFunc(display);
     glutMainLoop();
     return 0;
  }
