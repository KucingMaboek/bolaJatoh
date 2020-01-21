#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <GL/gl.h>
#include <stdlib.h>
#include <fstream>

bool arah;
float initPosBola[2][4] = { { 5, 70, 15, 80 }, { 25, 70, 35, 80 } }; //5,15 ; 25,35
float posBola[2][4] = { { 5,70,15,80 }, { 25,70,35,80 } };
float ukuranBola = (initPosBola[1][3]-initPosBola[1][1]) / 32;
int collisionRing1[4] = { 4,10,16,13 };	//x1,y1,x2,y2
int collisionRing2[4] = { 24,10,36,13 };	//x1,y1,x2,y2
int randSpawn;
int score;
int nyawa = 3;
char cetakScore[1000];
char cetakNyawa[1000];

void *font = GLUT_BITMAP_HELVETICA_12;
void *font2 = GLUT_BITMAP_TIMES_ROMAN_24;

//hapus const
void drawText(int x, int y, const char *string) {
	glRasterPos2f(x, y);
	int len = (int)strlen(string);
	for (int i = 0; i < len; i++) {
		glutBitmapCharacter(font2, string[i]);
	}
}

void bolaReset(int id) {
	if (posBola[id][1] <= -10)
	{
		randSpawn = rand() % 2;
		posBola[id][0] = initPosBola[randSpawn][0];
		posBola[id][1] = initPosBola[randSpawn][1];
		posBola[id][2] = initPosBola[randSpawn][2];
		posBola[id][3] = initPosBola[randSpawn][3];
		nyawa -= 1;
	}


	if (arah == false)
	{
		if (posBola[id][0] >= collisionRing1[0] && posBola[id][2] <= collisionRing1[2])
		{
			if (posBola[id][1] >= collisionRing1[1] && posBola[id][1] <= collisionRing1[3])
			{
				randSpawn = rand() % 2;
				posBola[id][0] = initPosBola[randSpawn][0];
				posBola[id][1] = initPosBola[randSpawn][1];
				posBola[id][2] = initPosBola[randSpawn][2];
				posBola[id][3] = initPosBola[randSpawn][3];
				score += 1;
			}
		}
	}
	if (arah == true)
	{
		if (posBola[id][0] >= collisionRing2[0] && posBola[id][2] <= collisionRing2[2])
		{
			if (posBola[id][1] >= collisionRing2[1] && posBola[id][1] <= collisionRing2[3])
			{
				randSpawn = rand() % 2;
				posBola[id][0] = initPosBola[randSpawn][0];
				posBola[id][1] = initPosBola[randSpawn][1];
				posBola[id][2] = initPosBola[randSpawn][2];
				posBola[id][3] = initPosBola[randSpawn][3];
				score += 1;
			}
		}
	}
}

