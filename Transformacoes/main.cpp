#include <math.h>
#include <Windows.h>
#include <gl/glut.h>
#include<stdio.h>

void init()
{

	glClearColor(1.0f, 1.0f, 0.5f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-2.0, 2.0, -2.0, 2.0);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);

	//glLoadIdentity();
}

int sign = 1;
float sx = 0.1, sy = 0.1, sz = 0.1;
int angle = 5.0;
float rx = 1, ry = 1, rz = 1;
float tx = 0.2, ty = 0.0, tz = 0;
bool pause = true;
int ch = 1;
float escala =0.1;

//ROTACAO -> MATRIZ DE ROTACAO
void rotation()
{
	float R[16] = {float(cos(angle)),float(sin(angle)),0,0,-float(sin(angle)),float(cos(angle)),0,0,0,0,1.0,0,0,0,0,1.0};
	glMultMatrixf(R);
	
}
//ESCALA -> MATRIZ ESCALA
void scale(float s)
{
	float S[16] = {s*sx,0,0,0,0,s*sy,0,0,0,0,s*sz,0,0,0,0,1};
	glMultMatrixf(S);	
	glPopMatrix();
}

//TRANSLACAO -> MATRIZ DE MULTIPLICACAO
void translacao()
{
	float t[16] = { 1,0,0,0,0,1,0,0,0,0,1,0,sign*tx,ty,tz,1 };
	glMultMatrixf(t);
}
//REFLEXAO -> MATRIZ DE REFLEXAO
void reflection(float s)
{

	float S[16] = { -s*sx,0,0,0,0,-s*sy,0,0,0,0,-s*sz,0,0,0,0,1 };
	glMultMatrixf(S);
}

//CISALHAMENTO -> MATRIZ DE CISALHAMENTO
void shear()
{
	float s[16] = {};
	glMultMatrixf(s);
	
}

void disp()
{
	init();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);

	if (ch == 1) {
		glLoadIdentity();
		glPushMatrix();
		//glTranslatef(sign*tx,ty,tz);
		translacao();
		glRotatef(angle, 0, 1, 0);
		glBegin(GL_TRIANGLES);
		glColor3f(0, 0, 0);
		glVertex3f(-0.1, -0.4, 0);
		glColor3f(0.2, 0.2, 0.2);
		glVertex3f(-0.4, -0.7, 0);
		glColor3f(0.9, 0.9, 0.9);
		glVertex3f(0.2, -0.6, 0);
		glColor3f(0, 0, 0);
		glEnd();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(sign*tx, ty, tz);
		glRotatef(angle, 2, 3, 1);
		//glScalef(0.5,0.5,0.5);
		glScalef(sx, sy, sz);

		//glVertex2f(-0.1,0.0);
		//glVertex2f(0.0,0.1);
		//glVertex2f(0.1,0.0);
		glBegin(GL_TRIANGLES);
		glColor4f(1, 0, 0, 1);
		glVertex3f(1, 0, 0);
		glVertex3f(0, 1, 0);
		glVertex3f(0, 0, 1);

		glColor4f(0, 1, 0, 1);
		glVertex3f(0, 0, 1); glVertex3f(0, 0, 0); glVertex3f(0, 1, 0);

		glColor4f(0, 0, 1, 1);
		glVertex3f(0, 1, 0); glVertex3f(0, 0, 0); glVertex3f(1, 0, 0);

		glColor4f(1, 0, 1, 1);
		glVertex3f(1, 0, 0); glVertex3f(0, 0, 0); glVertex3f(0, 0, 1);
		glEnd();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(tx, 0.5, 0.0);
		glRotatef(angle, 0, 1, 1);
		glColor3f(0.3, 0.6, 0.4);
		glPopMatrix();
		/*
		glTranslatef(0.4,-0.8,0.0);
		glutSolidCube(0.5);
		*/
		glutSwapBuffers();

		//glFlush();
	}
	else if(ch == 2)
	{	
		glLoadIdentity();
		glPushMatrix();
		//glTranslatef(sign*tx,ty,tz);
		translacao();
		glRotatef(angle, 0, 1, 0);
		
		glBegin(GL_TRIANGLES);
		glColor3f(0, 0, 0);
		glVertex3f(-0.1, -0.4, 0);
		glColor3f(0.2, 0.2, 0.2);
		glVertex3f(-0.4, -0.7, 0);
		glColor3f(0.9, 0.9, 0.9);
		glVertex3f(0.2, -0.6, 0);
		glColor3f(0, 0, 0);
		glEnd();
		glPopMatrix();

		glPushMatrix();
		glRotatef(angle, 2, 3, 1);
		//glScalef(0.5,0.5,0.5);
		glScalef(sx, sy, sz);

		//glVertex2f(-0.1,0.0);
		//glVertex2f(0.0,0.1);
		//glVertex2f(0.1,0.0);
		glBegin(GL_TRIANGLES);
		glColor4f(1, 0, 0, 1);
		glVertex3f(1, 0, 0);
		glVertex3f(0, 1, 0);
		glVertex3f(0, 0, 1);

		glColor4f(0, 1, 0, 1);
		glVertex3f(0, 0, 1); glVertex3f(0, 0, 0); glVertex3f(0, 1, 0);

		glColor4f(0, 0, 1, 1);
		glVertex3f(0, 1, 0); glVertex3f(0, 0, 0); glVertex3f(1, 0, 0);

		glColor4f(1, 0, 1, 1);
		glVertex3f(1, 0, 0); glVertex3f(0, 0, 0); glVertex3f(0, 0, 1);
		glEnd();
		glPopMatrix();

	}else if(ch == 3)
	{
		glPushMatrix();
		glRotatef(angle, 0, 1, 0);
		glColor3f(0.2, 0.2, 0.2);
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		glutSolidCube(0.3);
		glPopMatrix();

		
		glPushMatrix();
		translacao();
		glColor3f(1.0, 1.2, 2.2);
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		glutSolidCube(0.3);
		glPopMatrix();
						
		glutSwapBuffers();
	}
}

