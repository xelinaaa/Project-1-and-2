#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h> 

static float X = 0.0;
static float Y = 0.0;
static float Z = -15.0;


void kotakPutih() {

	//kotak putih
	glBegin(GL_LINES);
	glColor3f(1, 1, 1);

	glVertex3f(-2.0, 0.0, 0.0);
	glVertex3f(4.0, 0.0, 0.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1, 1, 1);

	glVertex3f(-2.0, 6.0, 0.0);
	glVertex3f(4.0, 6.0, 0.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1, 1, 1);

	glVertex3f(-2.0, 7.0, 0.0);
	glVertex3f(-2.0, -1.0, 0.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1, 1, 1);

	glVertex3f(4.0, -1.0, 0.0);
	glVertex3f(4.0, 7.0, 0.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1, 1, 1);

	glVertex3f(-2.0, 4.0, 0.0);
	glVertex3f(4.0, 4.0, 0.0);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1, 1, 1);

	glVertex3f(-2.0, 2.0, 0.0);
	glVertex3f(4.0, 2.0, 0.0);
	glEnd();
}

// Drawing routine.
void drawScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	//glColor3f(0.0, 0.0, 0.0);

	glLoadIdentity();

	glTranslatef(0.0, 0.0, -15.0);

	//kotak luar
	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.1, 0.1);

	glVertex3f(-4.0, -2.0, 0.0);
	glVertex3f(6.0, -2.0, 0.0);
	glVertex3f(6.0, 8.0, 0.0);
	glVertex3f(-4.0, 8.0, 0.0);
	glEnd();

	//kotak dalam
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.2, 0.2);

	glVertex3f(-3.0, -1.0, 0.0);
	glVertex3f(5.0, -1.0, 0.0);
	glVertex3f(5.0, 7.0, 0.0);
	glVertex3f(-3.0, 7.0, 0.0);
	glEnd();

	//fungsi membaut kotak putih
	kotakPutih();

	//kotak garis 3d
	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 1.0);

	glVertex3f(-4.0, -2.0, 0.0);
	glVertex3f(-3.0, -1.0, 0.0);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 1.0);

	glVertex3f(6.0, -2.0, 0.0);
	glVertex3f(5.0, -1.0, 0.0);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 1.0);

	glVertex3f(6.0, 8.0, 0.0);
	glVertex3f(5.0, 7.0, 0.0);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 1.0);

	glVertex3f(-4.0, 8.0, 0.0);
	glVertex3f(-3.0, 7.0, 0.0);
	glEnd();

	glFlush();
}



// Initialization routine.
void setup(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 100.0);

	glMatrixMode(GL_MODELVIEW);
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		exit(0);
		break;
	case 'a':
		X += 0.5;
		glutPostRedisplay();
		break;
	case 'd':
		X -= 0.5;
		glutPostRedisplay();
		break;
	case 's':
		Y -= 0.5;
		glutPostRedisplay();
		break;
	case 'w':
		Y += 0.5;
		glutPostRedisplay();
		break;
	case 'q':
		Z -= 0.5;
		glutPostRedisplay();
		break;
	case 'e':
		Z += 0.5;
		glutPostRedisplay();
		break;
	default:
		break;
	}
}

// Main routine.
int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitContextVersion(4, 3);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("box.cpp");

	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyInput);

	glewExperimental = GL_TRUE;
	glewInit();

	setup();

	glutMainLoop();
}