void drawBola(int id) {
	bolaReset(id);
	//glPushMatrix(); //collision
	//glBegin(GL_POLYGON);
	//glColor4f(0, 0, 0, 0.5);
	//	glVertex2f(posBola[id][0], posBola[id][1]);
	//	glVertex2f(posBola[id][2], posBola[id][1]);
	//	glVertex2f(posBola[id][2], posBola[id][3]);
	//	glVertex2f(posBola[id][0], posBola[id][3]);
	//glEnd();
	//glPopMatrix();

	glPushMatrix();
	glTranslatef(posBola[id][0], posBola[id][1],0);
	glScalef(ukuranBola, ukuranBola, ukuranBola);
	// Background Hitam
	glColor3ub(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(1, 20);
	glVertex2f(0, 20);
	glVertex2f(0, 12);
	glVertex2f(1, 12);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(1, 23);
	glVertex2f(1, 9);
	glVertex2f(2, 9);
	glVertex2f(2, 23);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(2, 25);
	glVertex2f(2, 7);
	glVertex2f(3, 7);
	glVertex2f(3, 25);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(3, 26);
	glVertex2f(3, 6);
	glVertex2f(4, 6);
	glVertex2f(4, 26);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(4, 27);
	glVertex2f(4, 5);
	glVertex2f(5, 5);
	glVertex2f(5, 27);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(5, 28);
	glVertex2f(5, 4);
	glVertex2f(6, 4);
	glVertex2f(6, 28);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(6, 29);
	glVertex2f(6, 3);
	glVertex2f(7, 3);
	glVertex2f(7, 29);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(7, 30);
	glVertex2f(7, 2);
	glVertex2f(9, 2);
	glVertex2f(9, 30);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(9, 31);
	glVertex2f(9, 1);
	glVertex2f(12, 1);
	glVertex2f(12, 31);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(12, 32);
	glVertex2f(12, 0);
	glVertex2f(20, 0);
	glVertex2f(20, 32);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(20, 31);
	glVertex2f(20, 1);
	glVertex2f(23, 1);
	glVertex2f(23, 31);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(23, 30);
	glVertex2f(23, 2);
	glVertex2f(24, 2);
	glVertex2f(24, 30);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(24, 30);
	glVertex2f(24, 3);
	glVertex2f(25, 3);
	glVertex2f(25, 30);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(25, 29);
	glVertex2f(25, 3);
	glVertex2f(26, 3);
	glVertex2f(26, 29);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(26, 28);
	glVertex2f(26, 4);
	glVertex2f(27, 4);
	glVertex2f(27, 28);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(27, 27);
	glVertex2f(27, 5);
	glVertex2f(28, 5);
	glVertex2f(28, 27);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(28, 26);
	glVertex2f(28, 6);
	glVertex2f(29, 6);
	glVertex2f(29, 26);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(29, 24);
	glVertex2f(29, 7);
	glVertex2f(30, 7);
	glVertex2f(30, 24);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(30, 23);
	glVertex2f(30, 10);
	glVertex2f(31, 10);
	glVertex2f(31, 23);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(31, 20);
	glVertex2f(31, 12);
	glVertex2f(32, 12);
	glVertex2f(32, 20);
	glEnd();
	//Isi Putih
	glColor3ub(255, 255, 255);
	glBegin(GL_POLYGON);
	glVertex2f(10, 30);
	glVertex2f(10, 29);
	glVertex2f(11, 29);
	glVertex2f(11, 30);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(8, 29);
	glVertex2f(8, 28);
	glVertex2f(10, 28);
	glVertex2f(10, 29);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(7, 28);
	glVertex2f(7, 27);
	glVertex2f(8, 27);
	glVertex2f(8, 28);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(16, 31);
	glVertex2f(16, 30);
	glVertex2f(17, 30);
	glVertex2f(17, 31);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(21, 28);
	glVertex2f(21, 30);
	glVertex2f(13, 30);
	glVertex2f(13, 29);
	glVertex2f(12, 29);
	glVertex2f(12, 28);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(22, 26);
	glVertex2f(22, 28);
	glVertex2f(11, 28);
	glVertex2f(11, 24);
	glVertex2f(23, 24);
	glVertex2f(23, 26);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(16, 24);
	glVertex2f(16, 23);
	glVertex2f(21, 23);
	glVertex2f(21, 24);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(22, 29);
	glVertex2f(22, 28);
	glVertex2f(23, 28);
	glVertex2f(23, 29);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(25, 27);
	glVertex2f(25, 28);
	glVertex2f(23, 28);
	glVertex2f(23, 26);
	glVertex2f(26, 26);
	glVertex2f(26, 27);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(27, 25);
	glVertex2f(27, 26);
	glVertex2f(24, 26);
	glVertex2f(24, 24);
	glVertex2f(28, 24);
	glVertex2f(28, 25);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(25, 24);
	glVertex2f(25, 23);
	glVertex2f(28, 23);
	glVertex2f(28, 24);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(29, 23);
	glVertex2f(26, 23);
	glVertex2f(26, 22);
	glVertex2f(27, 22);
	glVertex2f(27, 21);
	glVertex2f(29, 21);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(3, 24);
	glVertex2f(3, 22);
	glVertex2f(4, 22);
	glVertex2f(4, 24);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(2, 22);
	glVertex2f(2, 20);
	glVertex2f(3, 20);
	glVertex2f(3, 22);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(2, 15);
	glVertex2f(2, 11);
	glVertex2f(3, 11);
	glVertex2f(3, 19);
	glVertex2f(2, 19);
	glVertex2f(2, 16);
	glVertex2f(1, 16);
	glVertex2f(1, 15);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(6, 19);
	glVertex2f(6, 20);
	glVertex2f(3, 20);
	glVertex2f(3, 9);
	glVertex2f(6, 9);
	glVertex2f(6, 8);
	glVertex2f(7, 8);
	glVertex2f(7, 19);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(8, 13);
	glVertex2f(8, 15);
	glVertex2f(7, 15);
	glVertex2f(7, 10);
	glVertex2f(8, 10);
	glVertex2f(8, 12);
	glVertex2f(9, 12);
	glVertex2f(9, 13);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(9, 15);
	glVertex2f(9, 13);
	glVertex2f(10, 13);
	glVertex2f(10, 22);
	glVertex2f(9, 22);
	glVertex2f(9, 21);
	glVertex2f(8, 21);
	glVertex2f(8, 15);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(15, 23);
	glVertex2f(10, 23);
	glVertex2f(10, 12);
	glVertex2f(12, 12);
	glVertex2f(12, 11);
	glVertex2f(15, 11);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(15, 22);
	glVertex2f(15, 12);
	glVertex2f(16, 12);
	glVertex2f(16, 13);
	glVertex2f(17, 13);
	glVertex2f(17, 22);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(18, 21);
	glVertex2f(18, 22);
	glVertex2f(17, 22);
	glVertex2f(17, 14);
	glVertex2f(18, 14);
	glVertex2f(18, 15);
	glVertex2f(19, 15);
	glVertex2f(19, 21);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(19, 18);
	glVertex2f(19, 16);
	glVertex2f(20, 16);
	glVertex2f(20, 18);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(4, 8);
	glVertex2f(4, 7);
	glVertex2f(6, 7);
	glVertex2f(6, 8);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(5, 7);
	glVertex2f(5, 6);
	glVertex2f(8, 6);
	glVertex2f(8, 7);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(6, 6);
	glVertex2f(6, 5);
	glVertex2f(9, 5);
	glVertex2f(9, 6);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(7, 5);
	glVertex2f(7, 4);
	glVertex2f(10, 4);
	glVertex2f(10, 5);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(8, 4);
	glVertex2f(8, 3);
	glVertex2f(11, 3);
	glVertex2f(11, 4);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(15, 4);
	glVertex2f(14, 4);
	glVertex2f(14, 1);
	glVertex2f(18, 1);
	glVertex2f(18, 5);
	glVertex2f(15, 5);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(12, 4);
	glVertex2f(12, 2);
	glVertex2f(21, 2);
	glVertex2f(21, 3);
	glVertex2f(22, 3);
	glVertex2f(22, 4);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(29, 10);
	glVertex2f(30, 10);
	glVertex2f(30, 20);
	glVertex2f(27, 20);
	glVertex2f(27, 10);
	glVertex2f(28, 10);
	glVertex2f(28, 9);
	glVertex2f(29, 9);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(26, 17);
	glVertex2f(26, 14);
	glVertex2f(31, 14);
	glVertex2f(31, 17);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(17, 12);
	glVertex2f(16, 12);
	glVertex2f(16, 7);
	glVertex2f(17, 7);
	glVertex2f(17, 6);
	glVertex2f(18, 6);
	glVertex2f(18, 13);
	glVertex2f(17, 13);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(19, 14);
	glVertex2f(18, 14);
	glVertex2f(18, 5);
	glVertex2f(24, 5);
	glVertex2f(24, 15);
	glVertex2f(19, 15);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(20, 16);
	glVertex2f(20, 15);
	glVertex2f(22, 15);
	glVertex2f(22, 16);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(24, 15);
	glVertex2f(24, 6);
	glVertex2f(25, 6);
	glVertex2f(25, 15);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(26, 10);
	glVertex2f(26, 14);
	glVertex2f(25, 14);
	glVertex2f(25, 7);
	glVertex2f(26, 7);
	glVertex2f(26, 8);
	glVertex2f(27, 8);
	glVertex2f(27, 10);
	glEnd();
	glPopMatrix();
	glutPostRedisplay();
}

void jaring() {
	glPushMatrix();
	glScalef(0.8, 1, 0);
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2f(3, 0);
	glVertex2f(0, 10);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(3, 0);
	glVertex2f(12, 0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(12, 0);
	glVertex2f(15, 10);
	glEnd();


	glBegin(GL_LINES);
	glVertex2f(2, 2);
	glVertex2f(13, 2);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(1.5, 4);
	glVertex2f(13.5, 4);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(1, 6);
	glVertex2f(14, 6);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(0.5, 8);
	glVertex2f(14.5, 8);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(0, 10);
	glVertex2f(15, 10);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(3, 0);
	glVertex2f(3, 10);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(6, 0);
	glVertex2f(6, 10);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(9, 0);
	glVertex2f(9, 10);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(12, 0);
	glVertex2f(12, 10);
	glEnd();
	glPopMatrix();
}

void ring() {
	glPushMatrix();

	if (arah == false)
	{
		glPushMatrix();
		glTranslatef(4, 4, 0);
		jaring();
		glPopMatrix();

		glPushMatrix();
		glScalef(1.7, 1.7, 0);
		glTranslatef(-4, 0, 0);
		glBegin(GL_POLYGON);//cagak ring
		glColor3f(0.5, 0, 0);
		glVertex2f(6, 8);
		glVertex2f(6, 9);
		glColor3f(0.7, 0, 0);
		glVertex2f(16, 9);
		glVertex2f(16, 8);
		glEnd();
		glPopMatrix();

	}
	if (arah == true)
	{
		glPushMatrix();
		glTranslatef(24, 4, 0);
		jaring();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(16.5, 0, 0);
		glScalef(1.7, 1.7, 0);
		glTranslatef(-4, 0, 0);
		glBegin(GL_POLYGON);//cagak ring
		glColor3f(0.5, 0, 0);
		glVertex2f(6, 8);
		glVertex2f(6, 9);
		glColor3f(0.7, 0, 0);
		glVertex2f(16, 9);
		glVertex2f(16, 8);
		glEnd();
		glPopMatrix();


	}

	glPushMatrix();
	glBegin(GL_POLYGON);//tiang
	glColor3f(0.5, 0.5, 0.5);
	glVertex2f(18.5, 0);
	glVertex2f(18.5, 20);
	glColor3f(0.7, 0.7, 0.7);
	glVertex2f(21.5, 20);
	glVertex2f(21.5, 0);
	glEnd();
	glPopMatrix();

	glPopMatrix();
}


void update(int value) {
	if (nyawa > 0)
	{

		posBola[0][1] -= 0.1;
		posBola[0][3] -= 0.1;
		posBola[1][1] -= 0.1;
		posBola[1][3] -= 0.1;
		if (GetAsyncKeyState(VK_RIGHT)) {
			arah = true;
		}
		if (GetAsyncKeyState(VK_LEFT)) {
			arah = false;
		}



	}
	glutPostRedisplay();
	glutTimerFunc(1, update, 0);
}

void displayMe(void) {
	glClearColor(1,1,1, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();
	glBegin(GL_POLYGON); //langit
	glColor3ub(199, 255, 242);
	glVertex2f(0, 10);
	glVertex2f(40, 10);
	glColor3f(0, 0.776, 0.929);
	glVertex2f(40, 70);
	glVertex2f(0, 70);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3f(0.063, 0.91, 0.176);
	glVertex2f(0, 0);
	glVertex2f(40, 0);
	glColor3ub(125, 191, 0);
	glVertex2f(40, 10);
	glVertex2f(0, 10);
	glEnd();
	glPopMatrix();

	drawBola(0);
	drawBola(1);
	//jaring();
	glPushMatrix();
	ring();
	glPopMatrix();

	glColor3f(0, 0, 0);
	sprintf_s(cetakScore, "%d", score);
	sprintf_s(cetakNyawa, "%d", nyawa);

	//codeblock error
	//sprintf(cetakScore, "%d", score);
	//sprintf(cetakNyawa, "%d", nyawa);

	drawText(1, 66, "Score: ");
	drawText(9, 66, cetakScore);
	drawText(1, 64, "Nyawa: ");
	drawText(9, 64, cetakNyawa);

	glFlush();
	glutSwapBuffers();
}


void myinit() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glClearColor(1.0, 1.0, 1.0, 1.0); //membersihkan windows
	glColor3f(0.0, 0.0, 0.0); //spesifikasi warna
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(400, 700);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Bola");
	gluOrtho2D(0, 40, 0, 70);
	glutDisplayFunc(displayMe);
	glutTimerFunc(0,update,0);
	myinit();
	glutMainLoop();
	return 0;
}