void updateDireita()//int v)
{
	if (pause)
	{
		angle += 2.0;
		tx += 0.01;
		escala += 0.1;
		if (angle>360)
			angle -= 360;
		if (tx>0.9)
		{
			tx -= 1.9;
			escala -= 0.1;
			sign *= -1;
			sx += 0.1;
			sy += 0.1;
			sz += 0.1;
			if (sx>3)
				sx = sy = sz = 0;
		}
		//        if(angle%3==0)
		//        rx++;
		//        else
		//        if(angle%3==1)
		//            ry++;
		//        else
		//            rz++;
		//v++;
	}
	glutPostRedisplay();
	//if (v>5000000) return;				 // so that animation stop after some time, i.e. aftr 125000 seconds..
	//glutTimerFunc(25, update, v);
	return;
}

void updateEsquerda()//int v)
{
	if (pause)
	{
		angle += 2.0;
		tx -= 0.01;
		escala -= 0.1;
		if (angle>360)
			angle -= 360;
		if (tx<-0.9)
		{
			tx += 1.9;
			sign *= -1;
			escala -= 0.1;
			sx -= 0.1;
			sy -= 0.1;
			sz -= 0.1;
			if (sx<3)
				sx = sy = sz = 0;
		}
		//        if(angle%3==0)
		//        rx++;
		//        else
		//        if(angle%3==1)
		//            ry++;
		//        else
		//            rz++;
		//v++;
	}
	glutPostRedisplay();
	//if (v>5000000) return;				 // so that animation stop after some time, i.e. aftr 125000 seconds..
	//glutTimerFunc(25, update, v);
	//return;

}

/*
void mouseReset(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
	{

		tx = ty = tz = 0;
	}
	glutPostRedisplay();
}
*/

/*
void mouseUpdateDireita(int button, int state, int x, int y)
{
	if(button == GLUT_RIGHT_BUTTON)
	{
		updateDireita();
	}else if(button == GLUT_LEFT_BUTTON)
	{
		updateEsquerda();
	}
	glutPostOverlayRedisplay();
}
*/

void keys(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_END: 
			exit(0);
	case GLUT_KEY_PAGE_DOWN: 
			ch = 1;
			break;
	case GLUT_KEY_PAGE_UP: 
			ch = 3;
			break;
	case GLUT_KEY_DOWN: 
			tx = ty = tz = 0;
			glutPostRedisplay();
			break;
	case GLUT_KEY_RIGHT:
			updateDireita();			
			break;
	case GLUT_KEY_LEFT:
			updateEsquerda();			
			break;
	default: printf("\nComando nao especificado!!");
	}
	glutPostRedisplay();
}

int main(int argv, char **argc)
{
	glutInit(&argv, argc);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);
	glutInitWindowPosition(500, 0);
	glutInitWindowSize(500, 500);
	init();
	glutCreateWindow("TRANSFORMACOES");
	glutSpecialFunc(keys);
	glutDisplayFunc(disp);	
	glutMainLoop();
	return 0;
}
