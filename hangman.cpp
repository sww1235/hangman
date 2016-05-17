#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<glut.h>
#include <math.h>
using namespace std;
int r=6;
float pi=3.141592653589323846;
int w=0;
char letter; 
string word;
string guessword;
void hangman();
void secondary()
{
	cout<<"first player, enter a word for the second player to guess\n";
	cin>>word;
	system("cls");
	guessword=word;
	for(int i = 0; i < word.length(); i++)
	{
		guessword[i]='_';
	}

}
bool firstTime = true;
void display ()
{
	if(guessword!=word)
	{
		cout<<w<<"      "<<"Your wrong counter\n\n\n"<<endl;
		glClear (GL_COLOR_BUFFER_BIT);
		if(firstTime)
		{
			glutSwapBuffers();
			firstTime = false;
		}
		hangman();
		if(w>=1)
		{
			glBegin(GL_LINES);//platform
			glVertex3f(50,-40,0);
			glVertex3f(-50,-40,0);
			glEnd();
		}
		if(w>=2)
		{
			glBegin(GL_LINES);//post
			glVertex3f(40,40,0);
			glVertex3f(40,-40,0);
			glEnd();
		}
		if(w>=3)
		{
			glBegin(GL_LINES);//beam
			glVertex3f(40,40,0);
			glVertex3f(0,40,0);
			glEnd();
		}
		if(w>=4)
		{
			glBegin(GL_LINES);//rope
			glVertex3f(0,40,0);
			glVertex3f(0,30,0);
			glEnd();

		}
		if(w>=5)
		{
			glBegin(GL_LINE_LOOP);//head
			for(int y=0;y<360;y+=10)
				glVertex3f(r*cos(y*pi/180.),r*sin(y*pi/180.)+24,0);
			glEnd();
		}
		if(w>=6)
		{
			glBegin(GL_LINES);//body
			glVertex3f(0,18,0);
			glVertex3f(0,-10,0);
			glEnd();

		}
		if(w>=7)
		{
			glBegin(GL_LINES);//right arm
			glVertex3f(0,10,0);
			glVertex3f(-10,0,0);
			glEnd();

		}
		if(w>=8)
		{
			glBegin(GL_LINES);//left arm
			glVertex3f(0,10,0);
			glVertex3f(10,0,0);
			glEnd();

		}
		if(w>=9)
		{
			glBegin(GL_LINES);//right leg
			glVertex3f(0,-10,0);
			glVertex3f(-10,-20,0);
			glEnd();
		}
		if(w>=10)
		{
			glBegin(GL_LINES);//left leg+loose
			glVertex3f(0,-10,0);
			glVertex3f(10,-20,0);
			glEnd();
			glutSwapBuffers();
			system("cls");
			system("color 04");
			cout<<"\ntoo bad, you lost.\n\n";
			system("pause");
			exit(0);
		}
		glutSwapBuffers ();
		glutPostRedisplay();
	} 

	else if(guessword==word)

	{ 
		system("cls");
		system("color CA");
		cout<<"congratulations, you won.\n\n\n";
	system("pause");
	exit(0);
	}
}
void hangman()
{
	bool gotOne = false;
	cout<<"second player enter a letter\n";
	cin>>letter;
	for(int i = 0; i < word.length(); i++)
	{
		if(letter==word[i])//correct letter
		{		
			guessword[i]=letter;
			gotOne = true;
		}
	}
	if(!gotOne) ++w;
	cout<<guessword<<"\n\n"<<endl;
}

void init()
{
	glColor3f(1,1,1);
	glBegin(GL_LINES);
	glVertex3f(0,0,0);
	glVertex3f(0,0,0);
	glEnd();
	glColor3f(0,0,0);
	glFlush();
	glutSwapBuffers();
	glClear (GL_COLOR_BUFFER_BIT);
}

int main (int argc, char** argv)
{
	glutInit (&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (400, 400);
	glutInitWindowPosition (800, 100);
	glutCreateWindow ("your hangman.Don't let him swing");
	glOrtho(-100, 100, -100, 100, -1, 1);
	glClearColor (50, 20, 50, 0);
	glColor3f (0, 0, 0); 
	glutDisplayFunc(display);
	secondary();
	init();
	glutMainLoop();
	return 0;
}

